#include<bits/stdc++.h>
using namespace std;
int M,N,H;
int Data[100][100][100];
int visited[100][100][100];
class Pos{
    public:
    int x;int y;int z;
    Pos(int a,int b,int c){
        x=a;y=b;z=c;
    }
};
queue<pair<Pos, int>> Q;
void input(){
    cin>>N>>M>>H;
    
    for(int k=0;k<H;k++){
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                cin>>Data[i][j][k];
                if(Data[i][j][k]==1){
                    Pos p(i,j,k);
                    Q.push({Pos(i,j,k),1});
                }
            }
        }
    }
}
bool isWall(int x,int y,int z){
    return x<0||y<0||z<0||x>=M||y>=N||z>=H||Data[x][y][z]==-1||Data[x][y][z]==1;
}
void bfs(){
    while(!Q.empty()){
        Pos c = Q.front().first;
        int cnt = Q.front().second;
        if(visited[c.x][c.y][c.z]==0 || visited[c.x][c.y][c.z]>cnt){
            visited[c.x][c.y][c.z]=cnt;
        }
        Q.pop();
        int dir[6][3]={{0,1,0},{0,-1,0},{1,0,0},{-1,0,0},{0,0,1},{0,0,-1}};
        for(int d=0;d<6;d++){
            int nx=c.x+dir[d][0];
            int ny=c.y+dir[d][1];
            int nz=c.z+dir[d][2];
            if(!isWall(nx,ny,nz)){
                if(visited[nx][ny][nz]==0 || visited[nx][ny][nz]>cnt+1){
                    visited[nx][ny][nz]=cnt+1;
                    Q.push(make_pair(Pos(nx,ny,nz),cnt+1));
                }
            }
        }
    }
}
int main(){
    input();
    bfs();
    int max = 0;
    for(int k=0;k<H;k++){
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(visited[i][j][k]==0 && Data[i][j][k]!=-1){
                    max=-1;break;
                }
                else{
                    if(max<visited[i][j][k])max=visited[i][j][k];
                }
            }
            if(max==-1)break;
        }
        if(max==-1)break;
    }

    if(max==-1)cout<<max;
    else cout<<max-1;
}