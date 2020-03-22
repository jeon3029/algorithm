#include<bits/stdc++.h>
using namespace std;
int Data[50][30];
int Sum[51][31];
int N,K,P;
int answer = 0;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;cin>>T;
	for(int tc=1;tc<=T;tc++){
		cin>>N>>K>>P;
		memset(Sum,0,sizeof(Sum));
		for(int i=0;i<N;i++){
			for(int j=0;j<K;j++){
				cin>>Data[i][j];
				if(j==0)Sum[i+1][j+1] = Data[i][j];
				else Sum[i+1][j+1] = Sum[i+1][j]+Data[i][j];
			}
		}
		int dp[N+1][P+1];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=N;i++){
			for(int j=0;j<=P;j++){
				dp[i][j] = dp[i-1][j];
				for(int x=1;x<=K;x++){
					if(j>=x)
					dp[i][j] = 	max(dp[i][j],Sum[i][x] + dp[i-1][j-x]);
				}
			}
		}
		for(int i=1;i<=N;i++){
			for(int j=0;j<=P;j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<"\n";
		}
		cout<<"Case #"<<tc<<": "<<dp[N][P]<<"\n";
	}
}