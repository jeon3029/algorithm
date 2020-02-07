#include<bits/stdc++.h>
#define MAX 987654321
using namespace std;
int N;
int Map[20][20];
int Time=0;
class Shark{
    public:
    int x;
    int y;
    int size;
    Shark(){
        size = 2;
    }
};
Shark baby_shark;
void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>Map[i][j];
            if(Map[i][j]==9){
                baby_shark.x=i;
                baby_shark.y=j;
            }
        }
    }
}
bool isWall(int x,int y){
    if(x<0||y<0 ||y>=N||x>=N||Map[x][y]==9)return true;
    return false;
}
typedef struct _pos{
    int x;int y;int time;
}Pos;
vector<Pos> find_eattable(){
    queue<pair<int,int>> q; //shark pos x,y
    pair<int,int> visited[N][N];//visited,time
    int eattable[N][N];
    vector<Pos>answer;
    memset(visited,0,sizeof(visited));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            eattable[i][j] = MAX;
        }
    }

    visited[baby_shark.x][baby_shark.y].first=1;
    visited[baby_shark.x][baby_shark.y].second=0;
    q.push(make_pair(baby_shark.x,baby_shark.y));
    while(!q.empty()){
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        int curX = q.front().first;
        int curY = q.front().second;q.pop();
        for(int i=0;i<4;i++){
            int nextX = curX + dir[i][0];
            int nextY = curY + dir[i][1];
            if(!isWall(nextX,nextY) && Map[nextX][nextY]<=baby_shark.size){//이동 가능할 때
                if(visited[nextX][nextY].first==0){//아직 방문하지 않았다면
                    visited[nextX][nextY].first =1;
                    visited[nextX][nextY].second = visited[curX][curY].second+1;
                    if(Map[nextX][nextY]!=0 && Map[nextX][nextY]<baby_shark.size){//먹을 수 있다면
                        if(eattable[nextX][nextY]>visited[curX][curY].second+1){
                            eattable[nextX][nextY] = visited[curX][curY].second+ 1;
                        }
                    }
                    q.push(make_pair(nextX,nextY));
                }
                else{//이미 방문했다면
                    if(Map[nextX][nextY]!=0&&Map[nextX][nextY]<baby_shark.size){//먹을 수 있다면
                        if(eattable[nextX][nextY]>visited[curX][curY].second+1){
                            eattable[nextX][nextY] = visited[curX][curY].second + 1;
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(eattable[i][j]!=MAX){
                Pos p;
                p.x = i;p.y=j;p.time=eattable[i][j];
                answer.push_back(p);
            }
        }
    }
    return answer;
}
bool my_cmp(Pos a,Pos b){
    if(a.time==b.time){
        if(a.x==b.x){
            return a.y<b.y;
        }
        return a.x<b.x;
    }
    return a.time<b.time;
}
bool eat(){
    vector<Pos> eattable = find_eattable();
    if(eattable.size()==0)
        return false;

    sort(eattable.begin(),eattable.end(),my_cmp);
    Map[eattable[0].x][eattable[0].y]=0;
    Time +=eattable[0].time;
    Map[baby_shark.x][baby_shark.y]=0;
    baby_shark.x=eattable[0].x;
    baby_shark.y=eattable[0].y;
    Map[baby_shark.x][baby_shark.y]=9;
    return true;
}
int main(int argc,char**argv){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    int cnt = 0;
    while(1){
        if(!eat())break;
        else{
            cnt++;
            if(cnt==baby_shark.size){
                baby_shark.size++;
                cnt=0;
            }
        }
    }
    cout<<Time<<endl;
}