#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int N,M;
int Data[50][50];
int answer = 0;
int memo[51][51][51][51];
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
    if(memo[x][y][h][w]!=INF)return memo[x][y][h][w];
    int curV=0; 
    for(int i=x;i<x+h;i++){
        for(int j=y;j<y+w;j++){
            curV+=Data[i][j];
        }
    }
    for(int i=1;i<h;i++){
        if(memo[x][y][i][w]==INF)memo[x][y][i][w] = dfs(x,y,i,w);
        if(memo[x+i][y][h-i][w]==INF)memo[x+i][y][h-i][w]=dfs(x+i,y,h-i,w);
        memo[x][y][h][w] = curV+min(memo[x][y][h][w],memo[x][y][i][w]+memo[x+i][y][h-i][w]);
    }
    for(int i=1;i<w;i++){
        if(memo[x][y][h][i]==INF)memo[x][y][h][i] = dfs(x,y,h,i);
        if(memo[x][y+i][h][w-i]==INF)memo[x][y+i][h][w-i] = dfs(x,y+i,h,w-i);
        memo[x][y][h][w] = curV+min(memo[x][y][h][w],memo[x][y][h][i]+memo[x][y+i][h][w-i]);
    }
    return memo[x][y][h][w];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        answer = INF;
        fill(memo[0][0][0],memo[0][0][0]+51*51*51*51+1,INF);
        answer = dfs(0,0,N,M);
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
}