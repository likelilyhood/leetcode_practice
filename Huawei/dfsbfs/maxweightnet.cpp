#include<map>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
void dfs(int u,vector<vector<int>>& graph,vector<bool>& visited,int& sumweight,vector<int>& weight,int& maxNode){
   visited[u] = true;
    sumweight += weight[u];
    if(maxNode==-1 || weight[u]>weight[maxNode]){
        maxNode = u;
    }for(int i=0;i<graph[u].size();i++){
        int v = graph[u][i];
        if(!visited[v]){
            dfs(v,graph,visited,sumweight,weight,maxNode);
        }
    }
}
int main(){
    int n;
    cin>>n;
    map<string,int> nameToid;
    vector<int> weight(n);
    vector<string> names(n);
    for(int i=0;i<n;i++){
        cin>>names[i]>>weight[i];
        nameToid[names[i]]=i;
    }
    vector<vector<int>> graph(n);
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        string a,b;
        cin>>a>>b;
        graph[nameToid[a]].push_back(nameToid[b]);
        graph[nameToid[b]].push_back(nameToid[a]);
    }

    vector<bool> visited(n,false);
    int bestsum = -1;
    int bestNode = -1;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            int sumWeight = 0;
            int maxNode = -1;
            dfs(i,graph,visited,sumWeight,weight,maxNode);
            bestsum = max(bestsum,sumWeight);
            if(sumWeight>=bestsum){
                bestNode = maxNode;
                bestsum = sumWeight;
            }
        }
    }
    cout<<names[bestNode]<<" "<<bestsum<<endl;
    return 0;
}