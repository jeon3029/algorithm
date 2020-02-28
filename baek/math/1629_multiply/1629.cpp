#include<bits/stdc++.h>
using namespace std;
long long a,b,c;
int power(int n, int k){
    if(k==0) return 1;
    int temp = power(n,k/2);
    int result = (1LL * temp * temp) % c; 
  	if(k%2) result = 1LL * result * n % c;
    return result;
}
int main(){
    
    cin>>a>>b>>c;
    cout<<power(a,b)<<"\n";
}