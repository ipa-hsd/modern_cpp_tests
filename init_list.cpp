#include <iostream>

using namespace std;

void func(int i)
{
    cout << "int " << i << endl;
}

int main(int argc, char const *argv[])
{
    int i;
    func(i = 9);
    cout << "int " << i << endl;
    return 0;
}
