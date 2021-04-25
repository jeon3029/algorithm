#include <string>
#include <vector>
#include<cstring>
using namespace std;
int dp[1000001][2];
int solution(vector<int> money) {
    int answer = 0;
    int N = money.size();
    //첫번째 집 터는경우
    dp[0][0] = -99999999;
    dp[0][1] = money[0];
    for(int i=1;i < N;i++){
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
        if(i>=2){
            dp[i][1] = max(dp[i-1][0],dp[i-2][1]) + money[i];    
        }
        else{
            dp[i][1] = dp[i-1][0] + money[i];;    
        }
    }
    answer = dp[N-1][0];
    //첫번째 집 털지 않는 경우
    memset(dp,0,sizeof dp);
    dp[0][0] = 0;
    dp[0][1] = -99999999;
    for(int i=1;i < N;i++){
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
        if(i>=2){
            dp[i][1] = max(dp[i-1][0],dp[i-2][1]) + money[i];    
        }
        else{
            dp[i][1] = dp[i-1][0] + money[i];;    
        }
    }
    answer = max(answer,dp[N-1][1]);
    answer = max(answer,dp[N-1][0]);
    return answer;
}