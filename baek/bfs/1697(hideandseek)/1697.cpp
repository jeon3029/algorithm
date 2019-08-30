#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
int n,k;
int D[MAX];
void dfs(int x){
  if(x==k)return;
  if(x!=0 && x<k && x*2<MAX && D[x*2]>D[x]+1){
    D[x*2] = D[x]+1;
    dfs(x*2);
  }
  if(x<k && x+1 < MAX && D[x+1] > D[x]+1){
    D[x+1] = D[x]+1;
    dfs(x+1);
  }
  if(x-1>=0 && D[x-1]>D[x]+1){
    D[x-1] = D[x]+1;
    dfs(x-1);
  }
}
void bfs(){
  queue<int> q;
  q.push(n);
  while(!q.empty()){
    int x = q.front();q.pop();
    if(x==k)break;
    if(x<k && x+1<MAX && D[x+1]==0){
      q.push(x+1);
      D[x+1] = D[x]+1;
    }
    if(x-1>=0 && D[x-1]==0){
      q.push(x-1);
      D[x-1] = D[x]+1;
    }
    if(x!=0&&x*2<MAX && D[x*2]==0){
      q.push(x*2);
      D[x*2] = D[x]+1;
    }
  }
}
int main(void){
  cin>>n>>k;
  fill(D,D+MAX,987654321);
  D[n]=0;
  //dfs(n);
  fill(D,D+MAX,0);
  bfs();
  cout<<D[k]<<endl;
}
