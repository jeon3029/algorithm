#include<bits/stdc++.h>
using namespace std;
const int COUNT_SIZE = 1e6+1;
int A[COUNT_SIZE];
int main(){
    
    int N;cin>>N;
    for(int i=1;i<=N;i++){
        cin>>A[i];
    }
    for(int i=1;i<=N;i++){
        int count =0;
        for(int j=1;j<=N;j++){
            if(A[j]<A[i])count++;
            if(count>2)break;
        }
        if(count==1){
            cout<<A[i];
            return 0;
        }
    }
    assert("error");
}