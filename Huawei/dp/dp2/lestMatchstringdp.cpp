#include<string>
#include<iostream>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int m=s1.size(),n=s2.size();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }else if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=0;
            }
        }
    }
    int maxlen=0;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            maxlen=max(maxlen,dp[i][j]);
        }
     }
    cout<<maxlen<<endl;
    return 0;
}