#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
    int Find(const vector <int>& packs,const vector<int>& goods) {
        int sum=0;
        sort(packs.begin(),packs.end()) ;//
        return sum;
    }
};
    inline int ReadInt(){
        int num;
        std::cin>>num;
        return num;
    }
    inline std::vector<int> ReadVector(int size){
        std::vector<int> nums(size);
        for(int i=0;i<size;++i){
            std::cin>>nums[i];
        }
        return nums;
    }
    int main(){
        int packsCount=ReadInt();
        vector<int> packs=ReadVector(packsCount);
        int goodsCount=ReadInt();
        vector<int> goods=ReadVector(goodsCount);

        Solution sl;
        std::cout<<sl.Find(packs,goods);

        return 0;
    }

// 3
//4 1 3
//4
//3 2 50 3
//--out 6