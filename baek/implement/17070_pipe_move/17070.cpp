#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define SZ 17
typedef pair<int,int> pi;
int N;
int Map[SZ][SZ];
int D[SZ][SZ][3]; // count of state 0,1,2
int answer;
void input(){
    cin>>N;
    f(i,N){
        f(j,N){
            cin>>Map[i][j];
        }
    }
    memset(D,0,sizeof(D));
}
bool isWall(int x,int y){
    return x<0 || y<0 || x>=N || y>=N ||Map[x][y]==1;
}
deque<pair<int,pi>> q;//state,x,y
void bfs(){
    D[0][1][0]=1;
    answer = 0;
    q.push_back({0,{0,1}});
    while(!q.empty()){
        int state,count;
        int x,y;
        state = q.front().first;
        tie(x,y) = q.front().second;
        count = D[x][y][state];
        q.pop_front();
        if(Map[x][y]==1)continue;
        if(x==N-1 && y==N-1){
            answer++;
            continue;
        }
        switch(state){
            case 0://가로   
                if(!isWall(x,y+1)){
                    q.push_back({{0},{x,y+1}});
                }
                if(!isWall(x+1,y+1)&&!isWall(x,y+1)&&!isWall(x+1,y)){
                    q.push_back({{2},{x+1,y+1}});
                }
                break;
            case 1://세로
                if(!isWall(x+1,y)){
                    q.push_back({{1},{x+1,y}});
                }
                if(!isWall(x+1,y+1)&&!isWall(x,y+1)&&!isWall(x+1,y)){
                    q.push_back({{2},{x+1,y+1}});
                }
                break;
            case 2://대각선
                if(!isWall(x+1,y)){
                    q.push_back({{1},{x+1,y}});
                }
                if(!isWall(x+1,y+1)&&!isWall(x,y+1)&&!isWall(x+1,y)){
                    q.push_back({{2},{x+1,y+1}});
                }
                if(!isWall(x,y+1)){
                    q.push_back({{0},{x,y+1}});
                }
                break;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    bfs();
    cout<<answer<<"\n";
}