#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
  int n;
  int data[100];
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>data[i];
  }
  sort(data,data+n);
  if(n==1){
    cout<<data[0]*data[0]<<endl;
    return 0;
  }
  else{
    cout<<data[0]*data[n-1]<<endl;
    return 0;
  }
}
