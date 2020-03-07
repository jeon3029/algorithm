#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int N;
int Data[20][20];
pi sp;
int answer;
int dir[4][2]={{-1,-1},{-1,1},{1,1},{1,-1}};
int visited[20][20];
int used[101];
void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>Data[i][j];
        }
    }
}
bool isWall(int x,int y){
    return x<0||y<0||x>=N||y>=N;
}
void dfs(int x,int y,int len,int cnt_d,int d,int r,int c){//cd = d count, d = dir
    if(x==sp.first && y==sp.second && cnt_d==3){
        if(answer==-1) answer=len;
        else answer = max(answer,len);
        return;
    }
    if(cnt_d>3)return;
    d--;
    for(int i=0;i<2;i++){//i=0 : 그대로, i=1 : 방향 틀기
        d=(d+1)%4;
        int nx = x+dir[d][0];
        int ny = y+dir[d][1];
        if(i==1&&cnt_d==2&&len+3-r-c!=r)continue;//직사각형 안되면 방향 틀지 않는다
        if(!isWall(nx,ny)){
            if(!visited[nx][ny] && !used[Data[nx][ny]]){
                if(i==1){
                    if(cnt_d ==0){
                        r = len+1;
                    }
                    if(cnt_d==1){
                        c = len+2-r;
                        if(answer!=-1 && (len*2)<answer)return;
                    }
                }
                visited[nx][ny]=1;
                used[Data[nx][ny]]=1;
                dfs(nx,ny,len+1,cnt_d+i,d,r,c);
                used[Data[nx][ny]]=0;
                visited[nx][ny]=0;
            }
            if(nx==sp.first && ny==sp.second && cnt_d+i==3){
                dfs(nx,ny,len+1,cnt_d+i,d,r,c);
            }
        }    
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        answer=-1;
        for(int i=2;i<N;i++){
            for(int j=1;j<N-1;j++){
                sp.first=i;sp.second=j;
                used[Data[i][j]]=1;
                dfs(i,j,0,0,0,0,0);
                used[Data[i][j]]=0;
            }
        }
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
}