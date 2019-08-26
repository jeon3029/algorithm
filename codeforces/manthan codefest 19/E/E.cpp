#include<bits/stdc++.h>
#define MAX 100001
using namespace std;

int n,w;
vector<int> a[MAX];

long long max_element(vector<int> s, int pos){
  int size = s.size();
  long long max = 0;
  //for(int i=0;i<s.size();i++){
  //  cout<<s[i];
  //}cout<<endl;
  for(int i=0;i<s.size();i++){
    if((i+1)<=pos && (pos-(i+1)+size)<=w ){//check
      if(max<s[i]){
        max = s[i];
      }
    }
  }
  return max;
}
int main(void){
  cin>>n>>w;
  for(int i=0;i<n;i++){
    int T;cin>>T;
    for(int k=0;k<T;k++){
      int x;cin>>x;
      a[i].push_back(x);
    }
  }

  for(int i=1;i<=w;i++){//calc each max sum
    long long sum=0;
    for(int j=0;j<n;j++){
      sum+=max_element(a[j],i);
      //cout<<max_element(a[j],i) <<" ";
    }
    cout<<sum<<" ";
  }cout<<endl;
  return 0;
}
