#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  int i;
  for(i=n;;i++){
    int k=i;
    int cnt=0;
    while(k!=0){
      cnt+=k%10;
      k/=10;
    }
    if(cnt%4==0)break;
  }
  cout<<i<<endl;
  return 0;
}
