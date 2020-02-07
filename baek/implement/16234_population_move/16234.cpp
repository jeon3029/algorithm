#include<bits/stdc++.h>
using namespace std;
int Map[51][51];
int N,L,R;
void input(){
    cin>>N>>L>>R;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>Map[i][j];
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
bool move(){
    queue<Pos> q;
    int visited[N][N];
    memset(visited,0,sizeof(visited));
    int cnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visited[i][j]==0){
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
                            int diff = abs(Map[nextX][nextY]-Map[x][y]);
                            if(diff>=L && diff<=R){//국경선 공유 가능할 때
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
    bool answer = false;
    vector<pair<int,int>> sum(cnt,make_pair(0,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            sum[visited[i][j]-1].first+=Map[i][j];
            sum[visited[i][j]-1].second++;
        }
    }
    vector<int> div(cnt,0);
    for(int i=0;i<sum.size();i++){
        div[i] = sum[i].first / sum[i].second;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int currentDiv = visited[i][j];
            if(Map[i][j] != div[currentDiv-1]){
                Map[i][j] = div[currentDiv-1];
                answer = true;//인구가 변경되었음.
            }
        }
    }
    return answer;
}
int main(int argc,char **argv){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    int turn;
    for(turn = 0;turn<2000;turn++){
        if(!move())break;
    }
    cout<<turn<<endl;
}