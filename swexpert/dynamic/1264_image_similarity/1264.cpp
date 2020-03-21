
//first think : solve list LIS algorithm
//second think : solve with LCS algorithm
#include<bits/stdc++.h>
using namespace std;
int D[501][501];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;cin>>T;
	for(int tc=1;tc<=T;tc++){
		int n;
		string s1,s2;
		cin>>n>>s1>>s2;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(s2[i] == s1[j]){
					D[i+1][j+1] = D[i][j]+1;
				}
				else{
					D[i+1][j+1] = max(D[i+1][j],D[i][j+1]);
				}
			}
		}
		float ans = (float)D[n][n] / n *100;
		cout << fixed;
    	cout.precision(2);
		cout<<"#"<<tc<<" "<<ans<<"\n";
	}
}