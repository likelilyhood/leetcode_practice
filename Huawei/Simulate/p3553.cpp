#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct node
{
    double score;
    int index;
};

int main(){
    int n,m,p,k;
    cin>>n>>m>>p>>k;
    vector<double> expert(n);
    for(int i=0;i<n;i++){
        cin>>expert[i];
    }
    if(n%m!=0||p>m||p<=0){
        cout<<"error"<<endl;
        return 0;
    }
   int groupSize=n/m; 
   vector<vector<node>> groups(m);
   for(int i=0;i<n;i++){ 
    groups[i/groupSize].push_back({expert[i], i}); 
    } 
    vector<node> groupTopExperts(m); 
    for(int i=0;i<m;i++){ 
        sort(groups[i].begin(),groups[i].end(),[](const node& a, const node& b){
        return a.score > b.score;
        }); 
        groupTopExperts[i].score=groups[i][0].score; 
        groupTopExperts[i].index=i;
    }
    sort(groupTopExperts.begin(),groupTopExperts.end(),[](const node& a, const node& b){
        return a.score > b.score;
    });
    vector<int> selectedGroups;
    for(int i=0;i<p;i++){
        selectedGroups.push_back(groupTopExperts[i].index);
    }
    vector<node> candidates;
    for(int i=0;i<selectedGroups.size();i++){
        int groupIndex=selectedGroups[i];
        for(int j=0;j<groups[groupIndex].size();j++){
            candidates.push_back(groups[groupIndex][j]);
        }
    }
    if(candidates.size() < k){
    cout << "error" << endl;
    return 0;
}
    sort(candidates.begin(),candidates.end(),[](const node& a, const node& b){
        return a.score > b.score;
    });
    vector<int> ans;
    for(int i=0;i<k;i++){
        ans.push_back(candidates[i].index);
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}