#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int N;
long long ans;
long long D[100001][2];
vector<vector<int>> G;
long long dfs(int parent,int node, int color){
    //memoization
    if (D[node][color] != -1) return D[node][color] % MOD;
    
    int cnt = 0;
    for (int i = 0; i < G[node].size(); i++){
        int y = G[node][i];
        if (y==parent)
            continue;
        cnt++;
    }
    //leaf node
    if (cnt == 0) return 1;
    
    D[node][color] = 0;
    if (color == 0){//black
        long long mul = 1;
        for (int i = 0; i < G[node].size(); i++){
            long long sum = 0;
            int y = G[node][i];
            if (y!=parent){
                sum += (dfs(node,y, 1)) % MOD;//white
                sum %= MOD;
                mul *= sum;
                mul %= MOD;
            }
        }
        D[node][color] = mul;
    }
    if(color==1){//white
        long long mul = 1;
        for (int i = 0; i < G[node].size(); i++){
            long long sum = 0;
            int y = G[node][i];
            if (y!=parent){
                sum += ((dfs(node,y, 0)) % MOD) + ((dfs(node,y, 1)) % MOD);//black+white
                sum %= MOD;
                mul *= sum;
                mul %= MOD;
            }
        }
        D[node][color] = mul;
    }
    return D[node][color];
}
int main(){
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++){
        memset(D,-1,sizeof(D));
        cin >> N;
        G=vector<vector<int>>(N+1);
        for (int i = 1; i < N; i++){
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        ans = (dfs(-1,1,0)%MOD+dfs(-1,1, 1)%MOD)%MOD;
        cout <<"#"<<tc<<" "<< ans << endl;
    }
    return 0;
}
