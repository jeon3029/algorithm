#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;cin>>T;
	for(int tc=1;tc<=T;tc++){
		int n,k;
		cin>>n>>k;
		int Data[n][2];//volume,value
		for(int i=0;i<n;i++){
			cin>>Data[i][0]>>Data[i][1];
		}
		int Dp[n+1][k+1];
		memset(Dp,0,sizeof(Dp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				if(j<Data[i-1][0]){
					Dp[i][j] = Dp[i-1][j];
				}
				else{
					Dp[i][j] = max(Dp[i-1][j-Data[i-1][0]]+Data[i-1][1],Dp[i-1][j]);
				}
			}
		}
		cout<<"#"<<tc<<" "<<Dp[n][k]<<"\n";
	}
}