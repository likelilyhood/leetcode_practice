#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


class Solution {
    public:
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4){
    unordered_map<int,int> record;
    //统计两个数组中元素之和的所有可能
    for (int a:nums1){
        for(int b:nums2){
            record[a+b]++;
        }
    }
    int res=0;
    //在另外两个数组中找到和的相反数
    for(int c:nums3){
        for(int d:nums4){
            if(record.find(-c-d)!=record.end()){
                res+=record[-c-d];//找到了就加上
            }
        }
    }
    return res;
}};
int main(){
    Solution s;
    vector<int> nums1={1,2};
    vector<int> nums2={-2,-1};
    vector<int> nums3={-1,2};
    vector<int> nums4={0,2};
    cout<<s.fourSumCount(nums1,nums2,nums3,nums4)<<endl;
    return 0;
}