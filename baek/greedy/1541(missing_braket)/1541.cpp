#include<bits/stdc++.h>
using namespace std;

int main(void){
  string s;
  cin>>s;
  int meetMinus = 0;
  int result = 0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='+'){
      continue;
    }
    else if(s[i]=='-'){
      meetMinus=1;
      continue;
    }
    else{
      int j;
      for(j=i;j<s.size();j++){
        if(s[j]=='+' || s[j] =='-'){
          break;
        }
      }
      if(meetMinus == 0){
        int x = atoi(s.substr(i,j-i).c_str());
        //cout<<s.substr(i,j-i)<<endl;
        result += x;
        //cout<<x<<endl;

      }
      else if(meetMinus == 1){
        int x = atoi(s.substr(i,j-i).c_str());
        //cout<<s.substr(i,j-i)<<endl;
        result -= x;
        //cout<<x<<endl;
      }
      //cout<<j<<endl;
      i=j-1;
    }
  }
  cout<<result<<endl;
  return 0;
}
