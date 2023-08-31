#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include<stack>
#include<queue>
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
//非递减排序整数数组，返回数的平方，非递减排序。
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      int k=nums.size()-1;
      vector <int > result(nums.size(),0);
      for(int i=0,j=nums.size()-1;i<=j;){
          if(nums[i]*nums[i]<nums[j]*nums[j]){
              result[k--]=nums[j]*nums[j];
              j--;
          }
          else{
              result[k--]=nums[i]*nums[i];
              i++;
          }
      }
      return result;
    }
    //快速排序
    void QuickSort(vector<int>& arr, int start, int end){
        if(start >= end) return;
        //int index = rand()%(end-start+1) + start; // 随机产生一个下标
       // int pivot = arr[index];   // 把它作为哨兵
       int pivot = arr[start];   // 把它作为哨兵
      //  swap(arr[start], arr[index]); // 注意：先把它放在最前面
        int i=start, j=end;
        while(i<j){
            // 注意：先移动右边j，这样while结束后i处是比pivot小的数字，才可以与pivot交换
            while(i<j && arr[j]>=pivot) // 注意：大于等于的放右边
                j--;
            while(i<j && arr[i]<=pivot) // 小于等于的放左边
                i++;
            if(i!=j) // 最多i==j
                swap(arr[i], arr[j]);
        }
        swap(arr[start], arr[i]); // 再把start处的pivot放在中间
        QuickSort(arr, start, i-1);
        QuickSort(arr, i+1, end); // 注意：i已经排过序
        return ;
    }
    //二分查找
    int search(vector<int>& nums, int target) {
            int left=0,right=nums.size()-1;
        while(left<=right){
          int  mid=(left+right)/2;
             if(nums[mid]>target){
                right=mid-1; 
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            else return mid;
        }
        return -1;
    }
    int lengthOfLongestSubstring(string s) {//最长不重复子串
        if(s.size() == 0) return 0;
        unordered_set<char> lookup;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            while (lookup.find(s[i]) != lookup.end()){
                lookup.erase(s[left]);
                left ++;
            }
            maxStr = max(maxStr,i-left+1);
            lookup.insert(s[i]);
    }
        return maxStr;
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
  
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking (vector<int>& nums, vector<bool>& used) {//字符串的排列
        // 此时说明找到了一组
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // used[i - 1] == true，说明同一树支nums[i - 1]使用过
            // used[i - 1] == false，说明同一树层nums[i - 1]使用过
            // 如果同一树层nums[i - 1]使用过则直接跳过
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {//字符串的排列
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end()); // 排序
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }


//寻找数组的中心下标
public:
    int pivotIndex(vector<int>& nums) {
        int sumLeft = 0, sumRight = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); i++) {
            sumRight -= nums[i];
            // 若左侧元素和等于右侧元素和，返回中心下标 i
            if (sumLeft == sumRight)
                return i;
            sumLeft += nums[i];
        }
        return -1;
    }
    //同构字符串
    bool isIsomorphic(string s, string t) {
        unordered_map <char,char> t2s, s2t;
        for(int i=0;i<s.size();i++){
            char a=s[i],b=t[i];
            if(s2t.find(a)!=s2t.end()&&s2t[a]!=b||t2s.find(b)!=t2s.end()&&t2s[b]!=a)
            //s2t.find(a)!=s2t.end()含义就是遍历到最后一个元素为止
            return false;
            s2t[a]=b;
            t2s[b]=a;
        }
        return true;
    }
  //合并两有序链表-递归
  //判断 l1 和 l2 头结点哪个更小，然后较小结点的 next 指针指向其余结点的合并结果。
  public:
    ListNode *mergeTwoList(ListNode *l1,ListNode *l2){
        if(l1==NULL)
        return l2;
        if(l2==NULL)
        return l1;
    if(l1->val<=l2->val){
        l1->next=mergeTwoList(l1->next,l2);
        return l1;
    }
    l2->next=mergeTwoList(l2->next,l1);
    return l2;
    }
    //反转链表
    public :
    ListNode * reverseList(ListNode * head){
        ListNode * pre=nullptr;
        ListNode * cur=head;
        while ( cur!=NULL){
            ListNode* tem=cur->next;//tem=cur.next
            cur->next=pre;
            pre=cur;
            cur=tem;

        }
        return pre;
        
    }
    //返回链表的中间节点
    public:
    ListNode* midNode(ListNode * head){
        ListNode* slow=head;
        ListNode* fast=head;
        while (fast!=NULL&&fast->next!=NULL){ //&&且
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
      
    }
    //链表有环
   ListNode *detectCycle(ListNode *head) {//set法
        unordered_set <ListNode*> set;
        while(head!=NULL){
            if(set.count(head)){
                return head;
            }
            set.insert(head);
            head=head->next;
        }
        return NULL;
    }
//买卖股票的最佳时机
    int maxProfit(vector<int>& prices) {
       int minRrice=INT_MAX;
       int maxProfit=0;
       for(int price:prices){
           minRrice=min(minRrice,price);
           maxProfit=max(maxProfit,price-minRrice);
       }
        return maxProfit;
    }
    //通过给定字符串中字母可以构成的最长回文字符串长度
int longestPalindrome(string s){
    unordered_map<char,int> counter;
    for(char ch:s)
    counter[ch]++;
    int res=0,odd=0;
    for(auto kv:counter){
        int count=kv.second;
        int rem=count%2;
        res+=count-rem;
        if(rem==1){
            odd=1;
        }
    }
    return res+odd;
}
//N叉树的前序遍历
vector <int> preorder(Node *root){
    vector<int> res;
    if(root==NULL){
        return res;
    }
    stack<Node*> sta;
    sta.emplace(root);
    while(!sta.empty()){
        Node* node=sta.top();
        sta.pop();
        res.emplace_back(node->val);
        for(auto it=node->children.rbegin();it!=node->children.rend();it++){
            sta.emplace(*it);
        }
    }
    return res;

}
//二叉树的层序遍历
vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> res;
    queue<TreeNode*> que;
    if(root!=NULL)
    que.push(root);
    while(!que.empty()){
        int len=que.size();
        vector<int> level;
        for(int i=0;i<len;i++){
            TreeNode * node=que.front();
            que.pop();
            level.push_back(node->val);
            if(node->left!=NULL)
            que.push(node->left);
            if(node->right!=NULL)
            que.push(node->right);
        }
        res.push_back(level);
    }
    return res;
}
int main() {
    int a[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int arr[]={1,4,6,8,9,10,88};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    Solution solution;
    //cout << solution.minCostClimbingStairs(cost) << endl;
    cout<<solution.search(nums,8)<<endl;
}
};