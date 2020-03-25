#include<bits/stdc++.h>
using namespace std;
int Data[500][500];
int dp[500][500];
int N;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            cin>>Data[i][j];
        }
        if(i==0)dp[i][0] = Data[i][0];
        else dp[i][0] = Data[i][0]+dp[i-1][0];
    }
    int answer = 0;
    for(int i=0;i<N;i++){
        for(int j=1;j<=i;j++){
            dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+Data[i][j];
            if(i==N-1){
                answer = max(answer,dp[i][j]);
            }
        }
    }
    cout<<answer<<"\n";
}