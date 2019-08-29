#include<bits/stdc++.h>
using namespace std;
int main(void)
{
  int n;
  cin>>n;
  vector<int> data;
  while(n--){
    int x;cin>>x;
    data.push_back(x);
  }
  sort(data.begin(),data.end());
  int result = 0;
  for(int i=0;i<data.size();i++){
    for(int j=0;j<=i;j++){
      result += data[j];
    }
  }
  cout<<result<<endl;
  return 0;
}
