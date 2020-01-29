#include<bits/stdc++.h>
#define MAX 100001
using namespace std;

int n,m;
int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int>  > SCC;
vector<int> result;
stack<int> s;
int group[MAX];
bool inDegree[MAX];

int dfs(int x){
  d[x] = ++id;
  s.push(x);
  int parent=d[x];
  for(int i=0;i<a[x].size();i++){
    int y=a[x][i];
    if(d[y]==0)parent = min(parent,dfs(y));
    else if(!finished[y])parent = min(parent,d[y]);
  }
  //SCC찾은 경우
  if(parent == d[x]){
    vector<int> scc;
    while(1){
      int t = s.top();s.pop();
      scc.push_back(t);
      group[t] = SCC.size()+1;
      finished[t]=true;
      if(t==x)break;
    }
    SCC.push_back(scc);
  }
  return parent;
}
int main(void){
  int T;
  cin>>T;
  while(T--){
    cin>>n>>m;
    SCC.clear();
    fill(d,d+MAX,0);
    fill(finished,finished+MAX,0);
    fill(inDegree,inDegree+MAX,false);
    result.clear();

    for(int i=1;i<=n;i++)a[i].clear();
    for(int i=0;i<m;i++){
      int x,y;
      cin>>x>>y;
      a[x+1].push_back(y+1);
    }
    for(int i=1;i<=n;i++){
      if(d[i]==0)dfs(i);
    }
    for(int i=1;i<=n;i++){
      for(int j=0;j<a[i].size();j++){
        int y = a[i][j];
        if(group[i]!=group[y]){
          inDegree[group[y]]=true;
        }
      }
    }
    int count=0;
    for(int i=0;i<SCC.size();i++){
      if(inDegree[i+1]==0){
        count++;
        for(int j=0;j<SCC[i].size();j++){
          result.push_back(SCC[i][j]-1);
        }
      }
    }
    sort(result.begin(),result.end());
    if(count!=1){
      cout<<"Confused"<<endl<<endl;
    }
    else{
      for(int i=0;i<result.size();i++)cout<<result[i]<<endl;
      cout<<endl;
    }
  }
  return 0;
}
