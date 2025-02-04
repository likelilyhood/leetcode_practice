#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        return mytotalFruit(tree);
    }
private:
    int mytotalFruit(vector<int>& tree) {
        int n = tree.size();
        if (n == 0) {
            return 0;
        }
        int start = 0, end = 0;
        int mark1 = -1, mark2 = -1; // 初始化为 -1 表示未确定水果种类
        int maxLen = 0;

        while (end < n) {
            int currentFruit = tree[end];
            if (mark1 == -1) {
                mark1 = currentFruit;
            } else if (mark2 == -1 && currentFruit != mark1) {
                mark2 = currentFruit;
            } else if (currentFruit != mark1 && currentFruit != mark2) {
                maxLen = max(maxLen, end - start);
                start = end - 1;
                // 回溯找到上一个不同水果种类的起始位置，添加 start > 0 的检查
                while (start > 0 && tree[start] == tree[start - 1]) {
                    start--;
                }
                mark1 = tree[start];
                mark2 = currentFruit;
            }
            end++;
        }
        // 处理最后一段满足条件的子数组
        maxLen = max(maxLen, end - start);

        return maxLen;
    }
};


int main() {
    Solution sol;
    vector<int> tree = {1,2,1,2,3};
    int maxLen = sol.totalFruit(tree);
    cout << "Max length: " << maxLen << endl;
    return 0;
}