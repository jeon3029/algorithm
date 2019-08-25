#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;
int N,K;
int data[MAX];
bool possible(int num){
  int cnt=0;
  for(int i=0;i<N;i++){
    cnt+= data[i] / num;
    if(cnt >= K)return true;
  }
  return false;
}
int main(void){
  cin>>N>>K;
  int max_data=0;
  for(int i=0;i<N;i++){
    scanf("%d",&data[i]);
    if(data[i]>max_data)max_data=data[i];
  }
  int left=0;
  int right = max_data;
  int mid;
  while(left<=right){
    mid = (left + right)/2;
    if(mid!=0 && possible(mid))left=mid+1;
    else right = mid-1;
  }
  cout<<right;
  return 0;
}
