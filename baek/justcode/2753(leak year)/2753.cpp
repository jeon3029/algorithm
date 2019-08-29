#include<iostream>
using namespace std;
int main(){
  int n;cin>>n;
  bool out;
  if(n%400==0)out=true;
  else if(n%100==0)out=false;
  else if(n%4==0)out = true;
  else out=false;
  cout<<out<<endl;
  return 0;
}
