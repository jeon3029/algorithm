#include<bits/stdc++.h>
using namespace std;
int N,M,K;

pair<int,int> Scent[20][20];//number(1~M),time(1~...)
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
class Shark{
public:
  int x;
  int y;
  int cur_d;
  int dir_p[4][4];
  bool valid;
  Shark(){
  }
};
vector<Shark> allShark;
int sharkData[20][20];
void input(){
  cin>>N>>M>>K;
  allShark = vector<Shark>(M,Shark());
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      int a;
      cin>>sharkData[i][j];
      if(sharkData[i][j]){
        Shark s;
        s.x=i;s.y=j;
        s.valid=true;
        allShark[sharkData[i][j]-1] = s;
      }
    }
  }
  //direction
  for(int i=0;i<M;i++){
    int d;cin>>d;
    allShark[i].cur_d = d-1;
  }
  for(int i=0;i<M;i++){
    for(int j=0;j<4;j++){
      int a,b,c,d;
      cin>>a>>b>>c>>d;
      allShark[i].dir_p[j][0] = a-1;
      allShark[i].dir_p[j][1] = b-1;
      allShark[i].dir_p[j][2] = c-1;
      allShark[i].dir_p[j][3] = d-1;
    }
  }
}
bool isWall(int x,int y){
  return x<0||y<0||x>=N||y>=N;
}
int calc(){
  for(int time=1;time<=1000;time++){
    //냄새뿌리기
    for(int i=0;i<M;i++){
      if(allShark[i].valid==false)continue;
      int x = allShark[i].x;
      int y = allShark[i].y;
      Scent[x][y].first = i+1;
      Scent[x][y].second = time;
    }
    //이동하기
    for(int i=0;i<M;i++){
      if(allShark[i].valid==false)continue;

      int curd = allShark[i].cur_d;
      int x = allShark[i].x;
      int y = allShark[i].y;
      //빈칸있나 확인
      bool empty = false;
      for(int d=0;d<4;d++){
        int ndir = allShark[i].dir_p[curd][d];
        int nx = x + dir[ndir][0];
        int ny = y + dir[ndir][1];
        if(isWall(nx,ny))continue;
        if(Scent[nx][ny].first==0 || time - Scent[nx][ny].second>=K ){//빈 경우
          empty=true;
          if(sharkData[nx][ny]!=0 && sharkData[nx][ny]<i+1){//이미 먼저 자리 차지하고있는 경우
            allShark[i].valid=false;
            sharkData[x][y] = 0;
            break;
          }
          else{
            sharkData[x][y] = 0;
            sharkData[nx][ny] = i+1;
            allShark[i].x = nx;
            allShark[i].y = ny;
            allShark[i].cur_d = ndir;
            break;
          }
        }
      }
      //빈칸 없으면 자기 냄새 칸으로
      if(!empty){
        for(int d=0;d<4;d++){
          int ndir = allShark[i].dir_p[curd][d];
          int nx = x + dir[ndir][0];
          int ny = y + dir[ndir][1];
          if(isWall(nx,ny))continue;
          if(Scent[nx][ny].first==i+1){//자기 냄새
            sharkData[x][y] = 0;
            sharkData[nx][ny] = i+1;
            allShark[i].x = nx;
            allShark[i].y = ny;
            allShark[i].cur_d = ndir;
            break;
          }
        }
      }
    }
    //1번만 남았는지 체크
    int count = 0;
    for(int j=0;j<M;j++){
      if(allShark[j].valid)count++;
    }
    if(count==1){
      return time;
    }
  }
  return -1;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  input();
  cout<<calc()<<"\n";
}