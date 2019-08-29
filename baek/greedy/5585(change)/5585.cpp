#include<bits/stdc++.h>
using namespace std;
int main(void){
  int x;
  cin>>x;
  x = 1000-x;
  int result = 0;
  result += x/500;
  x= x%500;
  result += x/100;
  x= x%100;
  result += x/50;
  x= x%50;
  result += x/10;
  x= x%10;
  result += x/5;
  x= x%5;
  result+=x;
  cout<<result;
}
