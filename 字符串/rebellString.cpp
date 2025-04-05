#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution{
    string s;
    public:
    vector<string> split (const string& s){
        vector<string>words;
        string word;
        for(char c : s){
            if(c==' '){
                if(!word.empty()){
                    words.push_back(word);
                    word.clear();
                }
        }else{
                    word += c;
                }
            
        }
        if(!word.empty()){
            words.push_back(word);
            word.clear();
        }
        return words;
    }

    string reverse(const vector<string>& words){
        string result;
        for(int i=words.size()-1;i>=0;--i){
            result+=words[i];
            if(i>0){
                result+=' ';
            }
        }
        return result;
    }
   void setString(const string& input){
    s = input;
   }
   string func(){
    vector<string> words=split(s);
    return reverse(words);
   }
};
int main (){
    Solution solution;
    string input="hello word";
    solution.setString(input);
    string reversed =solution.func();

    cout<<reversed<<endl;
    return 0;
}