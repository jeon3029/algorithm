#include<bits/stdc++.h>
using namespace std;
int N,K;
void input(){
  cin>>N>>K;
}
int solve(){
  for(int now=N;;now++){
    int cnt = 0;
    int calc = now;
    while(1){
      cnt += calc%2;
      calc = calc/2;
      if(calc==0)break;
    }
    if(cnt<=K){
      return now-N;
    }
  }
  return -1;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  input();
  cout<<solve();
  return 0;
}

