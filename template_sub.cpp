#include <iostream>

struct A
{
};

template <typename T>
class Foo
{
public:
  Foo(int i) {}
  void something(T i)
  {
      t = i;
    std::cout << "printing A: " << t.val << std::endl;
  }

private:
  T t;
};

struct B : public A
{
  B() : val(1) {}
  int val;
};

template <typename T>
class Bar : public Foo<T>
{
public:
  Bar(int i) : Foo<T>(i) {}

private:
  B b;
};

int main(int argc, char *argv[])
{
  Bar<B> bar(10);
  bar.something();
  return 0;
}
