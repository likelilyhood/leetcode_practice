#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
const int INF=1e9;
int main(){
    int T;
    cin>>T;
    T=T-1;
    int k;
    cin>>k;
    
    vector<int> loss(T+1);
    for(int i=1;i<=T;i++){
        cin>>loss[i];
    }
    vector<vector<int>> dp(T+1, vector<int>(k+1, INF));
    
    dp[0][0]=0;
    for(int i=1;i<=T;i++){
        dp[i][0]=0;
        for(int j=1;j<=k;j++){
            dp[i][j]=min(dp[i][j],dp[i-1][j]);
            if(i>=2){
                    dp[i][j]=min(dp[i][j],dp[i-2][j-1]+loss[i]);
                }else{
                    if(j==1)
                    dp[i][j]=min(dp[i][j],loss[i]);
                }
                
            
        }
    }
    if(T<2*k-1){
        cout<<-1<<endl;
        return 0;
    }
    cout<<dp[T][k]<<endl;
    return 0;
}