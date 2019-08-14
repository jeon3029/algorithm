#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
char map[10][11];
struct INFO{
   int ry,rx,by,bx,count;
};
INFO start;
int bfs(){
  int visited[10][10][10][10] = {0,};
  int dx[4] = {1,-1,0,0}; int dy[4] = {0,0,1,-1}; //east west south north
  visited[start.ry][start.rx][start.by][start.bx] = 1;
  queue<INFO> q;
  q.push(start);
  //cout<<start.ry<<start.rx<<start.by<<start.bx<<start.count;
  int ret = -1;
  while(!q.empty()){
    INFO cur = q.front(); q.pop();
  //  cout<<endl<<cur.count<<endl;
    if(cur.count > 10) break;
    if(map[cur.ry][cur.rx] =='O' && map[cur.by][cur.bx]!='O'){
      ret = cur.count;
      break;
    }

    for(int dir = 0; dir<4;++dir){
      int next_rx = cur.rx;
      int next_ry = cur.ry;
      int next_bx = cur.bx;
      int next_by = cur.by;
      
      while(1){
        //cout<<"1";
        if(map[next_ry][next_rx] != '#' && map[next_ry][next_rx]!='O'){
          next_ry += dy[dir]; next_rx += dx[dir];
        }
        else {
          if(map[next_ry][next_rx]=='#'){
            next_ry-=dy[dir];next_rx-=dx[dir];
          }
          break;
        }
      }
      while(1){
        if(map[next_by][next_bx] != '#' && map[next_by][next_bx]!='O'){
          next_by += dy[dir]; next_bx += dx[dir];
        }

        else {
          if(map[next_by][next_bx]=='#'){
            next_by-=dy[dir];next_bx-=dx[dir];
          }
          break;
        }
      }
      if(next_rx == next_bx && next_ry == next_by){
        int rd = abs(next_ry-cur.ry) + abs(next_rx-cur.rx);
        int bd = abs(next_by-cur.by) + abs(next_bx-cur.bx);
        if(rd>bd){
          next_ry-=dy[dir];next_rx-=dx[dir];
        }
        else{
          next_by-=dy[dir];next_bx-=dx[dir];
        }
      }
      if(visited[next_ry][next_rx][next_by][next_bx] ==0){
        visited[next_ry][next_rx][next_by][next_bx]=1;
        INFO next;
        next.ry = next_ry; next.rx = next_rx; next.by = next_by; next.bx = next_bx;
        next.count = cur.count+1;
        q.push(next);
      }

    }
  }
  return ret;
}
int main(void){
  int n,m;
  cin>>n>>m;
 // cout<<"nmdone"<<endl;
  for (int i=0;i<n;i++){
    //cin>>map[i];
    scanf("%s",map[i]);
  }
  //cout<<"scan done"<<endl;
  //start pos
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(map[i][j]=='R'){
        start.ry=i;start.rx=j;
//        cout<<"r"<<i<<j;
      }
      if(map[i][j]=='B'){
        start.by=i;start.bx=j;
//        cout<<"b"<<i<<j;
      }
    }
  }
//  cout<<endl;
  start.count = 0; 
  int ret = bfs();
  cout<<ret<<endl;
  return 0;
}
