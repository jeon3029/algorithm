#include<bits/stdc++.h>
using namespace std;
class CVelt{
public:
  int frac;
  bool isPeople;
  CVelt(){
    frac=0;
    isPeople=false;
  }
};
vector<CVelt> velt;
int N,K;
void input(){
  cin>>N>>K;
  velt = vector<CVelt>(2*N,CVelt());
  for(int i=0;i<2*N;i++){
    cin>>velt[i].frac;
  }
}
void movevelt(){
  CVelt temp = velt[2*N-1];
  for(int i=2*N-1;i>=1;i--){
    velt[i] = velt[i-1];
  }
  velt[0] = temp;
  velt[N-1].isPeople=false;
}
void movepeople(){
  for(int i=N-2;i>=0;i--){
    if(velt[i].isPeople==false)continue;
    if(velt[i+1].isPeople==true || velt[i+1].frac==0)continue;
    velt[i].isPeople=false;
    velt[i+1].isPeople=true;
    velt[i+1].frac--;
  }
  velt[N-1].isPeople=false;
}
int answer = 0;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  input();
  for(int t=1;;t++){
    movevelt();
    movepeople();
    if(!velt[0].isPeople && velt[0].frac>0){
      velt[0].frac--;
      velt[0].isPeople=true;
    }
    int cnt=0;
    for(int i=0;i<2*N;i++){
      if(velt[i].frac==0)cnt++;
    }
    if(cnt>=K){
      answer = t;
      break;
    }
  }
  cout<<answer<<"\n";
}