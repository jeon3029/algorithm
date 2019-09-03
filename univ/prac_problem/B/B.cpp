#include<bits/stdc++.h>
using namespace std;
//가상화폐 문제
vector<int> data[10000];//to whom and count
int inDegree[10000];
int n,m;
queue<int> q;
int result[10000];
int topologySort(){
  for(int i=1;i<=n;i++){
      if(inDegree[i]==0){
        q.push(i);
      }
  }
  for(int i=0;i<n;i++){
    if(q.empty()){//cycle
      break;
    }
    int x = q.front();q.pop();
    for(int j=0;j<data[x].size();j++){
      int y = data[x][j];
      if(--inDegree[y]==0){
        q.push(y);
      }
      result[y] = result[x]+1;
    }
  }
  int max=0;int k=0;
  for(int i=0;i<=n+1;i++){//조건 다시 확인!!
    if(result[i]>max){
      max = result[i];k=i;
    }
  }
  return k;
}
int main(){
  int T;scanf("%d",&T);
  for(int num=0;num<T;num++){
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++) data[i].clear();
    int count=m;
    for(int i=0;i<m;i++){
      int x,y;
      scanf("%d%d",&x,&y);
      data[x].push_back(y);
      inDegree[y]++;
    }
    //입력 끝
    int res = topologySort();
    cout<<"Case #"<<num+1<<'\n'; 
    cout<<res<<'\n';
  }
  return 0;
}
