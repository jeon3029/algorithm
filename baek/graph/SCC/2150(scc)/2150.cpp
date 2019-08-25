#include<bits/stdc++.h>
#define MAX 10002
using namespace std;

vector<int> a[MAX];
int V,E;
stack<int> s;
int visited[MAX];
bool finished[MAX];
int id;
vector<vector<int>  > SCC;//results

int dfs(int x){
  visited[x] = ++id;
  s.push(x);

  int parent = visited[x];

  for(int i=0;i<a[x].size();i++){
    int y=a[x][i];
    if(!visited[y])parent = min(parent,dfs(y));
    else if(!finished[y])parent = min(parent,visited[y]);
  }
  if(parent == visited[x]){
    vector<int> scc;
    while(1){
      int t=s.top();
      s.pop();
      scc.push_back(t);
      finished[t] = true;
      if(t==x)break;
    }
    SCC.push_back(scc);
  }
  return parent;
}
int main(void){
  cin>>V>>E;
  while(E--){
    int x,y;
    cin>>x>>y;
    a[x].push_back(y);
  }
  for(int i=1;i<=V;i++){
    if(!visited[i]){
      dfs(i);
    }
  }
  cout<<SCC.size()<<endl;

  for(int i=0;i<SCC.size();i++){
    sort(SCC[i].begin(),SCC[i].end());
  }
  sort(SCC.begin(),SCC.end());
  for(int i=0;i<SCC.size();i++){

    for(int j=0;j<SCC[i].size();j++){
      cout<<SCC[i][j]<<" ";
    }
    cout<<"-1"<<endl;
  }
  return 0;
}
