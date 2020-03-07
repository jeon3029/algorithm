
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
void dfs(int x,int y,int len,int cnt_d,int d){//cd = d count, d = dir
    if(x==sp.first && y==sp.second && cnt_d==3){
        if(answer==-1)
        answer=len;
        else answer = max(answer,len);
        return;
    }
    if(cnt_d>3)return;
    d--;
    for(int i=0;i<2;i++){//그대로, 방향 틀기
        d=(d+1)%4;
        int nx = x+dir[d][0];
        int ny = y+dir[d][1];
        if(!isWall(nx,ny)){
            if(!visited[nx][ny] && !used[Data[nx][ny]]){
                visited[nx][ny]=1;
                used[Data[nx][ny]]=1;
                dfs(nx,ny,len+1,cnt_d+i,d);
                used[Data[nx][ny]]=0;
                visited[nx][ny]=0;
            }
            if(nx==sp.first && ny==sp.second && cnt_d+i==3){
                dfs(nx,ny,len+1,cnt_d+i,d);
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
        for(int i=0;i<N;i++){
            for(int j=1;j<N-1;j++){
                sp.first=i;sp.second=j;
                for(int d=0;d<4;d++){
                    memset(used,0,sizeof(used));
                    memset(visited,0,sizeof(visited));
                    used[Data[i][j]]=1;
                    dfs(i,j,0,0,d);
                }
            }
        }
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
}