#include<bits/stdc++.h>
using namespace std;
int cheese[101][101];
int N,M;
vector<int> Count;//for count cheese in time passed
void input(){
    cin>>N>>M;
    Count.push_back(0);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>cheese[i][j];
            if(cheese[i][j]==1)Count[0]++;
        }
    }
}
bool isWall(int x,int y){
    return x<0||y<0||x>=N||y>=M;
}
typedef struct _pos{
    int x;
    int y;
}Pos;
void melt(){
    int melting[N][M];
    int visited[N][M];
    memset(melting,0,sizeof(melting));
    memset(visited,0,sizeof(visited));
    queue<Pos> q;
    Pos p;p.x=0;p.y=0;
    q.push(p);
    while(!q.empty()){
        int i = q.front().x;
        int j = q.front().y;
        visited[i][j] = 1;
        q.pop();
        int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        for(int d=0;d<4;d++){
            int nextX = i+dir[d][0];
            int nextY = j+dir[d][1];
            if(!isWall(nextX,nextY)){
                if(cheese[nextX][nextY]==1){//치즈인 경우
                    melting[nextX][nextY]=1;
                }
                else{//공기인 경우
                    if(visited[nextX][nextY]==0){
                        visited[nextX][nextY]=1;
                        Pos temp;temp.x = nextX;temp.y = nextY;
                        q.push(temp);
                    }
                }
            }
        }
    }
    int cnt = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(melting[i][j]==1){
                cnt++;
                cheese[i][j]=0;
            }
            
        }
    }
    int current = Count[Count.size()-1];
    Count.push_back(current-cnt);
}
int main(int argc, char**argv){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    int time;
    for(time=0;;time++){
        if(Count[time]==0)break;
        melt();
    }
    cout<<time<<endl<<Count[time-1]<<endl;
}