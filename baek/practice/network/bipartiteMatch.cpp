#include<iostream>
#include<vector>
#define MAX 101

using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int n=3,m,s;

bool dfs(int x){
  for(int i=0;i<a[x].size();i++){
    int t = a[x][i];
    if(c[t])continue;
    c[t]=true;
    if(d[t]==0 || dfs(d[t])){//해당 요소를 체크할 수 있는지, 안된다면 이 원소를 가리키고 잇는 녀석을 다른 곳으로 보낼 수 있는지.
      d[t] = x;
      return true;
    }
  }
  return false;
}
int main(void){
  a[1].push_back(1);
  a[1].push_back(2);
  a[1].push_back(3);
  a[2].push_back(1);
  a[3].push_back(2);
  int count =0;
  for(int i=1;i<=n;i++){
    fill(c,c+MAX,false);
    if(dfs(i))count++;
  }
  printf("%d개의 매칭이 성공되었습니다.\n",count);
  for(int i=1;i<=n;i++){
    if(d[i]!=0){
      printf("%d -> %d\n",d[i],i);
    }
  }
  return 0;
}
