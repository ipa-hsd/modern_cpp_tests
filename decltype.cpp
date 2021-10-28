#include <iostream>
#include <utility>
#include <sstream>

using namespace std;

template <typename T>
T from_string(const std::string &data)
{
    if (!data.empty())
    {
        T ret;
        std::istringstream iss(data);
        iss >> std::dec >> ret;
        if (iss.fail())
        {
            std::cerr << "conversion of data from string failed" << std::endl;
            return T();
        }
        return ret;
    }
    return T();
}

class Dummy
{
public:
    int get() { return 10; }
};

class Dummy2
{
public:
    float get() { return 2.5; }
};

template <typename T>
auto get_it(T t) -> decltype(std::declval<T>().get())
{
    return t.get();
}

int main(int argc, char const *argv[])
{
    string _int = "10";
    cout << from_string<float>(_int) << endl;

    Dummy d1;
    Dummy2 d2;

    std::cout << get_it(d1) << std::endl;
    std::cout << get_it(d2) << std::endl;
    return 0;
}
