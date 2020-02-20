#include<bits/stdc++.h>
using namespace std;
int M,N;
int Data[1000][1000];
int visited[1000][1000];
class Pos{
    public:
    int x;int y;
    Pos(int a,int b){
        x=a;y=b;
    }
};
queue<pair<Pos, int>> Q;
vector<Pos> t;
void input(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin>>Data[i][j];
            if(Data[i][j]==1){
                Pos p(i,j);
                Q.push(make_pair(Pos(i,j),1));
            }
        }
    }
}
bool isWall(int x,int y){
    return x<0||y<0||x>=M||y>=N||Data[x][y]==-1||Data[x][y]==1;
}
void bfs(){
    while(!Q.empty()){
        Pos c = Q.front().first;
        int cnt = Q.front().second;
        if(visited[c.x][c.y]==0 || visited[c.x][c.y]>cnt){
            visited[c.x][c.y]=cnt;
        }
        Q.pop();
        int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        for(int d=0;d<4;d++){
            int nx=c.x+dir[d][0];
            int ny=c.y+dir[d][1];
            if(!isWall(nx,ny)){
                if(visited[nx][ny]==0 || visited[nx][ny]>cnt+1){
                    visited[nx][ny]=cnt+1;
                    Q.push(make_pair(Pos(nx,ny),cnt+1));
                }
            }
        }
    }
}
int main(){
    input();
    bfs();
    int max = 0;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(visited[i][j]==0 && Data[i][j]!=-1){
                max=-1;break;
            }
            else{
                if(max<visited[i][j])max=visited[i][j];
            }
        }
        if(max==-1)break;
    }
    if(max==-1)cout<<max;
    else cout<<max-1;
}