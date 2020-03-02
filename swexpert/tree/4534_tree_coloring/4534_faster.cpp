#include<bits/stdc++.h>
using namespace std;
const int  MOD =1000000007;
vector<vector<int>>Input;
long long dp[100001][2];
int N;
void dfs(int cur,int parent){
    dp[cur][0] = 1;
    dp[cur][1] = 1;
    for (int i = 0; i < Input[cur].size(); i++){
        int y = Input[cur][i];
        if (y == parent)continue;
        dfs(y, cur);
        dp[cur][0] = (dp[cur][0] * (dp[y][1] + dp[y][0])) % MOD;
        dp[cur][1]=(dp[cur][1]*dp[y][0])%MOD;
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin >> T;
    for(int tc=1;tc<=T;tc++) {
        cin >> N;
        Input= vector<vector<int>>(N+1);
        for (int i = 0; i < N - 1; i++) {
            int a,b;cin>>a>>b;
            Input[a].push_back(b);
            Input[b].push_back(a);
        }
        dfs(1, -1);
        cout << "#" << tc << " " << (dp[1][0] + dp[1][1])%MOD << '\n';
    }
}