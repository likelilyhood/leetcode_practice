#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int k;
    cin>>k;
    if (k <= 0 || k > 100) {
        cout << -2 << endl;
        return 0;
    }
    vector<vector<int>> maps(k,vector<int>(k,0));
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            cin>>maps[i][j];
            if (maps[i][j] < 0 || maps[i][j] > 10) {
                cout << -2 << endl;
                return 0;
            }
        }
    }
    vector<vector<int>> dp(k,vector<int>(k,1000000));
    dp[0][0]=maps[0][0];
    for(int j=0;j<k;j++){
        for(int i=0;i<k;i++){
           if(dp[i][j]==1000000){
               continue;
           }
           if(i+1<k&&abs(maps[i][j]-maps[i+1][j])<=1){
               dp[i+1][j]=min(dp[i+1][j],dp[i][j]+maps[i+1][j]);
           }
           if(j+1<k&&abs(maps[i][j]-maps[i][j+1])<=1){
               dp[i][j+1]=min(dp[i][j+1],dp[i][j]+maps[i][j+1]);
           }
        }
    }
    int ans=1000001;
for(int i=0;i<k;i++){
        ans=min(ans,dp[i][k-1]);
    }
    if(ans>=1000000){cout<<-1<<endl;}
    else cout<<ans<<endl;
    // for(int i=0;i<k;i++){
    //     for(int j=0;j<k;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;

}