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


int main(){
    string s;
    
    Demo d;
    const auto startTime = std::chrono::steady_clock::now();
    int m=d.Find(1);
    //Sleep(2);
    const auto curTime = std::chrono::steady_clock::now();
    auto inter = curTime - startTime;
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(inter).count();
    std::cout<<"pass costed time    "<<time<<"  ms";
    while(cin>>s){
        stack<char> st;
        for(auto c:s){
            if(c!='$'){
                st.push(c);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        cout<<st.size()<<endl;
    }
}