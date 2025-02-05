#include<iostream>
#include<vector>
using namespace std;
int main (){
    int n;
    int a;
    int b;
    vector<int> vec(n);
    vector<int> dp(n);
    int persum=0;
    scanf("%d %d %d",&n,&a,&b);
    for(int i=0;i<n;i++){
        scanf("%d",&vec[i]);
        persum+=vec[i];
        dp[i]=persum;
    }
    int res=0;
    if(a==0)res=dp[b];
    else res=dp[b]-dp[a-1];
    printf("%d\n",res);
    return 0;
}