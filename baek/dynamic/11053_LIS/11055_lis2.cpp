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
	int sum[n];
	memset(sum,0,sizeof(sum));
	int ans = 0;
	for(int i=0;i<n;i++){
		if(sum[i]==0)sum[i]=D[i];
		for(int j=0;j<i;j++){
			if(D[j]<D[i]){
				sum[i] = max(sum[i],sum[j]+D[i]);
			}
		}
		ans = max(ans,sum[i]);
	}cout<<ans<<"\n";
}