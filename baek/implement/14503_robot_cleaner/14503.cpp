#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
//predefined

int N,M;
int Data[50][50];
int answer = 0;
int visited[50][50];
int x,y,d;
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

void input(){
    cin>>N>>M;
    cin>>x>>y>>d;
    rep(i,0,N)rep(j,0,M)cin>>Data[i][j];
}
bool isWall(int x,int y){
    return x<0||y<0||x>=N||y>=M;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    while(1){
        //1
        if(!visited[x][y]){
            answer++;
            visited[x][y] = 1;
        }
        //2
        //a,b
        int flag = 0;
        int nd = d;
        for(int i=0;i<4;i++){
            nd = (nd+3)%4;//turn left
            int nx = x + dir[nd][0];
            int ny = y + dir[nd][1];
            if(!isWall(nx,ny) && !visited[nx][ny]&& Data[nx][ny]==0){
                x = nx;
                y = ny;
                d = nd;
                flag = 1;
                break;
            }
        }
        if(flag)continue;

        //c
        nd = (d+2)%4;//back
        int nx = x + dir[nd][0];
        int ny = y + dir[nd][1];
        if(!isWall(nx,ny) && Data[nx][ny]==0){
            x = nx;
            y = ny;
            continue;
        }
        //d
        break;
    }
    cout<<answer<<"\n";
}