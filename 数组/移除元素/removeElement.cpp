#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fastindex = 0;
        int slowindex = 0;
        for (fastindex = 0; fastindex < nums.size(); fastindex++) {
            if (nums[fastindex] != val) {
                nums[slowindex] = nums[fastindex];
                slowindex++; // 递增slowindex
            }
        }
        return slowindex; // 返回新数组的长度
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    int newLength = sol.removeElement(nums, val);
    cout << "New length: " << newLength << endl;
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}