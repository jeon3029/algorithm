//비트연산
#include<bits/stdc++.h>
using namespace std;
#define N 4
int Map[4][4];
int check[3125000];
int answer=0;
void input(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>Map[i][j];
        }
    }
}
bool isWall(int x,int y){
    return x<0||y<0||x>=N||y>=N;
}
void calc(int x,int y,int s,int len){//dfs
    if(len==7){
        int a = s / 32;
        int b = s % 32;
        if(!(check[a]&0x1<<b)){
            check[a] |= 0x1<<b;
            answer++;
        }
        return;
    }
    s = s*10 + Map[x][y];
    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    for(int d=0;d<4;d++){
        int nextX = x + dir[d][0];
        int nextY = y + dir[d][1];
        if(!isWall(nextX,nextY)){
            calc(nextX,nextY,s,len+1);
        }
    }
    s/=10;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    for(int tt=1;tt<=t;tt++){
        input();
        answer=0;
        memset(check,0,sizeof(check));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                calc(i,j,0,0);
            }
        }
        cout<<"#"<<tt<<" "<<answer<<"\n";
    }
}