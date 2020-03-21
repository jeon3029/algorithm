//LIS : O(N^2) dp algorithm
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;cin>>n;
	vector<int> D;
	for(int i=0;i<n;i++){
		int t;cin>>t;
		D.push_back(t);
	}
	int dp[n];
	memset(dp,0,sizeof(dp));
	int ans = 0;
	for(int i=0;i<n;i++){
		if(dp[i]==0)dp[i]=1;
		for(int j=0;j<i;j++){
			if(D[j]<D[i]){
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
		ans = max(ans,dp[i]);
	}cout<<ans<<"\n";
}