#include <iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define MAX 10001


using namespace std;

int id;//고유값
int d[MAX];// 각 노드(visited 처럼 활용) 0이면 방문하지 않은 것
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int>  > SCC;
stack<int> s;

int dfs(int x){
  d[x] = ++id;
  s.push(x);

  int parent = d[x];
  for(int i=0;i<a[x].size();i++){
    int y = a[x][i];
    //노드 돌면서 부모를 더 작은 것으로 갱신
    if(d[y] == 0) parent = min(parent,dfs(y));
    //dfs안끝난 노드의 경우 d[y] !=0 이고 parent 와 d[y] 비교하는 이유는 잘 모르겠다...
    else if(!finished[y])parent = min(parent,d[y]);
  }
  if(parent == d[x]){//scc찾은 경우  : 부모가 자기 자신인 경우
    vector<int> scc;
    while(1){
      int t = s.top();
      s.pop();
      scc.push_back(t);
      finished[t] = true;
      if(t==x) break;
    }
    SCC.push_back(scc);
  }
  return parent;
}

int main(void)
{
  int v=11;
  a[1].push_back(2);
  a[2].push_back(3);
  a[3].push_back(1);
  a[4].push_back(2);
  a[4].push_back(5);
  a[5].push_back(7);
  a[6].push_back(5);
  a[7].push_back(6);
  a[8].push_back(5);
  a[8].push_back(9);
  a[9].push_back(10);
  a[10].push_back(11);
  a[11].push_back(3);
  a[11].push_back(8);
  for(int i=1;i<=v;i++){
    if(d[i]==0)dfs(i);
  }
  cout<<"scc count : "<<SCC.size()<<endl;
  for(int i=0;i<SCC.size();i++){
    cout<<i+1<<"번째 scc : ";
    for(int j=0;j<SCC[i].size();j++){
      cout<<SCC[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
