#include <iostream>
#include <utility>
#include <sstream>
#include <vector>
#include <iterator>

class KV : public std::pair<std::string, std::string>
{
    template <typename T>
    static std::string make_list(bool first, const T &t)
    {
        std::stringstream s;
        if (!first)
            s << ";";
        s << t;
        return s.str();
    }

    template <typename T, typename... Ts>
    static std::string make_list(bool first, const T &t, Ts &&... list)
    {
        std::stringstream s;
        s << make_list(first, t);
        s << make_list(false, list...);
        return s.str();
    }

    static std::string make_list(bool first, std::vector<std::string> list)
    {
        std::stringstream s;
        std::copy(list.begin(), list.end() - 1, std::ostream_iterator<std::string>(s, ";"));
        s << list.back();
    }

public:
    template <typename... Ts>
    KV(const std::string &k, const Ts &... list) : std::pair<std::string, std::string>(k, make_list(true, list...)) {}
};

class Resource
{
    using param_type = std::pair<std::string, std::string>;

    static std::string join(const std::initializer_list<param_type> &list)
    {
        std::stringstream s;
        for (const auto &p : list)
        {
            s << p.first << "=" << p.second;
        }
        return s.str();
    }
    const std::string uri;

public:
    Resource(const std::string &method, const std::initializer_list<param_type> &list) : uri(method + join(list)) {}

    void get()
    {
        std::cout << uri << std::endl;
    }
};

template <typename... Ts>
void dummy2(const Ts &... list)
{
    // for (auto item : list...)
    // {
    //     std::cout << item << "; " std::endl;
    // }
    // std::cout << " the END" << std::endl;
}

template <typename... Ts>
void dummy(const Ts &... list)
{
    dummy2(std::forward(list)...);
}

std::vector<std::string> dummy()
{
    std::vector<std::string> list;
    list.push_back("harsh");
    list.push_back("hello");
    list.push_back("world");
    return list;
}

std::string blub()
{
    return std::string();
}

int main()
{
    Resource r("command", {{"a", "b"}, KV{"answer", 42.0}, KV{"list5", "A", 3, 2}});
    r.get();

    dummy("foo", 1);

    return 0;
}
