#include<iostream>
#include<string>
#include<map>
using namespace std;
class Solution {
    public:
        bool isAnagram(string s, string t) {
            int record[26] = {0};
            for (int i = 0; i < s.size(); i++) {
                record[s[i] - 'a']++;
            }
            for(int i=0;i<t.size();i++){
                record[t[i]-'a']--;
            }
            for(int i=0;i<26;i++){
                if(record[i]!=0){
                    return false;
                }
            }
            return true;

        }
    };
int main(){
    Solution s;
    cout<<s.isAnagram("anagram","nagaram")<<endl;
    cout<<s.isAnagram("rat","car")<<endl;
    return 0;
}