#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
//predefined

int N,W,H;
int Map[15][12];
int cur_Map[15][12];
int answer=0;
int max_answer=0;
int selected[4];
bool isWall(int x,int y){
    return x<0||y<0||x>=H||y>=W;
}
typedef struct _xyd{
    int x;int y;int dis;
    _xyd(int a,int b,int c){
        x=a;y=b;dis=c;
    }
}xyd;

int bomb(int x,int y){
    queue<xyd> q;
    q.push(xyd(x,y,cur_Map[x][y]));
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int broke = 0;
    while(!q.empty()){
        int cx = q.front().x;
        int cy = q.front().y;
        int dis = q.front().dis;
        q.pop();
        if(cur_Map[cx][cy]){
            broke++;
            cur_Map[cx][cy]=0;
        }
        for(int dd = 1; dd < dis; dd++){
            for(int d=0;d<4;d++){
                int nx = cx + (dd * dir[d][0]);
                int ny = cy + (dd * dir[d][1]);
                if(isWall(nx,ny))continue;
                if(cur_Map[nx][ny]==0)continue;
                else{
                    q.push(xyd(nx,ny,cur_Map[nx][ny]));
                    cur_Map[nx][ny] = 0;
                    broke++;
                }
            }
        }
    }    
    return broke;
}
int break_brick(int pos){
    int broke=0;
    //chain bombing
    int flag = 0;
    for(int i=0;i<H;i++){
        if(cur_Map[i][pos]!=0){
            broke+=bomb(i,pos);
            flag=1;
            break;
        }
    }
    if(!flag)return broke;
    //push down after break brick
    rep(j,0,W){
        for(int i=H-1;i>=0;i--){
            if(cur_Map[i][j]==0){
                for(int ii=i-1;ii>=0;ii--){
                    if(cur_Map[ii][j]){
                        cur_Map[i][j]=cur_Map[ii][j];
                        cur_Map[ii][j]=0;
                        break;
                    }
                }
            }
        }
    }
    return broke;
}
void calc(){
    int broke=0;
    memcpy(cur_Map,Map,sizeof Map); 
    for(int i=0;i<N;i++){
        int bricks = break_brick(selected[i]);
        if(bricks==0)break;
        else broke += bricks;
    }
    if(answer<broke)answer = broke;
}
//select all cases(O(W^N))
void select_n(int n){
    if(answer == max_answer)return;
    if(n == N){
        calc();
        return;
    }
    else{
        rep(i,0,W){ 
            selected[n]=i;
            select_n(n+1);
        }
    }
}
void input(){
    cin>>N>>W>>H;
    max_answer=0;
    rep(i,0,H)rep(j,0,W){
        cin>>Map[i][j];
        if(Map[i][j])max_answer++;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        answer = 0;
        select_n(0);
        cout<<"#"<<tc<<" "<<max_answer-answer<<endl;
    }
}