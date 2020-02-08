#include<bits/stdc++.h>
using namespace std;
int Map[50][50];
int N,M;
void input(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        for(int j=0;j<M;j++){
            if(s[j]=='L')
                Map[i][j]=1;
            else
                Map[i][j]=0;
        }
    }
}
bool isWall(int x,int y){
    return x<0||x>=N||y<0||y>=M;
}
int calc(int x,int y){
    queue<pair<pair<int,int>,int> > q;//x,y,time
    vector<vector<int> > vis(N,vector<int>(M,0));
    q.push(make_pair(make_pair(x,y),1));
    int answer = 0;
    while(!q.empty()){
        int curX = q.front().first.first;
        int curY = q.front().first.second;
        int curT = q.front().second;
        if(vis[curX][curY]==0){
            vis[curX][curY]=curT;
        }
        else if(vis[curX][curY]>curT){
            vis[curX][curY] = curT;
        }
        q.pop();
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int d=0;d<4;d++){
            int nextX = curX+dir[d][0];
            int nextY = curY+dir[d][1];
            if(!isWall(nextX,nextY)){
                if(Map[nextX][nextY]==1){
                    if(vis[nextX][nextY]==0){
                        vis[nextX][nextY]=curT+1;
                        q.push(make_pair(make_pair(nextX,nextY),curT+1));  
                    }
                    else if(vis[nextX][nextY]>curT+1){
                        vis[nextX][nextY]=curT+1;
                        q.push(make_pair(make_pair(nextX,nextY),curT+1));  
                    }
                }
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(answer<vis[i][j])answer=vis[i][j];
        }
    }
     return answer-1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    int max_distance = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(Map[i][j]==1){
                int temp = calc(i,j);
                if(temp>max_distance)max_distance=temp;
            }
        }
    }
    cout<<max_distance<<endl;
}