#include<bits/stdc++.h>
using namespace std;
int N,M;
int Data[20][20];
int taxi_x,taxi_y;
int Person[20][20];
int fuel;
int answer;
class infoP{
  public:
  int x;int y;int fx;int fy;
  infoP(){
  }
};
vector<infoP> infoPerson;
void input(){
  cin>>N>>M>>fuel;
  infoPerson = vector<infoP>(M,infoP());
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>Data[i][j];
    }
  }
  cin>>taxi_x>>taxi_y;taxi_x--;taxi_y--;
  for(int i=1;i<=M;i++){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    Person[a-1][b-1] = i;
    infoPerson[i-1].x=a-1;
    infoPerson[i-1].y=b-1;
    infoPerson[i-1].fx=c-1;
    infoPerson[i-1].fy=d-1;
  }
}
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool isWall(int x,int y){
  return x<0||y<0||x>=N||y>=N;
}
const int INF = 987654321;
typedef struct pdis{
  int p;int dis;
}Pdis;
Pdis findPerson(int x,int y){
  int visited[N][N];
  memset(visited,0,sizeof visited);
  queue<pair<pair<int,int>,int>> q;
  q.push({{x,y},1});
  while(!q.empty()){
    int cx = q.front().first.first;
    int cy = q.front().first.second;
    int dis = q.front().second;
    q.pop();
    visited[cx][cy]=dis;
    for(int d=0;d<4;d++){
      int nx = cx+dir[d][0];
      int ny = cy+dir[d][1];
      if(isWall(nx,ny) || Data[nx][ny]==1)continue;
      if(!visited[nx][ny]){
        visited[nx][ny]=dis+1;
        q.push({{nx,ny},dis+1});
      }
      else if(visited[nx][ny]>dis+1){
        visited[nx][ny]=dis+1;
        q.push({{nx,ny},dis+1});
      }
    }
  }
  int smallDistance = INF;
  int personNo = 0;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(Person[i][j]>=1 && Person[i][j]<=M){
        if(visited[i][j]<smallDistance){
          smallDistance = visited[i][j];
          personNo = Person[i][j];
        }
      }
    }
  }
  Pdis ret;
  if(smallDistance==INF)smallDistance=0;
  ret.p = personNo;
  ret.dis = smallDistance-1;
  return ret;
}
int getDis(int p){
  int x = infoPerson[p-1].x;
  int y = infoPerson[p-1].y;
  int fx = infoPerson[p-1].fx;
  int fy = infoPerson[p-1].fy;
  int visited[N][N];
  memset(visited,0,sizeof visited);
  queue<pair<pair<int,int>,int>> q;
  q.push({{x,y},1});
  while(!q.empty()){
    int cx = q.front().first.first;
    int cy = q.front().first.second;
    int dis = q.front().second;
    q.pop();
    visited[cx][cy]=dis;
    for(int d=0;d<4;d++){
      int nx = cx+dir[d][0];
      int ny = cy+dir[d][1];
      if(isWall(nx,ny) || Data[nx][ny]==1)continue;
      if(!visited[nx][ny]){
        visited[nx][ny]=dis+1;
        q.push({{nx,ny},dis+1});
      }
      else if(visited[nx][ny]>dis+1){
        visited[nx][ny]=dis+1;
        q.push({{nx,ny},dis+1});
      }
    }   
  }
  return visited[fx][fy]-1;
}
void solve(){
  for(int i=0;i<M;i++){ 
    //손님, 거리 찾기
    Pdis p = findPerson(taxi_x,taxi_y);//person,distance
    //연료계산
    if(fuel<p.dis || p.dis==-1){
      answer=-1;
      return;
    }
    fuel-=p.dis;
    int dis = getDis(p.p);
    if(fuel<dis || dis==-1){
      answer=-1;
      return;
    }
    else{
      fuel+=dis;
      taxi_x = infoPerson[p.p-1].fx;
      taxi_y = infoPerson[p.p-1].fy;
      Person[infoPerson[p.p-1].x][infoPerson[p.p-1].y]=0;
    }
  }
  answer = fuel;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  input();
  solve();
  cout<<answer<<"\n";
}