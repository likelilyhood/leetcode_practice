#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // 交换函数
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // 主函数
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 0; // 用于记录非零元素应该放置的位置

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
