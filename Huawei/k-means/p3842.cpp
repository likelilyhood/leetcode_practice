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
struct Si
{
    double  h,w;
};
double IOU(Si s1,Si s2){
    double interArea=max(0.0,min(s1.h,s2.h)*min(s1.w,s2.w));
    double unionArea=s1.h*s1.w+s2.h*s2.w-interArea;
    unionArea+=1e-16;
    return interArea/unionArea;
}


int main(){
   int n, k, t;
cin >> n >> k >> t;

vector<Si> s(n);

for(int i = 0; i < n; i++){
    cin >> s[i].h >> s[i].w;
}

vector<Si> center(k);

for(int i = 0; i < k; i++){
    center[i] = s[i];
}

while(t--){
    vector<vector<Si>> group(k);

    for(int i = 0; i < n; i++){
        double bestDist = 1e18;
        int index = -1;

        for(int j = 0; j < k; j++){
            double d = 1.0 - IOU(s[i], center[j]);

            if(d < bestDist){
                bestDist = d;
                index = j;
            }
        }

        group[index].push_back(s[i]);
    }

    bool same = true;

    for(int i = 0; i < k; i++){
        if(group[i].empty()) continue;

        int sumh = 0;
        int sumw = 0;

        for(auto item : group[i]){
            sumh += item.h;
            sumw += item.w;
        }

        Si newCenter;
        newCenter.h = sumh / group[i].size();
        newCenter.w = sumw / group[i].size();

        if(newCenter.h != center[i].h || newCenter.w != center[i].w){
            same = false;
        }

        center[i] = newCenter;
    }

    if(same){
        break;
    }
    }
   sort(center.begin(), center.end(), [](const Si &a, const Si &b){
    return a.h * a.w > b.h * b.w;
    });
    for(int i = 0; i < k; i++){
        printf("%.0f %.0f\n", center[i].h, center[i].w);
    }
    return 0;
}
