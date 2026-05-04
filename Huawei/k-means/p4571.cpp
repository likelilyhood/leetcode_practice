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
    double  x,y,z;
};
double distance(Si s1,Si s2){
    return (s1.x-s2.x)*(s1.x-s2.x)+(s1.y-s2.y)*(s1.y-s2.y)+(s1.z-s2.z)*(s1.z-s2.z);
}
double Silhouette_Index(Si s,Si center1,Si center2){
    double a=distance(s,center1);
    double b=distance(s,center2);
    return (b-a)/max(a,b);
}
int main(){
    int k,t,m;
    cin>>k;
    vector<Si> center(k);
    for(int i=0;i<k;i++){
        cin>>center[i].x>>center[i].y>>center[i].z;
    }   
    cin>>t>>m;
    vector<Si> s(m);
    for(int i=0;i<m;i++){
        cin>>s[i].x>>s[i].y>>s[i].z;
    }
    while(t--){
        vector<Si> sum(k,{0,0,0});
        vector<int> cnt(k,0);
        vector<Si> Oldcenter=center;
        for(int i=0;i<m;i++){
            double bestSilhouette=-1;
            int index=-1;
            for(int j=0;j<k;j++){
                double silhouette=Silhouette_Index(s[i],center[j],center[(j+1)%k]);
                if(silhouette>bestSilhouette){
                    bestSilhouette=silhouette;
                    index=j;
                }
            }
            sum[index].x+=s[i].x;
            sum[index].y+=s[i].y;
            sum[index].z+=s[i].z;
            cnt[index]++;
        }
        for(int i=0;i<k;i++){
            if(cnt[i]>0){
                center[i].x=sum[i].x/cnt[i];
                center[i].y=sum[i].y/cnt[i];
                center[i].z=sum[i].z/cnt[i];
            }
        }
        bool same=true;
        for(int i=0;i<k;i++){
            if(center[i].x!=Oldcenter[i].x||center[i].y!=Oldcenter[i].y||center[i].z!=Oldcenter[i].z){
                same=false;
                break;        
            }
        }
        if(same)break;
}
    for(int i=0;i<k;i++){
        printf("%.2f %.2f %.2f\n",center[i].x,center[i].y,center[i].z);
    }
    return 0;
}
