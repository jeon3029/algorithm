#include<bits/stdc++.h>
using namespace std;
int N;
int D[50001];
int main(){
    cin>>N;
    for(int i=N;i>=0;i--){
        for(int j=sqrt(i);j>=1;j--){
            if(D[i-j*j]==0||D[i-j*j]>D[i]+1){
                D[i-j*j]=D[i]+1;
            }
        }
    }
    cout<<D[0];
}