#include<bits/stdc++.h>

using namespace std;

int main(void){
  int n;cin>>n;
  vector<int> data;
  while(n--){
    int x;scanf("%d",&x);
    data.push_back(x);
  }
  vector<int> answer(data.size()+1,0);
  answer[data[0]+1] = 1;
  for(int i=2;i<=data.size();i++){
    int cnt=0;
    for(int j=1;j<=data.size();j++){
      if(cnt==data[i-1] && answer[j]==0){
        answer[j] = i;
        break;
      }
      else if(answer[j]==0){
        cnt++;
      }
    }
  }

  for(int i=1;i<=data.size();i++){
    cout<<answer[i]<<" ";
  }cout<<endl;
  return 0;
}
