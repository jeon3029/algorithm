#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
//predefined

int N,M,R,C;
int Time;
int answer = 0;
int Map[50][50];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};//동남서북
int tunnel[7][4]{//동남서북
    {1,1,1,1},
    {0,1,0,1},
    {1,0,1,0},
    {1,0,0,1},
    {1,1,0,0},
    {0,1,1,0},
    {0,0,1,1}
};
bool isWall(int x,int y){
    return x<0||y<0||x>=N||y>=M;
}
void input(){
    cin>>N>>M>>R>>C>>Time;
    rep(i,0,N)rep(j,0,M)cin>>Map[i][j];
}
typedef struct _xyt{
    int x;int y;int t;
    _xyt(int a,int b,int c):x(a),y(b),t(c){}
}xyt;
void bfs(){
    queue<xyt> q;
    q.push(xyt(R,C,1));
    int visited[50][50];
    memset(visited,0,sizeof visited);
    while(!q.empty()){
        int cx = q.front().x;
        int cy = q.front().y;
        int ct = q.front().t;
        q.pop();
        int val = Map[cx][cy];
        if(ct>Time || val==0)continue;
        if(visited[cx][cy]==0){
            visited[cx][cy]=ct;
        }
        if(ct+1>Time)continue;
        for(int d=0;d<4;d++){
            if(tunnel[val-1][d]){//check direction opened
                int nx = cx + dir[d][0];
                int ny = cy + dir[d][1];
                if(!isWall(nx,ny) && Map[nx][ny]!=0){
                    int nval = Map[nx][ny];
                    if(tunnel[nval-1][(d+2)%4]==0)continue;//check next direction opened
                    if(visited[nx][ny]){
                        if(visited[nx][ny]>ct+1){
                            q.push(xyt(nx,ny,ct+1));
                        }
                    }
                    else{
                        visited[nx][ny]=ct+1;
                        q.push(xyt(nx,ny,ct+1));
                    }
                }
            }
        }
    }
    rep(i,0,N){
        rep(j,0,M){
            if(visited[i][j])answer++;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        answer = 0;
        bfs();
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
}