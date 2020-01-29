#include<iostream>
#include<string>
using namespace std;
int main(void){
  string s;
  int count=0;
  getline(std::cin,s);
  for(int i=0;i<s.size();i++){
    if(s.at(i)==' ')count++;
  }
  if(s.at(0)==' ')count--;
  if(s.at(s.size()-1)==' ')count--;
  printf("%d\n",count+1);
  return 0;
}
