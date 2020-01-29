#include<bits/stdc++.h>
using namespace std;
int main(void){
  int T;cin>>T;
  while(T--){
    long long a[3],n;
    cin>>a[0]>>a[1]>>n;
    a[2] = a[0] ^ a[1];
    cout<< a[n%3]<<endl;
  }
  return 0;
}
