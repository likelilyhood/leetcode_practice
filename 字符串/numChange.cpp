#include<bits/stdc++.h>
using namespace std;
int main (){
    string s;
    while (cin>>s){
        int solIndex=s.size()-1;
        int count=0;
        for(int i=0;i<=s.size();i++){
            if(s[i]>='0'&&s[i]<='9')count++;
        }
        s.resize(s.size()+count*5);
        int sNewIndex=s.size()-1;
        while(solIndex>=0){
            if(s[solIndex]>='0'&s[solIndex]<='9'){
                s[sNewIndex--]='r';
                s[sNewIndex--]='e';
                s[sNewIndex--]='b';
                s[sNewIndex--]='m';
                s[sNewIndex--]='u';
                s[sNewIndex--]='n';
            }
            else 
            s[sNewIndex--]=s[solIndex];
            solIndex--;
            }
        cout<<s<<endl;
    }
   
    return 0;
}
