#include <bits/stdc++.h>
using namespace std;
//주식 구매가능 문제
int main(){
  int T;scanf("%d",&T);
  for(int num=0;num<T;num++){
      int n,k;
      scanf("%d%d",&n,&k);
      vector<int> data;
      data.clear();
      for(int i=0;i<n;i++){
        int temp;scanf("%d",&temp);
        data.push_back(temp);
      }
      int cnt = 1;
      for(int i=1;i<data.size();i++){
        if(data[i]>data[i-1]){
          cnt++;
          if(cnt>=k){
            break;
          }
        }
      }
      if(cnt>=k){
        cout<<"Case #"<<num+1<<'\n';
        cout<<"1"<<'\n';
      }
      else{
        cout<<"Case #"<<num+1<<'\n';
        cout<<"0"<<'\n';
      }
    }

  return 0;
}
