#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n;cin>>n;
  vector<int> data;
  while(n--){
    int x;cin>>x;
    data.push_back(x);
  }
  int max = 0;
  sort(data.begin(),data.end());
  for(int i=0;i<data.size();i++){
    int cnt=data.size() - (i);
    if(max< cnt*data[i])max = data[i]*cnt;
  }
  cout<<max<<endl;
  return 0;
}
