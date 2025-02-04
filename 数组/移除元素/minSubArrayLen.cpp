#include<iostream>
#include<vector>
using namespace std;
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        return myminSubArrayLen(target,nums);
    }
private:
 int myminSubArrayLen(int target, vector<int>& nums){
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int start = 0, end = 0;
        int sum = 0;
        int minLen =  n+1;
        while (end < n) {
            sum += nums[end];
            while (sum >= target) {
                minLen = min(minLen, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return minLen == n + 1 ? 0 : minLen;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    int minLen = sol.minSubArrayLen(target, nums);
    cout << "Min length: " << minLen << endl;
    return 0;
}