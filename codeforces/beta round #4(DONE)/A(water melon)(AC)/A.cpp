#include<bits/stdc++.h>
using namespace std;

int main(void){
  int n;
  cin>>n;
  int flag=0;
  for(int i=1;i<n;i++){
    if(i%2==0 && (n-i) %2==0){
      flag = 1;break;
    }
  }
  if(flag  ==1){
    cout<<"YES"<<endl;
  }
  else{cout<<"NO"<<endl;}
  return 0;
}
