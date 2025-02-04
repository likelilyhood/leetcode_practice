
/*class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int middle=n/2;
        if(nums[middle]==target)return middle ;
        else if(nums[middle]>target) search(middle=middle+(n-middle)/2);
        else search(middle/=2);
    }
};//原有代码问题在于1.n 和middle  无法进行有效迭代，另外，终止递归条件缺少*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }

private:
    int binarySearch(vector<int>& nums, int target, int left, int right) {
        if (left > right) {
            return -1; // 搜索范围为空，返回-1
        }

        int middle = left + (right - left) / 2;

        if (nums[middle] == target) {
            return middle; // 找到目标值，返回索引
        } else if (nums[middle] > target) {
            return binarySearch(nums, target, left, middle - 1); // 目标值在左半部分
        } else {
            return binarySearch(nums, target, middle + 1, right); // 目标值在右半部分
        }
    }
};
