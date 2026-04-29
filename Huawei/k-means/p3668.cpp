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
struct Node{
        double h,w,x,y;
};

double dist(Node& a, Node& b){
        return (a.h-b.h)*(a.h-b.h)+(a.w-b.w)*(a.w-b.w)+(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    }
int main(){
    int k,m,n;
    cin >> k >> m >> n;
    vector<Node> nodes(m);
    vector<Node> centersint(k);
   
    for(int i = 0; i < m; i++){
        cin >> nodes[i].h >> nodes[i].w >> nodes[i].x >> nodes[i].y;

        if(i < k){   
            centersint[i] = nodes[i];
        }
    }
    vector<int> cnt(k,0);
while(n--){
    vector<Node> Oldcenter = centersint;

    vector<Node> sum(k, {0, 0, 0, 0});
    cnt.assign(k, 0);

    for(int i = 0; i < m; i++){
        double bestDist = 10;
        int index = -1;
        for(int j = 0; j < k; j++){
            double d = dist(nodes[i], centersint[j]);

            if(d < bestDist){
                bestDist = d;
                index = j;
            }
        }

        sum[index].h += nodes[i].h;
        sum[index].w += nodes[i].w;
        sum[index].x += nodes[i].x;
        sum[index].y += nodes[i].y;
        cnt[index]++;
    }

    for(int j = 0; j < k; j++){
        if(cnt[j] == 0) continue;

        centersint[j].h = sum[j].h / cnt[j];
        centersint[j].w = sum[j].w / cnt[j];
        centersint[j].x = sum[j].x / cnt[j];
        centersint[j].y = sum[j].y / cnt[j];
    }

    bool same = true;
    for(int j = 0; j < k; j++){
        if(centersint[j].h != Oldcenter[j].h ||
           centersint[j].w != Oldcenter[j].w ||
           centersint[j].x != Oldcenter[j].x ||
           centersint[j].y != Oldcenter[j].y){
            same = false;
            break;
        }
    }

    if(same){
        break;
    }
}
    sort(cnt.begin(), cnt.end());
    for(int i = 0; i < k; i++){
        cout<<cnt[i]<<" ";
    }
    cout<<endl;
    return 0;
}