#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,k_total;
vector<int> profit;
vector<int> cost;
int main (){
    cin>>n>>k_total;
    profit.resize(n);
    cost.resize(n);
    for(int i=0;i<n;i++){
        cin>>profit[i]>>cost[i];
    }
    int maxProfit=0;
    int l=0;
    int r=0;
    int curProfit=0;
    int curCost=0;
    while(r<n){
        curProfit+=profit[r];
        curCost+=cost[r];
        while(curCost>k_total){
            curProfit-=profit[l];
            curCost-=cost[l];
            l++;
        }
        maxProfit=max(maxProfit,curProfit);
        r++;
    }
    cout<<maxProfit<<endl;
    return 0;
}