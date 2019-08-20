#include<iostream>
#include<queue>
#include<vector>
#define MAX 32001
using namespace std;

int n,m;
vector<int> data[MAX];
vector<int> result;
int inNode[MAX];
queue<int> q;
void topology(){
  for(int i=0;i<n;i++){
    if(inNode[i]==0){
      q.push(i);
    }
  }
  while(!q.empty()){
    int x = q.front();
    q.pop();
    result.push_back(x);
    for(int i=0;i<data[x].size();i++){
      if(--inNode[data[x][i]]==0){
        q.push(data[x][i]);
      }
    }
  }
  for(int i=0;i<result.size();i++){
    cout<<result[i]+1<<" ";
  }
  cout<<endl;
}
int main(void){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    data[x-1].push_back(y-1);
    inNode[y-1]++;
  }
  topology();
  return 0;
}
