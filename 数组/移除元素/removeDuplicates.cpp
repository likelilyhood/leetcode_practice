#include<iostream>
#include<vector>
using namespace std;
 
class Solution{
public:
    int removeDuplicates(vector<int>& nums){
    int sp=1;
    for(int fp=1;fp<nums.size();fp++){
    if(nums[fp]!=nums[fp-1])nums[sp++]=nums[fp];
    }
return sp;
}

};
int main() {
    Solution sol;
    vector<int> nums = {1,2, 2, 3, 4, 4, 5,6};
    int newLength = sol.removeDuplicates(nums);
    cout << "新的长度是：" << newLength << endl;
    cout << "数组内容：";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}