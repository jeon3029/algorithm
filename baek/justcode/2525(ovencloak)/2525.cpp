#include<iostream>
using namespace std;
int H,M;
int mi;
void calc(){
  int h = mi/60;
  int mm = mi%60;
  H += h;
  M += mm;
  if(M>=60){
    M-=60;
    H++;
  }
  H=H%24;
  cout<<H<<" "<<M<<endl;
}
int main(void)
{
  cin>>H>>M>>mi;
  calc();
}
