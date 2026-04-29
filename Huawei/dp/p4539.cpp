#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <deque>
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
    int n,d;
    cin>>n>>d;
    int R=min(d,n);
    vector<int> update_cost(n),query_reward(n);
    for(int i=0;i<n;i++){
        cin>>update_cost[i];
    }
    for(int j=0;j<n;j++){
        cin>>query_reward[j];
    }
    vector<int> next(R,0),cur(R,0);
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<R;j++){
            int no_update;
            if(j>0){
                no_update=query_reward[i]+next[j-1];
            }else{
                no_update=next[0];
            }

            int updateand_query=query_reward[i]+next[min(R-1,d-1)]-update_cost[i];
            cur[j]=max(no_update,updateand_query);
        }
        next=cur;
    }
    cout<<next[0]<<endl;
    return 0;
}