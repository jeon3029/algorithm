#include<bits/stdc++.h>
using namespace std;
#warning TODO : check for big integer
const int COUNT_MAX  = 1e6 +1;
int A[COUNT_MAX];
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i];
    }
    sort(A+1,A+n+1);
    cout<<A[2]<<"\n";
}