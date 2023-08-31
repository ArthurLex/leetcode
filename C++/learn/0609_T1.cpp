#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution{
public:
    int GetUniqueNum(vector<int>& arrs)
    {
        unordered_map<int, int> umap;
        int sum = 0;
        for (auto i : arrs){
            umap[i]++;
        }
        for (auto j : umap) {
            if(j.second == 1){
                sum += j.first;
            }

        }
        return sum;
    }
};

int main(){
    Solution solu;
    vector<int> vec = {35, 57, 35, 20, 30};
    int res = solu.GetUniqueNum(vec);
    cout << res << endl;


}