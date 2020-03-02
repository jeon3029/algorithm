#include<bits/stdc++.h>
using namespace std;
int R,C;
int Data[20][20];
int visited[20][20];
int used[26];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int answer;
void input(){
    cin>>R>>C;
    for(int i=0;i<R;i++){
        string s;
        cin>>s;
        for(int j=0;j<C;j++){
            Data[i][j]=s[j]-'A';
        }
    }
}
bool isWall(int x,int y){
    return x<0||y<0||x>=R||y>=C;
}
void dfs(int x,int y,int cnt){
    int val = Data[x][y];
    answer = max(answer,cnt);
    for(int d=0;d<4;d++){
        int nx=x+dir[d][0];
        int ny=y+dir[d][1];
        if(!isWall(nx,ny)){
            int nval = Data[nx][ny];
            if(!visited[nx][ny]){
                if(used[nval]==0){
                    visited[nx][ny]=1;
                    used[nval]=1;
                    dfs(nx,ny,cnt+1); 
                    visited[nx][ny]=0;
                    used[nval]=0;
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        memset(visited,0,sizeof(visited));
        memset(used,0,sizeof(used));
        answer=0;
        int val = Data[0][0];
        visited[0][0]=1;
        used[val]=1;
        dfs(0,0,1);
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
}