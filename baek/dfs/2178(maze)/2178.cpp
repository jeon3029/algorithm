#include<bits/stdc++.h>
#define MAX 102
using namespace std;
int n,m;
int data[MAX][MAX];
int D[MAX][MAX];
void dfs(int x,int y){
  if(x==n && y==m)return;
  if(data[x+1][y]==1){
    if(D[x][y]+1<D[x+1][y]){
      D[x+1][y] = D[x][y]+1;
      dfs(x+1,y);
    }
  }
  if(data[x][y+1]==1){
    if(D[x][y]+1<D[x][y+1]){
      D[x][y+1] = D[x][y]+1;
      dfs(x,y+1);
    }
  }
  if(data[x-1][y]==1){
    if(D[x][y]+1<D[x-1][y]){
      D[x-1][y] = D[x][y]+1;
      dfs(x-1,y);
    }
  }
  if(data[x][y-1]==1){
    if(D[x][y]+1<D[x][y-1]){
      D[x][y-1] = D[x][y]+1;
      dfs(x,y-1);
    }
  }
}
int main(){
  cin>>n>>m;
  memset(data,-1,sizeof(data));
  //fill(D[0],D[0]+sizeof(D),987654321);
  for(int i=0;i<n;i++){
    fill(D[i+1],D[i+1]+MAX,987654321);
    string s;cin>>s;
    for(int j=0;j<m;j++){
      int x = atoi(s.substr(j,1).c_str());
      data[i+1][j+1]=x;
    }
  }
  D[1][1]=1;
  dfs(1,1);
  cout<<D[n][m]<<endl;
  /*for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cout<<D[i+1][j+1]<<" ";
    }
    cout<<endl;
  }*/

  return 0;
}
