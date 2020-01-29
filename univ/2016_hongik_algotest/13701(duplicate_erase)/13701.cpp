#include<iostream>
#include<string>
#include<vector>
using namespace std;
int A[1+(1<<20)];
string s;
vector<int> data;
int main(void){
  int temp;
  /*getline(cin,s);
  string strtemp;
  for(int i=0;i<s.size();i++){
    if(s.at(i)==' '){
      data.push_back(atoi(strtemp.c_str()));
      strtemp="";
    }
    else{
      strtemp+=s.at(i);
    }
  }data.push_back(atoi(strtemp.c_str()));
*/
  //for(int i=0;i<data.size();i++){
  while(scanf("%d",&temp)!=EOF){
    int x,y;
    x=temp/32;
    y=temp%32;
    if(A[x]&(1<<y)){
      continue;
    }
    cout<<temp<<" ";
    A[x]+= (1<<y);
  }
  //}
  cout<<endl;
  return 0;
}
