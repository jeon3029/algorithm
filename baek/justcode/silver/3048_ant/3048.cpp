#include<bits/stdc++.h>
using namespace std;
int L,R;
string Ls, Rs;
vector<int> Dir;
string ans;
int len;
int T;
void input(){
  cin>>L>>R;
  len = L + R;
  cin>>Ls>>Rs;
  reverse(Ls.begin(),Ls.end());
  cin>>T;
  Dir = vector<int>(len,0);
  for(int i=0;i<L;i++)Dir[i] = 1;//1=right, 0=left
  ans = Ls + Rs;
}
void calc(){
  for(int t=0;t<T;t++){
    for(int i=0;i<len-1;i++){
      if(Dir[i]==1&&Dir[i+1]==0){
        swap(ans[i],ans[i+1]);
        swap(Dir[i],Dir[i+1]);
        i++;
      }
    }
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  input();
  calc();
  cout<<ans<<"\n";
}