#include<bits/stdc++.h>
using namespace std;
void changeMin(long long &x,long long y){x=min(x,y);}

int main(void){
  int T;
  cin>>T;
  while(T--){
    long long n,a,b;
    cin>>n>>a>>b;
    string s; cin>>s;
    vector<long long> dp1(n+1,1e18);
    vector<long long> dp2(n+1,1e18);
    dp1[0] = b;//default first line
    for(int i=0;i<n;i++){
      if(s[i]=='0'){
        changeMin(dp1[i+1],dp1[i]+a+b);//1st floor
        changeMin(dp2[i+1],dp1[i]+ a*2 + b);//1->2
        changeMin(dp1[i+1],dp2[i]+ a*2 + b*2);//2->1
        changeMin(dp2[i+1],dp2[i]+a+2*b);//2nd floor
      }
      else{
        changeMin(dp2[i+1],dp2[i]+a+2*b);
      }
    }
    cout<<dp1[n]<<'\n';

  }
  return 0;
}
