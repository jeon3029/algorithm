#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)

int N;
int T[1500002];
int P[1500002];
int Dp[1500002];//i 일에 최대 금액
void input(){
    cin>>N;
    rep(i,1,N+1) cin>>T[i]>>P[i];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    memset(Dp,0,sizeof Dp);
    for(int i=N;i>=1;i--){
        if(i+T[i] > N+1){
            Dp[i] = Dp[i+1];
        }
        else{
            Dp[i] = max(Dp[i+1],P[i]+Dp[i+T[i]]);
        }
    }
    cout<<Dp[1]<<"\n";
}