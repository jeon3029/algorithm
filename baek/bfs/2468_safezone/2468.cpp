#include<bits/stdc++.h>
using namespace std;
int Map[101][101];
int N;
int Max;
int Min = 987654321;
void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>Map[i][j];
            if(Max<Map[i][j])Max = Map[i][j];
            if(Min>Map[i][j])Min = Map[i][j];
        }
    }
}
typedef struct _pos{
    int x;
    int y;
}Pos;
bool isWall(int x,int y){
    if(x<0||y<0||x>=N||y>=N)return true;
    return false;
}
int find(int rain){
    queue<Pos> q;
    int visited[N][N];
    memset(visited,0,sizeof(visited));
    int cnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visited[i][j]==0 && Map[i][j]>rain){
                cnt++;
                Pos p;p.x=i;p.y=j;
                q.push(p);
                while(!q.empty()){
                    int x = q.front().x;
                    int y = q.front().y;
                    visited[x][y] = cnt;
                    q.pop();
                    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
                    for(int d=0;d<4;d++){
                        int nextX = x+dir[d][0];
                        int nextY = y+dir[d][1];
                        if(!isWall(nextX,nextY) && visited[nextX][nextY]==0){//벽이 아니고, 방문하지 않은 인접 위치
                            if(Map[nextX][nextY]>rain){
                                Pos temp;temp.x = nextX;temp.y=nextY;
                                visited[nextX][nextY] = cnt; // 한번 더 체크해야 중복으로 넣는 경우 없음.
                                q.push(temp);
                            }
                        }
                    }
                }
            }
        }
    }
    return cnt;
}
int main(int argc,char **argv){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    int max_area = 1;
    for(int rain = Min;rain<=Max;rain++){
        int temp = find(rain);
        if(max_area<temp)max_area = temp;
    }
    cout<<max_area<<endl;
}