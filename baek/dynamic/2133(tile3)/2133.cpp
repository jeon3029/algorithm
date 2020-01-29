#include<iostream>
using namespace std;
int D[30];
int main(void){
    int n;
    cin>>n;
    //D[1] = 1;
    D[0] = 1;
    D[2] = 3;
    D[4] = 11;
    for(int i=6 ; i <= n;i+=2){
      int sum=0;
      for(int j=i-4;j>=0;j-=2){
        sum+=D[j]*2;
      }
      D[i] = (D[i-2]*3 + sum);
    }
    cout<< D[n] <<endl;
    return 0;
}
