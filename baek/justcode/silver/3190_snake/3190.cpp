/**
 * @author [jeon3029]
 * @email [jeon3029@naver.com]
 * @create date 2020-04-09 09:25:24
 * @desc [구현문제]
 */
#include<bits/stdc++.h>
using namespace std;
int Map[100][100];//0:empty 1:apple 2:snake
int N;
int chdir[10001];//1:Right, 2:left, 0:none
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void input(){
    memset(Map,0,sizeof Map);
    memset(chdir,0,sizeof chdir);

    cin>>N;
    int k;cin>>k;
    for(int i=0;i<k;i++){
        int a,b;cin>>a>>b;
        Map[a-1][b-1]=1;
    }
    cin>>k;
    for(int i=0;i<k;i++){
        int t;char c;
        cin>>t>>c;
        if(c=='D')chdir[t]=1;
        else chdir[t]=2;
    }
}
bool isWall(int x,int y){
    return x<0||y<0||x>=N||y>=N||Map[x][y]==2;
}
typedef struct s_info{
    int x;int y;
    s_info(int a,int b){
        x=a;y=b;
    }
}Snake;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    int time;
    int cdir = 0; //동,남,서,북 - 현재 방향
    int cx=0,cy=0;
    queue<Snake> q; // 방향 저장하면서 이동
    q.push(Snake(0,0)); 
    for(time=1;;time++){
        int nx = cx+dir[cdir][0];
        int ny = cy+dir[cdir][1];
        if(isWall(nx,ny))break;
        if(Map[nx][ny]==0){//not apple
            Snake ep = q.front();
            Map[ep.x][ep.y]=0;
            q.pop();
        }
        q.push(Snake(nx,ny));
        cx=nx;cy=ny;
        Map[cx][cy]=2;
        if(chdir[time]==1)cdir=(cdir+1)%4;
        else if(chdir[time]==2)cdir=(cdir+3)%4;
    }  
    cout<<time<<"\n";
}