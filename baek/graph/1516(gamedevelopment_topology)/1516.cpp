#include<iostream>
#include<queue>
#include<vector>
#define MAX 501
using namespace std;

int preBuild[MAX];
int preBuild_calc[MAX];

int Time[MAX];
vector<int> data[MAX];
int n;
int result[MAX];
void topology_calc(){
  queue<int> q;
  for(int i=0;i<n;i++){
    result[i] = Time[i];
    if(preBuild[i]==0){
      q.push(i);
    }
  }
  for(int i=0;i<n;i++){
    //cout<<preBuild[i]<<endl;
  }
  while(!q.empty()){
    int x = q.front();
    q.pop();
    for(int i=0;i<data[x].size();i++){
      int y = data[x][i];
      result[y] = max(result[y],result[x]+Time[y]);
      if(--preBuild[y]==0){
        q.push(y);
      }
    }
  }
  for(int i=0;i<n;i++){
    cout<<result[i]<<endl;
  }
  return;
}
void input(){
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;;j++){
      int x;
      cin>>x;
      if(x==-1)break;
      if(j==0)Time[i]=x;
      else{
        data[x-1].push_back(i);
        preBuild[i]++;
      }
    }
  }
}
int main(void){
  input();
  topology_calc();
}
