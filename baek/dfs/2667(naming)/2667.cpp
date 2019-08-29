#include<bits/stdc++.h>
#define MAX 27
using namespace std;
int check[MAX][MAX]; // 1,1 ~ 25,25
int data[MAX][MAX]; //1,1 ~ 25,25
int cnt=0;
int n;
void dfs(int x,int y){
  check[x][y]=cnt;
  if(data[x+1][y]==1 && check[x+1][y]==0){
    dfs(x+1,y);
  }
  if(data[x][y+1]==1 && check[x][y+1]==0){
    dfs(x,y+1);
  }
  if(data[x-1][y]==1 && check[x-1][y]==0){
    dfs(x-1,y);
  }
  if(data[x][y-1]==1 && check[x][y-1]==0){
    dfs(x,y-1);
  }
  return;
}
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    string s;cin>>s;
    for(int j=0;j<n;j++){
      int x = atoi(s.substr(j,1).c_str());
      data[i+1][j+1] = x;
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(data[i][j]==1 && check[i][j]==0){
        cnt++;//room number
        dfs(i,j);
      }
    }
  }
  cout<<cnt<<endl;
  vector<int> data(cnt,0);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(check[i][j]!=0){
        data[check[i][j]-1]++;
      }
    }
  }
  sort(data.begin(),data.begin()+cnt);
  for(int i=0;i<cnt;i++){
    cout<<data[i]<<endl;
  }
  return 0;
}
