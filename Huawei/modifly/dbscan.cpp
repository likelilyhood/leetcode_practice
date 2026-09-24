#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
struct node{
    double x;
    double y;
    int label=0;
};

struct qury{
    double x;
    double y;
};
int main(){
    double n,m,e,minpt;
    
    cin>>n>>m>>e>>minpt;
    
    vector<node> nodes(n);
    vector<qury> qurys(m);
    vector<vector<double>> dist(n, vector<double>(n, 0.0));
    for(int i=0;i<n;i++){
       cin>>nodes[i].x>>nodes[i].y;
    }
    for(int i=0;i<m;i++){
       cin>>qurys[i].x>>qurys[i].y;
    }
    for(int i=0;i<n;i++){
        dist[i][i] = 0.0;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            dist[i][j] = sqrt(pow(nodes[i].x-nodes[j].x,2)+pow(nodes[i].y-nodes[j].y,2));
        }
    }
   for(int i=0;i<m;i++){
       int temp1=qurys[i].x;
       int temp2=qurys[i].y;
       if(dist[temp1][temp2]<e){
           cout<<"1"<<endl;
       }else{
           cout<<"0"<<endl; 
       }
    }
    cout<<endl;
    return 0;
}