#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // 外层循环遍历数组中的每个元素
        for (int i = 0; i < nums.size(); i++) {
            // 内层循环从 i + 1 开始，避免重复使用同一个元素
            for (int j = i + 1; j < nums.size(); j++) {
                // 计算两数之和
                if (nums[i] + nums[j] == target) {
                    // 若两数之和等于目标值，返回包含两个数索引的向量
                    return {i, j};
                }
            }
        }
        // 理论上不会执行到这里，因为题目保证有且只有一个解
        return {};
    }
};

// 以下是测试代码
int main() {
    Solution sol;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = sol.twoSum(nums, target);
    std::cout << "[" << result[0] << ", " << result[1] << "]" << std::endl;
    return 0;
}