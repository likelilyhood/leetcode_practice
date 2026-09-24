
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int N, K;
    cin >> N >> K;

    vector<int> f(N + 1);
    vector<int> pre(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> f[i];
        pre[i] = pre[i - 1] + f[i];
    }

    const int INF = 1e9;

    vector<vector<int>> dp(
        N + 1,
        vector<int>(K + 1, INF)
    );

    dp[0][0] = 0;

   for(int i=0;i<=N;i++){
        for(int j=1;j<=min(i,K);j++){
            for(int t=j-1;t<i;t++){
            int lastload = pre[i]-pre[t];
            int candite=max(dp[t][j-1],lastload);
            dp[i][j]=min(dp[i][j],candite);
            }
        }
    }

    cout << dp[N][K] << endl;

    return 0;
}