#include<bits/stdc++.h>
using namespace std;
int N;
vector<vector<char>> Map;
void input(){
  cin>>N;
  for(int i=0;i<N;i++){
    string s;
    cin>>s;
    vector<char> temp;
    for(int j=0;j<N;j++){
      temp.push_back(s[j]);
    }
    Map.push_back(temp);
  }
}
bool isWall(int x,int y){
  return x<0||y<0||x>=N||y>=N;
}
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int calc(){
  int max_num = 0;
  for(int i=0;i<N;i++){
    int max_row = 1;
    int temp = 1;
    for(int j=1;j<N;j++){
      if(Map[i][j]==Map[i][j-1]){
        temp++;
        if(temp>max_row)max_row = temp;
      }
      else{
        temp = 1;
      }
    }
    if(max_row>max_num)max_num = max_row;
  }
  for(int j=0;j<N;j++){
    int max_col = 1;
    int temp = 1;
    for(int i=1;i<N;i++){
      if(Map[i][j]==Map[i-1][j]){
        temp++;
        if(temp>max_col)max_col = temp;
      }
      else{
        temp = 1;
      }
    }
    if(max_col>max_num)max_num = max_col;
  }
  return max_num;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  input();
  int answer = 0;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      for(int d=0;d<4;d++){
        int nx = i+dir[d][0];
        int ny = j+dir[d][1];
        if(!isWall(nx,ny)){
          swap(Map[i][j],Map[nx][ny]);
          int temp = calc();
          if(temp>answer){
            answer = temp;
            // cout<<answer<<" : "<<i<<","<<j<<"/"<<d<<"\n";
          }
          swap(Map[i][j],Map[nx][ny]);
        }
      }
    }
  }
  cout<<answer<<"\n";
}