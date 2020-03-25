#include<bits/stdc++.h>
using namespace std;
int dp[1001][3];
int Data[1001][3];
int N;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>Data[i][0]>>Data[i][1]>>Data[i][2];
    }
    dp[0][0] = Data[0][0];
    dp[0][1] = Data[0][1];
    dp[0][2] = Data[0][2];
    for(int i=1;i<N;i++){
        dp[i][0] = min(dp[i-1][1],dp[i-1][2])+Data[i][0];
        dp[i][1] = min(dp[i-1][0],dp[i-1][2])+Data[i][1];
        dp[i][2] = min(dp[i-1][0],dp[i-1][1])+Data[i][2];
    }
    cout<<min({dp[N-1][0],dp[N-1][1],dp[N-1][2]})<<"\n";
}