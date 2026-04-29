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
const double INF=1e18;
struct node
{   
    int num;
    double  loss[2];
    int lossIndex[2];
    double  mem[2];
};

int main(){
    int L;
    double max_loss;
    cin>>L>>max_loss;
    int Mloss=round(max_loss*100);
    vector<node> nodes(L);
    for(int i=0;i<L;i++){
        cin>>nodes[i].num;
        for(int j=0;j<nodes[i].num;j++){
            string s;
            cin>>s;
            cin>>nodes[i].loss[j]>>nodes[i].mem[j];
            nodes[i].lossIndex[j]=round(nodes[i].loss[j]*100);

        }
    }
    vector<double> dp(Mloss+1,INF);
    dp[0]=0;
    for(int i=0;i<L;i++){
        vector<double> next_dp(Mloss+1,INF);
        for(int curloss=0;curloss<=Mloss;curloss++){
            for(int k=0;k<nodes[i].num;k++){
                double mem1=nodes[i].mem[k];
                if(nodes[i].lossIndex[k]+curloss<=Mloss){
                    next_dp[nodes[i].lossIndex[k]+curloss]=min(next_dp[nodes[i].lossIndex[k]+curloss],dp[curloss]+mem1);
                }
            }
        }
        dp=next_dp;
    }
    double ans=INF;
    for(int i=0;i<=Mloss;i++){
        ans=min(ans,dp[i]);
    }
    printf("%.2f\n",ans);
    return 0;
}

