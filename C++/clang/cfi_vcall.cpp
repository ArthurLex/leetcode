#include <iostream>

struct Base {
    Base() {}
    virtual ~Base() {}  //析构函数
    virtual void printMe() { 
        std::cout << "Base::printMe\n";
    }
};

struct Derived : Base {
    Derived() {}
    virtual ~Derived() {}

    virtual void printMe() {
        std::cout << "Derived::printMe\n";
    }
};

// imagine this is an attacker-created structure 
// in memory
struct Evil {
    Evil() {}
    virtual ~Evil() {}

    virtual void makeAdmin() {
        std::cout << "CFI Prevents this control flow\n";
        std::cout << "Evil::makeAdmin\n";
    }
};

int main(int argc, const char *argv[]) {

    Evil *eptr = new Evil();
    Derived* dptr = new Derived();

    (void)(argc);  //占位符，避免编译问题warning
    (void)(argv);

    dptr->printMe();
    
    // imagine a type confusion vulnerability
    // that does something similar
    dptr = reinterpret_cast<Derived*>(eptr);  //强制类型转换，将eptr转换成Derived*类型指针
    dptr->printMe();

    return 0;
    //虚拟调用期间出错，Evil指针调用Derived成员函数
}
