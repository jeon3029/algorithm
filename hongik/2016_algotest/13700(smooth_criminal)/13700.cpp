#include<iostream>
#define MAX 100001
using namespace std;

int N, S, D, F, B, K;
int d[MAX];
void dfs(int point){
  if(point==D)return;

  if(point+F <= N && d[point+F]!=-1 && d[point]+1 < d[point+F]){
    d[point+F] = d[point]+1;
    /*for(int i=0;i<=N;i++){
      cout<<d[i]<<" ";
    }cout<<endl;*/
    //cout<<"count : "<<d[point+F]<<endl;
    //cout<<"forward : "<<point<<endl;
    dfs(point+F);
  }
  if(point-B>=1 && d[point-B]!=-1 && d[point]+1 < d[point-B]){
    d[point-B] = d[point]+1;
    dfs(point-B);
  }
}
int main(void){
  scanf("%d%d%d%d%d%d",&N,&S,&D,&F,&B,&K);
  fill(d,d+MAX,MAX);
  for(int i=0;i<K;i++){
    int temp;scanf("%d",&temp);
    d[temp]=-1;
  }
  int point = S;

  d[point]=0;
  /*for(int i=0;i<=N;i++){
    cout<<d[i]<<" ";
  }cout<<endl;*/

  dfs(point);

  if(d[D]==MAX){
    cout<<"BUG FOUND"<<endl;
    return 0;
  }
  cout<<d[D]<<endl;
  return 0;
}
