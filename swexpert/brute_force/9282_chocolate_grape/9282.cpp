#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int N,M;
int Data[50][50];
int answer = 0;
int memo[50][50][51][51];
int p_sum[51][51];
void input(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>Data[i][j];
        }
    }
}
int dfs(int x,int y,int h,int w){
    if(w==1&&h==1)return 0;
    if(memo[x][y][h][w]!=0)return memo[x][y][h][w];
    int curV=0; 
    curV = p_sum[x+h][y+w]-p_sum[x+h][y]-p_sum[x][y+w]+p_sum[x][y];
    if(memo[x][y][h][w]==0)memo[x][y][h][w]=INF;
    for(int i=1;i<h;i++){
        if(memo[x][y][i][w]==0)memo[x][y][i][w] = dfs(x,y,i,w);
        if(memo[x+i][y][h-i][w]==0)memo[x+i][y][h-i][w]=dfs(x+i,y,h-i,w);
        memo[x][y][h][w] = min(memo[x][y][h][w],memo[x][y][i][w]+memo[x+i][y][h-i][w]);
    }
    for(int i=1;i<w;i++){
        if(memo[x][y][h][i]==0)memo[x][y][h][i] = dfs(x,y,h,i);
        if(memo[x][y+i][h][w-i]==0)memo[x][y+i][h][w-i] = dfs(x,y+i,h,w-i);
        memo[x][y][h][w] = min(memo[x][y][h][w],memo[x][y][h][i]+memo[x][y+i][h][w-i]);
    }
    memo[x][y][h][w]+=curV;
    return memo[x][y][h][w];
}
int s_dfs(int n,int m){
    if(n<1 || m<1)return 0;
    if(p_sum[n][m]!=0)return p_sum[n][m];
    p_sum[n][m] = s_dfs(n-1,m) + s_dfs(n,m-1) - s_dfs(n-1,m-1) + Data[n-1][m-1];
    return p_sum[n][m];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        memset(memo,0,sizeof(memo));
        memset(p_sum,0,sizeof(p_sum));
        s_dfs(N,M);
        answer = dfs(0,0,N,M);
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
}