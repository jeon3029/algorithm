
#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  vector<int> data(4,0);
  data[3] = a*b;
  for(int i=0;i<3;i++){
    int k=b%10;
    data[i] = k*a;
    b/=10;
  }
  for(int i=0;i<data.size();i++){
    cout<<data[i]<<endl;
  }
  return 0;
}
