#include<bits/stdc++.h>
using namespace std;

int main(void){
  int n,k;
  cin>>n>>k;
  vector<int> d;
  for(int i=0;i<n;i++){
    int x;cin>>x;
    d.push_back(x);
  }
  int result = 0;
  for(int i=d.size()-1;i>=0;i--){
    if(d[i]<=k){
      result += k/d[i];
      k= k%d[i];
    }
  }
  cout<<result<<endl;
  return 0;

}
