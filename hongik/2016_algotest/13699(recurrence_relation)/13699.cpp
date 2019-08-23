#include<iostream>
using namespace std;
long long t[100];
int main(void){
  int n;
  scanf("%d",&n);
  t[0]=1;
  for(int i=1;i<=n;i++){
    long long sum=0;
    for(int j=0;j<i;j++){
      sum+= t[j] * t[i-j-1];
    }
    t[i]=sum;
  }
  cout<<t[n]<<endl;
}
