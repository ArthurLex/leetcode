#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
//返回最小字典序回文串

class Solution{
public:
    string getPakindrome(string inputStr)
    {
        int len =inputStr.size();
        if (len <= 2) {
            return inputStr;
        }

        int index = 0;
        int flag = 0;
        unordered_map<char, int> strMap;
        string ans(inputStr);

        for (auto it : inputStr) {
            if (strMap.find(it) == strMap.end()) {
                strMap[it] = 1;
            } else {
                strMap[it]++;
            }
        }

        for (auto pair : strMap) {
            int n = pair.second;
            int ch = pair.first;
            if (n % 2 == 1) {

            }
        }

        return result;
    }
}; 

int main(){
    Solution solu;
    string inputStr="caaec";
    string res = solu.getPakindrome(inputStr);
    cout << res << endl;


}
