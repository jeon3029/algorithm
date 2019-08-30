#include<bits/stdc++.h>
#define MAX 1001
using namespace std;

vector<int> data[MAX];
int n,m,v;
int check[MAX];

void dfs(int x){
  if(check[x]==0)printf("%d ",x);
  if(check[x]==1)return;
  check[x]=1;
  for(int i=0;i<data[x].size();i++){
    dfs(data[x][i]);
  }
}
void bfs(int x){
  queue<int> q;
  for(int i=0;i<data[x].size();i++){
    q.push(data[x][i]);
  }
  if(check[x]==0)printf("%d ",x);
  check[x]=1;
  while(!q.empty()){
    int k = q.front();q.pop();
    if(check[k]==0)printf("%d ",k);
    check[k]=1;
    for(int i=0;i<data[k].size();i++){
      if(check[data[k][i]]==0) q.push(data[k][i]);
    }
  }
  cout<<'\n';
}
int main(){
  cin>>n>>m>>v;
  for(int i=0;i<m;i++){
    int x,y;scanf("%d%d",&x,&y);
    data[x].push_back(y);
    data[y].push_back(x);
  }
  for(int i=1;i<=n;i++){
    sort(data[i].begin(),data[i].end());
  }
  dfs(v);cout<<'\n';
  fill(check,check+n+1,0);
  bfs(v);
  return 0;
}
