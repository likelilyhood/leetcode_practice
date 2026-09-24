#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main (){
    int len,division,g,w,t;
    vector<int> gift;
    
    cin>>len>>division>>g>>w>>t;
    if(g){
        for(int i=0;i<g;i++){
            int temp;
            cin>>temp;
            gift.push_back(temp);
        }
    }
    int q[len][division];
    int k[len][division];
    int v[len][division];
    for(int i=0;i<len;i++){
        for(int j=0;j<division;j++){
            cin>>q[i][j];
        }
    }
    for(int i=0;i<len;i++){
        for(int j=0;j<division;j++){
            cin>>k[i][j];
        }
    }
    for(int i=0;i<len;i++){
        for(int j=0;j<division;j++){
            cin>>v[i][j];
        }
    }

for (int i = 0; i < len; i++) {

    // 1. 构造当前 i 的候选集合
    vector<int> c;

    bool isGlobal =
        find(gift.begin(), gift.end(), i) != gift.end();

    if (isGlobal) {
        for (int j = 0; j < len; j++) {
            c.push_back(j);
        }
    }
    else {
        c = gift;

        for (int j = max(0, i-w);
             j <= min(len-1, i+w);
             j++) {

            c.push_back(j);
        }

        sort(c.begin(), c.end());

        c.erase(
            unique(c.begin(), c.end()),
            c.end()
        );
    }

    // 2. 计算正分数候选
    vector<pair<long long, int>> candidates;

    for (int j : c) {

        long long score = 0;

        for (int x = 0; x < division; x++) {
            score += 1LL * q[i][x] * k[j][x];
        }

        if (score > 0) {
            candidates.push_back({score, j});
        }
    }

    // 3. TODO：排序 candidates
    sort(candidates.begin(), candidates.end(), [](const pair<long long, int>& a, const pair<long long, int>& b) {
        if(a.first == b.first) {
            return a.second < b.second; // 分数相同，按索引从小到大排序
        }
        return a.first > b.first; // 按照分数从大到小排序
    });

    // 4. TODO：选取前 t 个候选
    int cnt = min(t, (int)candidates.size());
    vector<vector<long long>> o(len, vector<long long>(division, 0));
    for(int p=0;p<cnt;p++){
        int score = candidates[p].first;
        int j=candidates[p].second;
        for(int x=0;x<division;x++){
            o[i][x] += 1LL * score * v[j][x];
        }
    }
    // 5. TODO：计算当前输出行 o[i]
    for (int x = 0; x < division; x++) {
        cout << o[i][x] << " ";
    }
    cout << endl;
}
    return 0;
}