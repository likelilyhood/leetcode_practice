#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

int N,maxmem;
int pretime[1000];
int checkpoint[1000];

int main (){
    cin>>N>>maxmem;
    for(int i=0;i<N;i++){
        cin>>pretime[i];
    }
    for(int i=0;i<N;i++){
        cin>>checkpoint[i];
    }
    vector<vector<int>> dp(N+1,vector<int>(maxmem+1,0));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=maxmem;j++){
            if(j>=checkpoint[i-1]){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-checkpoint[i-1]]+pretime[i-1]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
     
    cout<<dp[N][maxmem]<<endl;
    return 0;
}