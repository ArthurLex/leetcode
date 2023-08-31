#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <initializer_list>
#include <forward_list>
#include <optional>
#include <bitset>
#include <variant>
#include <atomic>
using namespace std;

class Student
{
public:
Student(const char *name, int age, float score);
void show();

private:

const char *m_name;
int m_age;
float m_score;
};

Student::Student(const char * name, int age, float score)
{
    m_name = name;
    m_age = age;
    m_score = score;
}
void Student::show()
{

    cout<<m_name<<" is "<<m_age<<" years old, score is "<<m_score<<endl;
}


int test_class()
{
    string name("MichaelHsu");

    Student stu(name.c_str(), 15, 92.5);
    stu.show();
    Student *ptu = new Student((char*)"LiHua", 16, 96);
    ptu->show();

    return 0;
}


float AddF(float a, float b)
{
    return (a + b);
}

double AddD(double a, double b)
{
    return (a + b); 
}

int AddI(int a, int b)
{
    return (a + b); 
}


void showMap()
{
    map<int, string> mapStudent;
    mapStudent.insert(pair<int, string>(000, "student_zero"));
    mapStudent.insert(map<int, string>::value_type(001, "student_one"));
    mapStudent[123] = "student_first";
    mapStudent[456] = "student_second";

    map<int,string>::iterator iter;  //迭代器遍历
    for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++) {
        cout<<iter->first<<" "<<iter->second<<endl;
    }
    return;
}

void VarTest()
{
    std::vector<int> v = {1, 2, 3};
    v[3] = 4;
    std::vector<int> v2 = {11, 22, 33};

    std::string singleStr = "this is string";
    std::map<int, int> intMap = {{1, 11}, {2, 22}};
    intMap[3] = 3;
    std::map<int, std::string> intStrMap = {{1, "one"}, {2, "two"}};
    intStrMap[3] = "three";
    std::map<std::string, std::string> strMap = {{"1", "one"}, {"2", "two"}};
    string singleStr2 = "this is string";
    map<int, string> intMap2 = {{1, "one"}, {2, "two"}};
    map<string, string> strMap2 = {{"1", "one"}, {"2", "two"}};

    std::set<int> se = {3, 4, 5};  /////////// no effect
    std::multiset<int> mSet = {4, 4, 5};  /////////// no effect
    std::list<int> li = {7, 8, 9};          // llvm15 no effect
    std::queue<int> q;  /////////// no effect
    q.push(11);
    q.push(12);
    std::deque<int> dq = {7, 8, 9}; /////////// no effect
    dq.push_back(13);
    dq.push_back(14);

    std::vector<int> vecArray[2] = {{1, 2, 3}, {4, 5, 6}};
    std::map<int, std::string> mapArray[2];
    mapArray[0].insert({1, "one"});
    mapArray[0].insert({2, "two"});
    mapArray[1].insert({3, "I"});
    mapArray[1].insert({4, "II"});
    std::forward_list<int> forwardList = {11, 22, 33};    /////////// no effect
    //std::optional<double> optionalDouble = 2.0;   // only available from C++17 onwards
    std::bitset<8> b(12);  // 00001100
    //std::variant<Another, Empty> variantObj = another2; // only available from C++17 onwards
std::atomic<int> atomicInt(7);

std::unordered_set<int> unSet = {3, 4, 5};    // llvm15 no effect

std::unordered_map<int, int> unMap = {{1, 100}, {2, 200}}; //llvm15 no effect

string sss = "qweqwe";
cout << sss << endl;
}

double mix(double x,double y){
return x*y;
}

void nullPtr()
{
char* a[3] = {NULL};

char tmp = 'c';

char* b[2] = {&tmp, &tmp};

int int_a = 2;

int *aptr[2] = {};

char* a_nullptr[3] = {nullptr};

char* p = nullptr;

char* p_null = NULL;

int int_n[2] = {};
int int_x[] = {1, 2};

int int_y[2] = {1};

cout<<int_a<<endl;

if (p == nullptr){
cout<<"p is nullptr"<<endl;
}

for (int i = 0; i < 2; i++)
{
cout<<int_y[i]<<endl;
}

for (int j = 0; j < sizeof(int_y)/sizeof(int); j++)
{
cout<<int_x[j]<<endl;
}

return;
}

void stringFunc()
{
string str("test string");
int length = str.length();

cout<<"str is "<<str.c_str()<<endl;
cout<<"length = "<<length<<endl;

map<int, string> mapTemp;
mapTemp.insert({5, "XiaoMing"});
mapTemp.insert({4, "XiaoHua"});
mapTemp.insert({3, "Xiaoqiang"});

map<int, string>::iterator it;
for (it = mapTemp.begin(); it != mapTemp.end(); it++)
{
cout<<"StudentID: "<<(*it).first<<" Name: "<<(*it).second.c_str()<<endl;
}

return;
}

void double_test()
{
double double_var=16.0;
double double_max=32.0;

double mul=mix(double_var,double_max);
cout << mul << endl;
return;
}

int main()
{
float i = 0.0, totolF = 15.0;
double j = 0.0, totolD =10.0;
int k = 9, totolI=5;

cout<<"Input a int num:"<<endl;
cin>>k;
totolF = AddF(totolF,i);
totolD = AddD(j, totolD);
totolI = AddI(k, totolI);

test_class();
showMap();
VarTest();
nullPtr();
double_test();
stringFunc();

return 0;
}