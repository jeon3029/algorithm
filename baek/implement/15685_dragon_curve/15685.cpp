#include<bits/stdc++.h>
using namespace std;
const int SZ=100;
int Data[20][4];
int Draw[SZ+1][SZ+1];
int visited[SZ+1][SZ+1];
int N;
void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>Data[i][0]>>Data[i][1]>>Data[i][2]>>Data[i][3];
    }
}
bool isWall(int x,int y){
    return x<0||y<0||x>=101||y>=101;
}
void draw(int x,int y,int d,int g){
    vector<int> dir;
    dir.push_back(d);
    for(int i=0;i<g;i++){
        int len=dir.size();
        for(int j=0;j<len;j++){
            dir.push_back((dir[len-1-j]+1)%4);
        }
    }
    int nx=x;int ny=y;
    Draw[nx][ny]=1;
    int next[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
    for(int i=0;i<dir.size();i++){
        int curD = dir[i];
        nx+=next[curD][0];
        ny+=next[curD][1];
        if(!isWall(nx,ny)){
            Draw[nx][ny]=1;
        }
    }
}
bool check(int x,int y){
    return(Draw[x][y]==1 && Draw[x+1][y]==1 && Draw[x][y+1]==1 && Draw[x+1][y+1]==1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    for(int i=0;i<N;i++){
        draw(Data[i][0],Data[i][1],Data[i][2],Data[i][3]);
    }
    int answer=0;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(check(i,j)){
                answer++;
            }
        }
    }
    cout<<answer<<"\n";
}