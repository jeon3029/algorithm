#include<bits/stdc++.h>
using namespace std;
int dir[8][2] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
class ball{
public:
  int mass;
  int speed;
  int dir;
  int sumd;
  int cnt;
  ball(){
    mass=0;
    speed=0;
    dir=0;
    sumd=0;
    cnt=0;
  }
};
vector<vector<ball>> fireball;
int N,M,K;
void input(){
  cin>>N>>M>>K;
  fireball = vector<vector<ball>>(N,vector<ball>(N,ball()));
  for(int i=0;i<M;i++){
    int r,c,m,s,d;
    cin>>r>>c>>m>>s>>d;
    r--;c--;
    fireball[r][c].cnt=1;
    fireball[r][c].mass=m;
    fireball[r][c].speed=s;
    fireball[r][c].dir=d;
  }
}
void calc(){
  vector<vector<ball>> newball = vector<vector<ball>>(N,vector<ball>(N,ball()));
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(fireball[i][j].cnt==1){
        int nx = i;
        int ny = j;
        for(int d=0;d<fireball[i][j].speed;d++){
          nx+=dir[fireball[i][j].dir][0];
          ny+=dir[fireball[i][j].dir][1];
          if(nx==N)nx=0;
          if(nx<0)nx=N-1;
          if(ny==N)ny=0;
          if(ny<0)ny=N-1;
        }
        if(newball[nx][ny].cnt>=1){
          if(newball[nx][ny].sumd==0){
            if(newball[nx][ny].dir%2==0){
              if(fireball[i][j].dir%2==1){
                newball[nx][ny].sumd=1;
              }
            }
            else{
              if(fireball[i][j].dir%2==0){
                newball[nx][ny].sumd=1;
              }
            }
          }
        }
        newball[nx][ny].cnt++;
        newball[nx][ny].dir=fireball[i][j].dir;
        newball[nx][ny].mass+=fireball[i][j].mass;
        newball[nx][ny].speed+=fireball[i][j].speed;
      }
      else if(fireball[i][j].cnt>1){
        int newmass = fireball[i][j].mass/5;
        int newspeed = fireball[i][j].speed/fireball[i][j].cnt;
        if(newmass==0)continue;
        int d = 0;
        if(fireball[i][j].sumd==0) d = 0;
        else d = 1;
        for(;d<8;d+=2){
          int nx = i;
          int ny = j;
          for(int k=0;k<newspeed;k++){
            nx+=dir[d][0];
            ny+=dir[d][1];
            if(nx==N)nx=0;
            if(nx<0)nx=N-1;
            if(ny==N)ny=0;
            if(ny<0)ny=N-1;
          }
          if(newball[nx][ny].cnt>=1){
            if(newball[nx][ny].sumd==0){
              if(newball[nx][ny].dir%2==0){
                if(d%2==1){
                  newball[nx][ny].sumd=1;
                }
              }
              else{
                if(d%2==0){
                  newball[nx][ny].sumd=1;
                }
              }
            }
          }
          newball[nx][ny].cnt++;
          newball[nx][ny].dir=d;
          newball[nx][ny].mass+=newmass;
          newball[nx][ny].speed+=newspeed;
        }
      }
    }
  }
  fireball = newball;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  input();
  for(int i=0;i<K;i++){
    calc();
  }
  int answer = 0;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(fireball[i][j].cnt==1)
        answer+=fireball[i][j].mass;
      else if(fireball[i][j].cnt>1){
        int t = fireball[i][j].mass/5;
        answer += t*4;
      }
    }
  }
  cout<<answer<<"\n";
}