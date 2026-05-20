#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
vector<int>takes;
int convert(int takes,int k){
    if(takes%k==0){
        return takes/k;
    }
    else{
        return takes/k+1;
    }
}
int limit;
int main(){
    cin>>n;
    takes.resize(n);
    for(int i=0;i<n;i++){
        cin>>takes[i];
    }
    cin>>limit;
    sort(takes.begin(),takes.end(),greater<int>());
    
    if(limit<n){
        cout<<-1<<endl;
        return 0;
    }
    if(limit==n){
        cout<<takes[0]<<endl;
        return 0;
    }
    int time=0;
    int flag=1;
    int machine=1;
   while(flag){
    time=0;
        for(int i=0;i<n;i++){
            time+=convert(takes[i],machine);
        }
        if(time<=limit){
            flag=0;
        }
        else{
            machine++;
        }
   }
    cout<<machine<<endl;
    return 0;
}