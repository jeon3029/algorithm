#include<bits/stdc++.h>
using namespace std;

char findmax(int *data){
  int max = 0;
  int pos=0;
  for(int i=0;i<27;i++){
    if(max<data[i]){
      max = data[i];
      pos = i;
    }
  }
  return 'A'+pos;
}
int main(){
  vector<string> s(1000,"");
  int n,m;
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>s[i];
  }
  int alpha[27];
  string result="";

  for(int i=0;i<m;i++){//알파벳 제일 많은 것 1개씩 찾기
    fill(alpha,alpha+27,0);
    for(int j=0;j<n;j++){//순회하며 1개씩 +
      alpha[s[j][i]-'A']++;
      //cout<<s[j][i]-'A'<<endl;
    }
    //string temp(1,findmax(alpha));
    //result.append(temp);
    result.append(1,findmax(alpha)); //-> doesnt work
  }
  cout<<result<<endl;
  int cnt=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(s[i][j]!=result[j]){
        cnt++;
      }
    }
  }
  cout<<cnt<<endl;
  return 0;
}
