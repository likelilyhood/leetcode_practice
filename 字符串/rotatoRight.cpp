#include<bits/stdc++.h>
using namespace std;
int main (){
    string s;
    int n;
    cin>>n;
    cin>>s;
    int len=s.size();
    reverse(s.begin(),s.end());
    reverse(s.begin(),s.begin()+n);
    reverse(s.begin()+n,s.end());
    cout<<s<<endl;
    return 0;
}