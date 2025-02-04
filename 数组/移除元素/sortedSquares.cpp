#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int> sortedSquares(vector<int>& nums) {
        return mysort(nums);
    }
    private:
    vector<int> mysort(vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            nums[i]*=nums[i];
        }
        heapSort(nums);
    return nums;
    }
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;  // 初始化最大值为根节点
        int left = 2 * i + 1;  // 左子节点
        int right = 2 * i + 2;  // 右子节点

        // 如果左子节点存在且大于根节点
        if (left < n && nums[left] > nums[largest]) {
            largest = left;
        }

        // 如果右子节点存在且大于当前最大值
        if (right < n && nums[right] > nums[largest]) {
            largest = right;
        }

        // 如果最大值不是根节点，交换它们
        if (largest != i) {
            swap(nums[i], nums[largest]);
            // 递归地调整子树
            heapify(nums, n, largest);
        }
    }

    void heapSort(vector<int>& nums) {
        int n = nums.size();

        // 构建最大堆
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }

        // 逐个提取最大元素并调整堆
        for (int i = n - 1; i > 0; i--) {
            swap(nums[0], nums[i]);  // 将堆顶元素（最大值）与最后一个元素交换
            heapify(nums, i, 0);  // 调整剩余的堆
        }
    }

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};