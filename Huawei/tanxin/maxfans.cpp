#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> pvs(n);
    pvs.resize(n);
    for(int i=0;i<n;i++){
        cin>>pvs[i];
    }
    int cnt=0;
    vector<int> fans(n,0);
    for(int i=0;i<n;i++){
       if(pvs[i]==0)continue;
       if(i-1>=0&&fans[i-1]==1)continue;
       if(i+1<n&&pvs[i+1]==0&&fans[i+1]==0){
           fans[i+1]=1;
           cnt++;
        }else if(i-1>=0&&pvs[i-1]==0&&fans[i-1]==0){
           fans[i-1]=1;
           cnt++;
        }else{
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<cnt<<endl;
    return 0;
}