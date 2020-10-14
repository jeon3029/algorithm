#include<bits/stdc++.h>
using namespace std;
int N,M,K;
int Data[1000][1000];
int visited[1000][1000][11];
void input(){
  cin>>N>>M>>K;
  for(int i=0;i<N;i++){
    string s;
    cin>>s;
    for(int j=0;j<M;j++){
      Data[i][j] = s[j]-'0';
    }
  }
}
const int INF = 987654321;
int answer = INF;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
bool isWall(int x,int y){
  return x<0||y<0||x>=N||y>=M;
}
void bfs(){
  queue<pair<int,pair<int,int>>> q;
  q.push({K,{0,0}});
  visited[0][0][K]=1;
  while(!q.empty()){
    int x = q.front().second.first;
    int y = q.front().second.second;
    int cnt = q.front().first;
    
    q.pop();
    for(int d=0;d<4;d++){
      int nx = x + dir[d][0];
      int ny = y + dir[d][1];
      if(isWall(nx,ny))continue;
      if(!visited[nx][ny][cnt] && Data[nx][ny]==0){
        visited[nx][ny][cnt] = visited[x][y][cnt]+1;
        q.push({cnt,{nx,ny}});
      }
      else if(cnt>0 && Data[nx][ny]==1 && !visited[nx][ny][cnt-1]){
        visited[nx][ny][cnt-1] = visited[x][y][cnt]+1;
        q.push({cnt-1,{nx,ny}});
      }
    }
  }
  for(int i=0;i<=K;i++){
    if(visited[N-1][M-1][i]==0)continue;
    if(visited[N-1][M-1][i]<answer)answer = visited[N-1][M-1][i];
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  input();
  bfs();
  if(answer==INF)cout<<"-1\n";
  else cout<<answer<<"\n";
}