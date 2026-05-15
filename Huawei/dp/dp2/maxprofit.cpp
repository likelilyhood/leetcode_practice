#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main (){
    int n;
    vector<int>profit;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        profit.push_back(x);
    }
    vector<int>dp(n+1,0);
    dp[0]=profit[0];
    for(int i=1;i<n;i++){
        dp[i]=max(profit[i],profit[i]+dp[i-1]);
    }
    sort(dp.begin(),dp.end());
    int ans=dp[n];
    cout<<ans<<endl;
    return 0;
}