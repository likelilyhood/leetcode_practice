#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Soution{
public:
    string reverseStr(string & s,int k){
        for (int i=0;i<s.size();i+=2*k){
            if(i+k<s.size())reverse(s.begin()+i,s.begin()+i+k);
            else reverse(s.begin()+i,s.end());

        }
        return s;
    }
};
int main(){
    string s="abcdefg";
    int k=2;
    Soution s1;
    cout<<s1.reverseStr(s,k)<<endl;
    return 0;
}