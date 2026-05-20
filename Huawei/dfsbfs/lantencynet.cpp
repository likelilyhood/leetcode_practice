#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int m,n;
vector<vector<int> > gird;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
long long cnt=0;

int main (){
    cin>>m>>n;
    gird.resize(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>gird[i][j];
        }   
     }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(gird[i][j]==1){
                cnt++;
                queue<pair<int,int>>q;
                q.push({i,j});
                gird[i][j]=0;
                while(!q.empty()){
                    pair<int,int> cur = q.front();
                    q.pop();
                    int x=cur.first;
                    int y=cur.second;
                    for(int k=0;k<8;k++){
                        int nx=x+dx[k];
                        int ny=y+dy[k];
                        if(nx<0||nx>=m||ny<0||ny>=n||gird[nx][ny]==0){
                            continue;
                        }
                        if(gird[nx][ny]==0){
                            continue;
                        }
                        q.push({nx,ny});
                        gird[nx][ny]=0;
                    }
                }
            }
        }
    }
    long long ans=cnt*(cnt-1)/2;
    cout<<ans<<endl;
    return 0;
}