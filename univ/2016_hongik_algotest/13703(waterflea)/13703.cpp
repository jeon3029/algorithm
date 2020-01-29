#include<bits/stdc++.h>
using namespace std;
long long k,n;
long long result=0;
long long D[150][150];
long long dfs(int depth,int time){
  if(depth==0){
    return 0;
  }
  if(time==n){
    return 1;
  }
  long long &result = D[depth][time];//inportant : 값을 저장하면서 dfs돌리므로 효율 증가
  if(result !=-1){
    return result;
  }
  result = dfs(depth+1,time+1)+dfs(depth-1,time+1);
  return result;

}
int main(void){
  cin>>k>>n;
  memset(D,-1,sizeof(D));
  cout<<dfs(k,0);
  return 0;
}
