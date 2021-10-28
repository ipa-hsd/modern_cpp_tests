#include <iostream>
#include <vector>

class MyClass
{
private:
    // disable copying
    // MyClass(const MyClass &);
    // MyClass &operator=(const MyClass &);

public:
    int x;
    MyClass() : x(10) {}
    // move constructor
    MyClass(MyClass &other)
    {
        std::cout << "copy constructor" << std::endl;
    }

    MyClass(MyClass &&other)
    {
        std::cout << "move constructor" << std::endl;
    }

    // move assignment operator
    MyClass &operator=(MyClass &other)
    {
        std::cout << "copy constructor = " << std::endl;
    }

    ~MyClass()
    {
        std::cout << "destructor" << std::endl;
    }
};

void func(MyClass &&a)
{
    std::cout << "func called " << &a << std::endl;
    a.x = 14;
}

int main(int argc, char const *argv[])
{
    // MyClass a;
    // std::cout << "a init " << &a << " " << a.x << std::endl;
    // //MyClass b = a;
    // MyClass b(std::move(a));

    // //delete &a;
    // std::cout << &b << " " << &a << " " << b.x << " " << sizeof(a) << " " << sizeof(b) << std::endl;
    // //func(b);

    std::vector<int> a = {1, 2, 3, 4, 5};
    auto b = std::move(a);

    std::cout << "a: " << a.size() << std::endl;
    std::cout << "b: " << b.size() << std::endl;

    int x = 6;
    int &&y = std::move(x);
    std::cout << y << " " << x << std::endl;

    return 0;
}
