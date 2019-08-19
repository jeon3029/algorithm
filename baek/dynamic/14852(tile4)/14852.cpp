#include<iostream>
using namespace std;
long long D[1000001];
int sum[1000001];
int main(void){
    int n;
    cin>>n;
// 1*1 / 1*2 / 2*1 블록 사용
    D[0] = 1;
    D[1] = 2;
    D[2] = 7;
    for(int i=3 ; i <= n;i++){
      sum[i] += (sum[i-1] + D[i-3]*2)%1000000007;
      D[i] = (((D[i-1]*2) +(D[i-2]*3) + sum[i]))%1000000007;
    }
    cout<< D[n] <<endl;
    return 0;
}
