#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int editDistance(string a, string b){
    int m=a.size(), n=b.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=0;i<=m;i++){
        dp[i][0]=i;
    }
    for(int j=0;j<=n;j++){
        dp[0][j]=j;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i]==b[j]){
                dp[i+1][j+1]=dp[i][j];
            }else{
                dp[i+1][j+1]=min({dp[i][j]+1, dp[i+1][j]+1, dp[i][j+1]+1});
            }

        }
    }
    return dp[m][n];
}
int main(){
    int dist, n;
    cin>>dist>>n;
    vector<string> command(n);
    for(int i=0;i<n;i++){
        cin>>command[i];
    }
    string wainfo;
    cin>>wainfo;
    int lenstr=wainfo.size();
    vector<pair<int,string>> ans;
   
    for(int i=0;i<n;i++){
        if(command[i]==wainfo){
            cout<<command[i]<<" "<<endl;
            return 0;
        }
        int d=editDistance(command[i], wainfo);
        if(d<=dist){
            ans.push_back({d, command[i]});
        }
    }
    
    sort(ans.begin(),ans.end());
    if(ans.empty()){
        cout<<"None"<<endl;
    }else{
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].second<<" ";
        }
    }
    cout<<endl;
    return 0;
}