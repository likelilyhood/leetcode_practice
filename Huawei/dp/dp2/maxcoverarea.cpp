#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main (){
    int areaReq,budget,n;
    cin>>areaReq>>budget>>n;
    vector<int>coverage(n),cost(n);
    for(int i=0;i<n;i++){
        cin>>coverage[i]>>cost[i];
        cost[i]/=10;
    }
    int sum1=0;
    for(int i=0;i<n;i++){
        sum1+=coverage[i];  
    }
    if(sum1<areaReq){
        cout<<0<<" "<<0<<endl;
        return 0;
    }
    vector<int>dp(budget/10+1,0);

    for(int i=0;i<n;i++){
        for(int j=budget/10;j>=0;j--){
            if(j>=cost[i]){
                dp[j]=max(dp[j],dp[j-cost[i]]+coverage[i]);
            }
        }
    }
    for(int i=0;i<budget/10+1;i++){
        if(dp[i]>=areaReq){
            cout<<i*10<<" "<<dp[i]<<endl;
            break;
        }else if(i==budget/10){
            cout<<0<<" "<<0<<endl;
        }
    }
    return 0;
}