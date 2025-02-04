#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return insertsearch(nums,0,nums.size()-1,target);
    }
private:
    int insertsearch(vector<int>& nums,int left ,int right,int target){
        int mid=left+(right-left)/2;
        if (nums[mid]==target)return mid;
        else if (nums[mid]>target){
            right=mid;
            insertsearch( nums, left, right, target);
        }else {
            left=mid;
            insertsearch(nums,left,right,target);
        }
        return mid+1;
    }
};
//第一次代码在进行递归时始终没有添加约束条件来中止
//下面是修改
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return insertsearch( nums,0,nums.size()-1,target);
    }
private:
    int insertsearch(vector<int>& nums,int left ,int right,int target){
        if (left>right)return left;
        int mid=left+(right-left)/2;
        if (nums[mid]==target)return mid;
        else if (nums[mid]>target){
            right=mid-1;
            return insertsearch( nums, left, right, target);
        }else {
            left=mid+1;
            return insertsearch(nums,left,right,target);
        }
        
    }
};