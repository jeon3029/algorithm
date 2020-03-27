#include<bits/stdc++.h>
using namespace std;
int Data[100000];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;cin>>T;
	for(int tc=1;tc<=T;tc++){
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>Data[i];
		}
		sort(Data,Data+n);
		int sum = 0;
		int answer = 0;
		for(int i=0;i<n;i++){
			sum+=Data[i];
			if(sum<=k){
				answer++;
			}
			else break;
		}
		cout<<"Case #"<<tc<<": "<<answer<<"\n";
	}
}