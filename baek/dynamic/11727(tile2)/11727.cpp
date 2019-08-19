#include<iostream>
using namespace std;
long long D[1001];
int main(void){
    int n;
    cin>>n;
    D[1] = 1;
    D[2] = 3;
    for(int i=3 ; i <= n;i++){
      D[i] = (D[i-1] + D[i-2]*2) %10007;
    }
    cout<< D[n] <<endl;
    return 0;
}
