#ifndef _MYOBJ_DEFINED
#define _MYOBJ_DEFINED
#include <string>
#include <iostream>
class MyObj {
public:
    MyObj(std::string name):_name(name) {
    }
    ~MyObj() {
        std::cout << "Goodbye World " << std::endl;
    }
    void speak() {
        std::cout << "Hello World from " << _name << std::endl;
    }
private:
    std::string _name;
};
#endif // _MYOBJ_DEFINED
