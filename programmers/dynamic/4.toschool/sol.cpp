#include <string>
#include <vector>

using namespace std;
bool check(int row,int col,const vector<vector<int>> &puddles){
    if(row==0 || col==0)return false;
    for(int i=0;i<puddles.size();i++){
        if(row == puddles[i][1] && col == puddles[i][0]){
            return true;
        }
    }
    return false;
}
long long dp[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    dp[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!check(i-1,j,puddles)){
                dp[i][j]+=dp[i-1][j];
            }
            if(!check(i,j-1,puddles)){
                dp[i][j]+=dp[i][j-1];
            }
            dp[i][j] = dp[i][j]%1000000007;
        }
    }
    answer = dp[n][m];
    return answer;
}