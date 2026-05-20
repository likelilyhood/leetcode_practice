#include<algorithm>
#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

bool check(vector<int>& pos,int m,int d){
    int n=pos.size();
    int cnt=0;
    int i=0;
    while(i<n){
        cnt++;
        int left=pos[i];
        while(i<n&&pos[i]-left<=d){
            i++;
        }
        int stop=pos[i-1];
        while(i<n&&pos[i]-stop<=d){
            i++;
        }
        if(cnt>m){
            return false;
        }
    }
    return cnt<=m;
}
int main (){
    int N,M;
    cin>>N>>M;
    vector<int> pos(N);
    for(int i=0;i<N;i++){
        cin>>pos[i];
    }
    int l=0;
    int r=pos[N-1]-pos[0];
    while(l<r){
        int mid=(l+r)/2;
        if(check(pos,M,mid)){
            r=mid;
        }else{
            l=mid+1;
        }    }
    cout<<l<<endl;
    return 0;
}