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
int main(){
    int H,W,K;
    cin>>H>>W>>K>>K;
    vector<vector<double>> img(H, vector<double>(W));
    vector<vector<double>> kernel(K, vector<double>(K));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>img[i][j];
        }
    }
    for(int i=0;i<K;i++){
        for(int j=0;j<K;j++){
            cin>>kernel[i][j];
        }
    }
    vector<vector<double>> erg(H, vector<double>(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            double sum=0;
            for(int k=0;k<K;k++){
                for(int l=0;l<K;l++){
                    int x=i+k-K/2;
                    int y=j+l-K/2;
                    if(x>=0&&x<H&&y>=0&&y<W){
                        sum+=img[x][y]*kernel[k][l];
                    }
                }
            }   
            erg[i][j]=sum;
        }
    }
    double cnt=-1e18;
    vector<vector<double>> dp(H, vector<double>(W,0));
    for(int i=0;i<H;i++){
        dp[i][0]=erg[i][0];
        cnt=max(cnt,dp[i][0]);
    }
    for(int j=1;j<W;j++){
        for(int i=0;i<H;i++){
            dp[i][j]=dp[i][j-1]+erg[i][j];
            if(i>0){
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+erg[i][j]);
            }
            if(i+1<H){
                dp[i][j]=max(dp[i][j],dp[i+1][j-1]+erg[i][j]);
            }
             cnt=max(cnt,dp[i][W-1]);//这里务必更新到最后一行的最大值，因为最后一列的值可能不是最大的，可能在中间某一列就已经达到了最大值了
            }
        }
    printf("%.1f\n",cnt);
    return 0;
}

