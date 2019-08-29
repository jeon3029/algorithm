#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  vector<int> k;
  while(n--){
    int x;scanf("%d",&x);k.push_back(x);
  }
  sort(k.begin(),k.end());
  cout<<k[0]<<" "<<k.back()<<endl;
  return 0;
}
