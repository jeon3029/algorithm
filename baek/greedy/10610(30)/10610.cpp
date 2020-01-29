#include<bits/stdc++.h>
using namespace std;
int main(void){
  string s;
  cin>>s;
  int flag = 0,sum=0;
  vector<int> a;
  //cout<<s<<endl;
  for(int i=0;i<s.size();i++){
    int x = atoi(s.substr(i,1).c_str());
    //cout<<s.substr(i,1)<<endl;
    //cout<<x<<endl;
    sum+=x;
    a.push_back(x);
    if(x==0)flag=1;
  }
  if(flag==1 && sum%3==0){
    sort(a.begin(),a.end(),greater<int>());
    for(int i=0;i<a.size();i++){
      cout<<a[i];
    }cout<<endl;
  }
  else{
    cout<<"-1"<<endl;
  }
}
