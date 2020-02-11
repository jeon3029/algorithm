#include<bits/stdc++.h>
using namespace std;
int Map[50][50];
//0 = empty, 1 = garbage, 2 = start 3 = end
int N;
int M;
int curX,curY;
int endX,endY;
vector<vector<pair<int,int> > > GMap;
pair<int,int> answer;//garbage,near_gaebage
void input(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string s;cin>>s;
        for(int j=0;j<M;j++){
            if(s[j]=='.')Map[i][j]=0;
            else if(s[j]=='g')Map[i][j]=1;
            else if(s[j]=='S'){
                curX=i;curY=j;Map[i][j]=2;
            }
            else{
                endX=i;endY=j;Map[i][j]=3;
            }
        }
    }
    answer.first = 987654321;
    answer.second = 987654321;
    for(int i=0;i<N;i++){
        vector<pair<int,int> >temp;
        for(int j=0;j<M;j++){
            temp.push_back(answer);
        }
        GMap.push_back(temp);
    }
}
bool isWall(int x,int y){
    return x<0||y<0||x>=N||y>=M;
}
int is_around(int x,int y){
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    for(int d=0;d<4;d++){
        int nextX = x+dir[d][0];
        int nextY = y+dir[d][1];
        if(!isWall(nextX,nextY)){
            if(Map[nextX][nextY]==1 ){
                return 1;
            }     
        }
    }
    return 0;
}

void dfs(int x,int y,int garbage,int near_garbage,vector<vector<int> > visited){
    visited[x][y] = 1;
    if(GMap[x][y].first<garbage){
        return;
    }
    else if(GMap[x][y].first==garbage && GMap[x][y].second<near_garbage){
        return;
    }
    GMap[x][y].first = garbage;
    GMap[x][y].second = near_garbage;

    if(answer.first==0 && answer.second==0)return;
    //if finished
    if(Map[x][y]==3){
        if(garbage<answer.first){
            answer.first = garbage;
            answer.second = near_garbage;
        }
        else if(garbage==answer.first && near_garbage<answer.second){
            answer.second = near_garbage;
        }
        return;
    }
    //garbage > max garbage -> return
    if(garbage>answer.first){
        return;
    }
    //current garbage check
    int flag = 0;
    if(Map[x][y]==1){
        garbage++;
        flag = 1;
    }
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    if (flag==0) near_garbage += is_around(x,y);
    //next move
    for(int d=0;d<4;d++){
        int nextX = x+dir[d][0];
        int nextY = y+dir[d][1];
        if(!isWall(nextX,nextY)){
            if(visited[nextX][nextY]==0){
                dfs(nextX,nextY,garbage,near_garbage,visited);
            }    
        }
    }
    visited[x][y] = 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    vector<vector<int> > visited(N,vector<int>(M,0));
    
    if(endX>curX && endY>curY){
        int t=0;
        for(int i=curX;i<=endX;i++){
            for(int j=curY;j<=endY;j++){
                if(Map[i][j]==1)t++;
            }
        }
        answer.first = t;
    }
    else if(endX>curX && endY<curY){
        int t=0;
        for(int i=curX;i<=endX;i++){
            for(int j=curY;j>=endY;j--){
                if(Map[i][j]==1)t++;
            }
        }
        answer.first = t;
    }
    else if(endX<curX && endY>curY){
        int t=0;
        for(int i=curX;i>=endX;i--){
            for(int j=curY;j<=endY;j++){
                if(Map[i][j]==1)t++;
            }
        }
        answer.first = t;
    }
    else if(endX<curX && endY<curY){
        int t=0;
        for(int i=curX;i>=endX;i--){
            for(int j=curY;j>=endY;j--){
                if(Map[i][j]==1)t++;
            }
        }
        answer.first = t;
    }
    dfs(curX,curY,0,0,visited);
    cout<<answer.first<<" "<<answer.second<<"\n";
}