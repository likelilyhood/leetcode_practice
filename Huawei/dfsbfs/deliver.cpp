#include<algorithm> 
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int n;
vector<int> price;
int ans = 1000000;
void dfs(int idx,int x,int y,int z){
    if(idx==n){
     if(x>y&&y>z&&z>0){
        ans=min(ans,x-z);
        }
     return;
    }
  
    dfs(idx+1,x+price[idx],y,z);
    dfs(idx+1,x,y+price[idx],z);
    dfs(idx+1,x,y,z+price[idx]);
}
int main(){
    cin>>n;
    price.resize(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    sort(price.begin(),price.end(),greater<int>());
    dfs(0,0,0,0);
    cout<<ans<<endl;
    return 0;
}