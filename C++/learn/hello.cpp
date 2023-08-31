#include <iostream>
#include <map>
using namespace std;

class Test {
    public:
    void test() {
        std::cout << "h" << std::endl;
    }
};




int main() {
    // Test a;
    // const Test* t = &a;
    // t->test();
    // std::cout << "out" << std::endl;
    map<double, int> PassTimeMap;
      if (timePassMap_.count(name) == 0) {
        timePassMap_.insert(std::make_pair(name, time));
    } else {
        timePassMap_.insert(std::make_pair(name, time + timePassMap_.at(name)));
    }
    PassTimeMap.insert(make_pair(1, 1));
    PassTimeMap.insert(make_pair(1, 5));
    map<double,int> :: iterator it;
    for(it=PassTimeMap.begin(); it!=PassTimeMap.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}


