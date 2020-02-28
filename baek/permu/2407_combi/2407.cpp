#include<bits/stdc++.h>
using namespace std;
//파스칼 삼각형 dp
string dp[101][101] ;
string bigInteger(string num1, string num2) {
	long long sum = 0;
	string result;
	while (!num1.empty() || !num2.empty() || sum) {
		if (!num1.empty()) {
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty()) {
			sum += num2.back()-'0';
			num2.pop_back();
		}
		result.push_back((sum % 10) + '0');
		sum /= 10;
	
	}
	reverse(result.begin(), result.end());
	return result;
}
int main() {
	int N, M;
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	if (N == M || M == 0) {
		cout << 1 << "\n";
		return 0;
	}
	dp[0][0] = '0';
	dp[1][0] = '1';
	dp[1][1] = '1';
	for (int i = 2; i <= N; i++) {
		for (int k = 0; k < i + 1; k++) {
			if (k == 0) {
				dp[i][k] = "1";
			}
			else if (i==k) {
				dp[i][k] = "1";
			}
			else{
				dp[i][k] = bigInteger(dp[i - 1][k],dp[i - 1][k - 1]);
			}
		}
	}
	cout << dp[N][M];
}