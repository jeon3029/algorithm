#include<bits/stdc++.h>
using namespace std;

int dir[8][2] = {{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
class Shark{
  public:
  int number;
  int dir;
  Shark(int a,int  b){
    number=a;dir=b;
  }
};
vector<vector<Shark>> Data;
int answer = 0;
void input(){
  for(int i=0;i<4;i++){
    vector<Shark> s;
    for(int j=0;j<4;j++){
      int a,b;
      cin>>a>>b;
      b--;
      s.push_back(Shark(a,b));
    }
    Data.push_back(s);
  }
}
bool isWall(int x,int y){
  return x<0||y<0||x>=4||y>=4;
}
void move_fish(vector<vector<Shark>> &cur_map,int shark_x,int shark_y){
  for(int num=1;num<=16;num++){
    int x,y;
    bool find = false;
    for(int i=0;i<4;i++){//find number pos
      for(int j=0;j<4;j++){
        if(cur_map[i][j].number==num){
          x=i;y=j;find=true;break;
        }
      } if(find)break;
    }
    if(!find)continue;
    int curD = cur_map[x][y].dir;
    for(int d=0;d<8;d++){
      int nx = x + dir[(curD+d)%8][0];
      int ny = y + dir[(curD+d)%8][1];
      if(isWall(nx,ny))continue;
      if(nx==shark_x && ny == shark_y)continue;
      else{
        // swap(cur_map[x][y],cur_map[nx][ny]);
        // int tempD = cur_map[x][y].dir;
        int tempD = (curD+d)%8;
        int tempN = cur_map[x][y].number;
        cur_map[x][y].dir = cur_map[nx][ny].dir;
        cur_map[x][y].number = cur_map[nx][ny].number;
        cur_map[nx][ny].dir = tempD;
        cur_map[nx][ny].number = tempN;
        break;
      }
    }
  }
}
void dfs(vector<vector<Shark>> curData,int shark_x,int shark_y,int cur_answer){
  if(answer<cur_answer)answer=cur_answer;
  // cout<<shark_x<<" , "<<shark_y<<"\n";
  move_fish(curData,shark_x,shark_y);
  bool isEat = false;
  int cx = shark_x;
  int cy = shark_y;
  while(1){
    int sd = curData[shark_x][shark_y].dir;
    int nx = cx + dir[sd][0];
    int ny = cy + dir[sd][1];
    if(isWall(nx,ny))break;
    if(curData[nx][ny].number==0){
      cx = nx;
      cy = ny;
      continue;
    }
    // cout<<"cur : "<<shark_x<<" , "<<shark_y<<"\n";
    // cout<<"next : "<<sd<<" : "<<nx<<" , "<<ny<<"\n";

    int temp = curData[nx][ny].number;
    curData[nx][ny].number = 0;
    dfs(curData,nx,ny,cur_answer +temp);
    curData[nx][ny].number = temp;

    cx = nx;
    cy = ny;
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  input();
  int score = Data[0][0].number;
  Data[0][0].number = 0;
  dfs(Data,0,0,score);
  cout<<answer<<"\n";
}