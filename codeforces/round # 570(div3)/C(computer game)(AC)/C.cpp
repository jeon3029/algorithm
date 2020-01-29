#include<bits/stdc++.h>
using namespace std;
int main(){
  int q;cin>>q;
  while(q--){
    long long k,n,a,b;
    cin>>k>>n>>a>>b;
    k = k-a*n;
    if(k>0)cout<<n<<endl;
    else{
      if((a-b)==0){
        cout<<"-1"<<endl;
      }
      else{
          k = -k; ++k;
			    long long diff = a - b;
          long long turns = (k + diff - 1) / diff;
			    if (turns > n) {
				    cout <<"-1"<<endl;
          }
          else {
            cout <<n-turns <<endl;
          }
      }
    }
  }
  return 0;
}
