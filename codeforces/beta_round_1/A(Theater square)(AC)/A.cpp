#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n,m,a;
  cin>> n >> m >> a;
  long long k1 = n/a;
  long long k2 = m/a;
  long long d1 = n%a;
  long long d2 = m%a;
  if(d1!=0)k1++;
  if(d2!=0)k2++;
  cout<<k1*k2<<endl;
  return 0;
}
