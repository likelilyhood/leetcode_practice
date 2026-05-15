#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int main(){
    long long  n,m;
    cin>>n>>m;
    vector<long long> costs(n);
    for(int i=0;i<n;i++){
        cin>>costs[i];
    }
    if (n < m) {
    cout << 0 << endl;
    return 0;
}
    vector<long long> dp(n+1,1e9);
    dp[0]=0;
    for(int i=0;i<n;i++){
        if(dp[i]==1e9){
            continue;
        }       
        for(int j=i+1;j<=i+m&&j<=n;j++){
            dp[j]=min(dp[j],dp[i]+costs[j-1]);
        }
    }
    long long ans=1e9;
    for(int i=n-m+1;i<=n;i++){
        ans=min(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}