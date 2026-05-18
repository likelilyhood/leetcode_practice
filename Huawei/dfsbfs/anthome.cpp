#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int n, m;
int grid[15][15];
int visited[15][15];

int totalFood = 0;
int ans = 0;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int foodCount) {
    if(x<0 || x>=n || y<0 || y>=m){
        return;
    }
    if(grid[x][y]==3){
        return;
    }
    if(visited[x][y]){
        return;
    }
    //arrive home
    if(grid[x][y]==1 && foodCount==totalFood){
        ans++;
        return;
    }
    if (grid[x][y] == 2) {
        foodCount++;
    }
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        dfs(newX, newY, foodCount);
        
    }

    visited[x][y] = 0;
}
int main (){
 
    cin>>n>>m;
    int startx,starty;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]==0){
                startx = i;
                starty = j;
            }
            if(grid[i][j]==2){
                totalFood++;
            }
        }
    }

    dfs(startx,starty,0);
    cout<<totalFood<<endl;
    cout<<ans<<endl;
    return 0;
}