#include<iostream>
#include<string>
#define MAX 50
using namespace std;
int N;
string s[MAX];
string result;
int main(void){
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>s[i];
  }
  int flag;
  if(N==1){
    cout<<s[0]<<endl;
    return 0;
  }
  for(int i=0;i<s[0].size();i++){
    flag=0;
    for(int j=1;j<N;j++){
      if(s[j].at(i) == s[j-1].at(i)){
        continue;
      }
      else{
        flag = 1;
        break;
      }
    }
    if(flag==1){
      result.append("?");
    }
    else{
      string temp(1,s[0].at(i));
      result.append(temp);
    }
  }
  cout<<result<<endl;
  return 0;
}
