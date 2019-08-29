#include<iostream>
using namespace std;
int H,M;
int mi;
void calc(){
  M += 15;
  if(M>=60){
    M-=60;
  }
  else{
    H--;
    if(H<0){
      H=23;
    }
  }
  cout<<H<<" "<<M<<endl;
}
int main(void)
{
  cin>>H>>M;
  calc();
}
