#include <bits/stdc++.h>
#include <chrono>
#include <Windows.h>
using namespace std;

class Demo{
public:
    int Find(int a) {
        int sum=0;
        for(int i=0;i<100000000;i++){
        }
        return sum;
    }
};

 std::string GetShortName(const std::string& methodName) 
{
    std::string KeyStr = "@";
    if (methodName.find(KeyStr)!=std::string::npos){
        std::string::size_type index = methodName.find(KeyStr);
        std::string extracted = methodName.substr(0, index);
        return extracted;
    }else{
        return methodName;
    }
}

int main(){
    string s = "dasdadad@asdad"; 
    string s1 = "dasda";
    std::cin >> s1;
    std::cout << "s after output:" << GetShortName(s) << endl;
    std::cout << "s1 after output:" << GetShortName(s1);

}