#include<iostream>
#include<string>
using namespace std;
int data[4];
void swap(int a,int b){
  int temp;
  temp = data[a];
  data[a]=data[b];
  data[b]=temp;
}
int main(void){
  string s;
  getline(cin,s);
  data[0] = 1;data[1] =2;data[2]=3;data[3]=4;
  for(int i=0;i<s.size();i++){
    switch(s.at(i)){
      case 'A':swap(0,1);break;
      case 'B':swap(0,2);break;
      case 'C':swap(0,3);break;
      case 'D':swap(1,2);break;
      case 'E':swap(1,3);break;
      case 'F':swap(2,3);break;
    }
  }
  int small,big;
  for(int i=0;i<4;i++){
    if(data[i]==1)small=i+1;
    if(data[i]==4)big =i+1;
  }
  cout<<small<<endl<<big<<endl;
  return 0;
}
