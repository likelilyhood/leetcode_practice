#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());//先将整个数组按照大小排布，便于后续去重剪枝
        for (int k=0; k<nums.size();k++){
            if(nums[k]>target&&nums[k]>0)break;//第一次判断，如果最小的两个数和依旧大于target，必然舍弃
            if(k>0&&nums[k]==nums[k-1])continue;//跳过相同的数字
            for(int i=k+1;i<nums.size();i++){
                if(nums[k]+nums[i]>target&&nums[k]+nums[i]>0)break;//第二次判断
                if(i>k+1&&nums[i]==nums[i-1])continue;
                int left=i+1;//左指针
                int right=nums.size()-1;//右指针
                while(left<right){
                    if((long)nums[k]+nums[i]+nums[right]+nums[left]>target)right--;
                    else if((long)nums[k]+nums[i]+nums[right]+nums[left]<target)left++;
                    else{
                        result.push_back(vector<int>{nums[k],nums[i],nums[left],nums[right]});//获得正确解，将这个推入答案数组
                        while(left<right&&nums[right]==nums[right-1])right--;//依旧跳过重复解
                        while(left<right&&nums[left]==nums[left+1])left++;

                        right--;//更新左右指针
                        left++;

                    }


                }
            }
        }
        return result;
    }
};
int main (){
    vector<int> nums={1,0,-1,0,-2,2};
    Solution s;
    vector<vector<int>> result=s.fourSum(nums,0);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}