#include<bits/stdc++.h>
using namespace std;
int N;
int Data[10];
int dp[1<<9][1<<9];
int solve(int L, int R, int lsum, int rsum) {
    if (dp[L][R] != -1)return dp[L][R];
    int visited = L | R;
    if (visited == ((1 << N) - 1))return dp[L][R] = 1;
    dp[L][R] = 0;
    for (int i = 0; i < N; ++i) {
        if (!(visited & (1 << i))){
            if (lsum + Data[i] >= rsum)dp[L][R] += solve(L | (1 << i), R, lsum + Data[i], rsum);
            if (lsum >= rsum + Data[i])dp[L][R] += solve(L, R | (1 << i), lsum, rsum + Data[i]);
        }
    }
    return dp[L][R];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for (int tc=1;tc<=T;tc++) {
        cin>>N;
        for (int i=0;i<N;i++)cin>>Data[i];
        memset(dp,-1,sizeof(dp));
        cout<<"#"<<tc<<" "<<solve(0,0,0,0)<<"\n";
    }
}