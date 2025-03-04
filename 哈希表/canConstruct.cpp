#include<iostream>
#include<string>
#include<map>
using namespace std;
class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            int record[26]={0};
            if(ransomNote.size()>magazine.size()){
                return false;
            }
            for(int i=0;i<magazine.size();i++){
                record[magazine[i]-'a']++;
            }
            for(int i=0;i<ransomNote.size();i++){
                record[ransomNote[i]-'a']--;
            }
            for(int i=0;i<26;i++){
                if(record[i]<0){
                    return false;
                }
            }
            return true;

        }
    };

int main(){
    Solution s;
    cout<<s.canConstruct("a","hgfadacb")<<endl;
    cout<<s.canConstruct("aa","ab")<<endl;
    cout<<s.canConstruct("aa","aab")<<endl;
    return 0;
}