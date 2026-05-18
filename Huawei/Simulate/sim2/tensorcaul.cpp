#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> number(n);
    number.resize(n);
    long long total=0;
    for(int i=0;i<n;i++){
        cin>>number[i];
        total+=number[i];
    }
    long long ans=total;
    long long seg=0;
    int l=0;
    for(int r=0;r<n;r++){
        seg+=number[r];
        ans=min(ans, max(6*seg, total-seg));
        while(l<=r && 6*seg>total-seg){
            seg-=number[l];
            l++;
            if(seg>0)ans=min(ans, max(6*seg, total-seg));
        }
    }
    cout<<ans<<endl;

    return 0;
}