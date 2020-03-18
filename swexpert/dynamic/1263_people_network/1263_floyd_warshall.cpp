#include<bits/stdc++.h>
using namespace std;
const int INF = 987564321;
int G[1000][1000];
int N;
void input(){
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			int t;cin>>t;
			if(i==j)G[i][j]=0;
			else if(t==0)G[i][j]=INF;
			else G[i][j]=t;
		}
	}
}
int getD(int i){
	int sum = 0;
	for(int j=0;j<N;j++){
		sum+=G[i][j];
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;cin>>T;
	for(int tc=1;tc<=T;tc++){
		input();
		for(int k=0;k<N;k++){
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					if(G[i][k] + G[k][j] < G[i][j]){
						G[i][j] = G[i][k] + G[k][j];
					}
				}
			}
		}
		int answer = INF;
		for(int i=0;i<N;i++){
			answer = min(answer,getD(i));
		}
		cout<<"#"<<tc<<" "<<answer<<"\n";
	}
}