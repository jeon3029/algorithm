#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int Data[1000][3];//red, green, blue
int N;
int dp[1000][3];
void input(){
    cin>>N;
    for(int i=0;i<N;i++)cin>>Data[i][0]>>Data[i][1]>>Data[i][2];
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    int answer = INF;
    //red first
    memset(dp,0,sizeof(dp));
    dp[0][0]=Data[0][0];
    dp[0][1]=INF;
    dp[0][2]=INF;
    for(int i=1;i<N;i++){
        int val = min(dp[i-1][1],dp[i-1][2]);
        if(val==INF)  dp[i][0]=INF;
        else{
            if(i==N-1)dp[i][0] = INF;
            else dp[i][0] = val + Data[i][0];
        }
        val = min(dp[i-1][0],dp[i-1][2]);
        if(val==INF)  dp[i][1]=INF;
        else{
            dp[i][1] = val + Data[i][1];
        }

        val = min(dp[i-1][0],dp[i-1][1]);
        if(val==INF)  dp[i][2]=INF;
        else{
            dp[i][2] = val + Data[i][2];
        }
    }
    answer = min({answer,dp[N-1][0],dp[N-1][1],dp[N-1][2]});
    //green first
    memset(dp,0,sizeof(dp));
    dp[0][0]=INF;
    dp[0][1]=Data[0][1];
    dp[0][2]=INF;
    for(int i=1;i<N;i++){
        int val = min(dp[i-1][1],dp[i-1][2]);
        if(val==INF)  dp[i][0]=INF;
        else{
            dp[i][0] = val + Data[i][0];
        }
        val = min(dp[i-1][0],dp[i-1][2]);
        if(val==INF)  dp[i][1]=INF;
        else{
            if(i==N-1)dp[i][1] = INF;
            else dp[i][1] = val + Data[i][1];
        }
        val = min(dp[i-1][0],dp[i-1][1]);
        if(val==INF)  dp[i][2]=INF;
        else{
            dp[i][2] = val + Data[i][2];
        }
    }
    answer = min({answer,dp[N-1][0],dp[N-1][1],dp[N-1][2]});
    //blue first
    memset(dp,0,sizeof(dp));
    dp[0][0]=INF;
    dp[0][1]=INF;
    dp[0][2]=Data[0][2];
    for(int i=1;i<N;i++){
        int val = min(dp[i-1][1],dp[i-1][2]);
        if(val==INF)  dp[i][0]=INF;
        else{
            dp[i][0] = val + Data[i][0];
        }
        val = min(dp[i-1][0],dp[i-1][2]);
        if(val==INF)  dp[i][1]=INF;
        else{
            dp[i][1] = val + Data[i][1];
        }
        val = min(dp[i-1][0],dp[i-1][1]);
        if(val==INF)  dp[i][2]=INF;
        else{
            if(i==N-1)dp[i][2] = INF;
            else dp[i][2] = val + Data[i][2];
        }
    }
    answer = min({answer,dp[N-1][0],dp[N-1][1],dp[N-1][2]});
    cout<<answer<<"\n";
}