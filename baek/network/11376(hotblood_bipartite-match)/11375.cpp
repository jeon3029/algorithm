#include<iostream>
#include<vector>
#define MAX 1002
using namespace std;
int N,M;
vector<int> a[MAX];//graph
bool check[MAX];//to check
int dest[MAX];//final graph`

bool dfs(int x){
  for(int i = 0 ; i < a[x].size();i++){
    int y = a[x][i];
    if(check[y])continue;
    check[y] = true;
    if(dest[y]==-1 || dfs(dest[y])){
      dest[y] = x;
      return true;
    }
  }
  return false;
}
void getData(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    int mm;scanf("%d",&mm);
    for(int j=0;j < mm;j++){
      int tt;scanf("%d",&tt);
      a[i].push_back(tt-1);
    }
  }
}
int main(void){
  int count=0;
  getData();
  //return 0;
  fill(dest,dest+MAX,-1);
  for(int i=0;i<N;i++){
    fill(check,check+MAX,false);
    if(dfs(i)) count++;
  }
  printf("%d\n",count);/*
  for(int i=0;i<N;i++){
    printf("%d -> %d\n",dest[i]+1,i+1);
  }*/
  return 0;
}
//done
