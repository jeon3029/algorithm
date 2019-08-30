#include<bits/stdc++.h>
using namespace std;
int main(){
  int q;cin>>q;
  while(q--){
    int n,k;
    cin>>n>>k;
    int min=987654321,max = 0;
    for(int i=0;i<n;i++){
      int x; cin>>x;
      if(min>x)min=x;
      if(max<x)max=x;
    }
    //cout<<max<<" "<<min<<endl;
    if((max-min) <= (2*k)){
      cout<<min+k<<endl;
    }
    else cout<<"-1"<<endl;
  }
  return 0;
}
