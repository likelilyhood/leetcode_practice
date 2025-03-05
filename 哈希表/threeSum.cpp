#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        //固定第一个元素
        for(int i=0;i<nums.size();i++){
            if (nums[i]>0)return res;
            int left=i+1;
            int right=nums.size()-1;
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            while(left<right){
                if(nums[i]+nums[left]+nums[right]>0)right--;
                else if(nums[i]+nums[left]+nums[right]<0)left++;
                else{
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;

                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                
                }
            }
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = s.threeSum(nums);
    for (const auto& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}