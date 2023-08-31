#include<iostream>


struct Foo {
    Foo(const std::string &s): command(s)  {}//command构造函数初始化列表，给成员变量赋值s
    virtual ~Foo() {}

    void fooStuff() {
        std::cout << "I am in " << __FUNCTION__ << "\n";
        std::cout << "And I would execute: " << command << "\n";
    }

    std::string command;
};

