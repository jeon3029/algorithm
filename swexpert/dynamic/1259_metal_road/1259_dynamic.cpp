#include<bits/stdc++.h>
using namespace std;
int D[100][2];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;cin>>T;
	for(int tc=1;tc<=T;tc++){
		int k;cin>>k;
		memset(D,0,sizeof(D));
		int f,r;
		for(int i=0;i<k;i++){
			cin>>f>>r;
			D[f][0] = r;
			D[r][1] = f;
		}
		while(D[f][1]!=0)f=D[f][1];
		cout<<"#"<<tc<<" ";
		while(D[f][0]){
			cout<<f<<" "<<D[f][0]<<" ";
			f=D[f][0];
		}cout<<"\n";
	}
}