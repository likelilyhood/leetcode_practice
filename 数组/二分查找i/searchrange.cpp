#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int mid = rangesearch(nums, 0, nums.size() - 1, target);
        return findrange(nums, mid, target);
    }

private:
    int rangesearch(vector<int>& nums, int left, int right, int target) {
        if (left > right) return -1;
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) return rangesearch(nums, left, mid - 1, target);
        else return rangesearch(nums, mid + 1, right, target);
    }

    vector<int> findrange(vector<int>& nums, int mid, int target) {
        if (mid == -1) return {-1, -1};

        int ltemp = mid;
        int rtemp = mid;

        // 向左扩展
        while (ltemp > 0 && nums[ltemp - 1] == target) {
            ltemp--;
        }

        // 向右扩展
        while (rtemp < nums.size() - 1 && nums[rtemp + 1] == target) {
            rtemp++;
        }

        return {ltemp, rtemp};
    }
};