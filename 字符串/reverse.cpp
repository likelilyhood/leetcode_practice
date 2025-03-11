#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
    public:
        void reverseString(vector<char>& s) {
            for(int i=0,j=s.size()-1;i<s.size()/2;i++,j--){
                int temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    };
int main(){
    Solution s;
    vector<char>si={'h','e','l','l','o'};
    vector<char>&nums=si;
    s.reverseString(nums);
    int i=0;
    while(i<5){cout<<si[i];i++;}
    return 0;
}