#include <memory>
#include <chrono>
#include <thread>
#include <iostream>
#include <functional>


class BaseClass {
public:

    BaseClass() : x(1) {
        dummy = std::make_shared<SomeClass>();
    }

    virtual ~BaseClass() {
        dummy.reset();
    }

    void do_func() {
        while(dummy) {
            std::cout << "doing stuff " << dummy->do_stuff(x) << std::endl;
            x++;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
private:
    int x;
    class SomeClass {
    public:
        int do_stuff(int x) {
            return x * x;
        }
    }; 
    std::shared_ptr<SomeClass> dummy;
};

class DerivedClass : public BaseClass {

};

int main() {
    auto obj = std::make_unique<DerivedClass>();
    std::thread t(&BaseClass::do_func, obj.get());
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "reset called!" << std::endl;
    obj.reset();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "going out of scope" << std::endl;
    t.join();
    return 0;
}