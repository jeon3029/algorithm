#include<bits/stdc++.h>
using namespace std;
int main(){
  int d,sumTime;
  cin>>d>>sumTime;
  vector<pair<int,int>  > data;
  int min = 0;
  int max = 0;
  vector<int> result;
  int cnt=0;
  for(int i=0;i<d;i++){
    int x,y;cin>>x>>y;
    data.push_back(make_pair(x,y));
    min+=x;max+=y;
    result.push_back((x+y)/2);
    cnt+=result.back();
  }
  if(min<=sumTime && max>=sumTime){
    int i=0;
    while(1){
      if(cnt == sumTime){
        break;
      }
      else if(cnt < sumTime){
        if(result[i%d]<data[i%d].second){
          result[i%d]++;
          cnt++;
        }
        i++;
      }
      else{
        if(result[i%d]>data[i%d].first){
          result[i%d]--;
          cnt--;
        }
        i++;
      }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<d;i++){
      cout<<result[i]<<endl;
    }
  }
  else{
    cout<<"NO"<<endl;
  }
  return 0;
}
