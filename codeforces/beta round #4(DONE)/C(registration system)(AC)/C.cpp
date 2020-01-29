#include<bits/stdc++.h>
using namespace std;
class Dup{
public:
  string s;
  int cnt;
public:
  Dup(){s="";cnt=0;}
  Dup(string _s,int _cnt):s(_s),cnt(_cnt){}
  Dup(string _s):s(_s),cnt(0){}
};
int main(){
  vector<Dup> s;
  int n;cin>>n;
  while(n--){
    string temp; cin>>temp;
    int flag = 0;
    for(int i=0;i<s.size();i++){
      if(s[i].s == temp){
        cout<<s[i].s<<s[i].cnt+1<<endl;
        s[i].cnt++;
        flag=1;
        break;
      }
    }
    if(flag == 1)continue;
    else{
      cout<<"OK"<<endl;
      s.push_back(Dup(temp));
    }
  }
  return 0;
}
