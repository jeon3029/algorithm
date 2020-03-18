#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int D[100][100];
int N;
int visited[100][100];
int rightOrder[100][2];
int calc(pi p1,pi p2){
	return p1.second * p1.first*p2.second;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;cin>>T;
	for(int tc=1;tc<=T;tc++){
		cin>>N;
		memset(visited,0,sizeof(visited));
		memset(rightOrder,0,sizeof(rightOrder));
		vector<pi> mat;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cin>>D[i][j];
			}
		}
		//find all chemical matter -> mat
		int f;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(!visited[i][j] && D[i][j]){
					int r,c;
					for(r=i;r<N;r++){
						if(D[r][j]==0)break;
					}
					for(c=j;c<N;c++){
						if(D[i][c]==0)break;
					}
					rightOrder[r-i][0] = c-j;
					rightOrder[c-j][1] = r-i;
					f=r-i;
					for(int t1=i;t1<r;t1++)for(int t2=j;t2<c;t2++)visited[t1][t2]=1;	
				}
			}
		}
		// order matrix in multipliable order ->mat
		while(rightOrder[f][1])f=rightOrder[f][1];//find first pos
		while(rightOrder[f][0]){
			mat.push_back({f,rightOrder[f][0]});
			f=rightOrder[f][0];
		}
		
		//find mimimum multiply count
		int dp[20][20];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<mat.size();i++){
			for(int j=0;j<mat.size()-i;j++){ //j부터 i칸 만큼 확인
				pi t1,t2;
				t1.first = j;
				t2.second = j+i;
				int val = 987654321;
				for(int k=0;k<i;k++){
					t1.second= j+k;
					t2.first = j+k+1;
					pi former = {mat[t1.first].first,mat[t1.second].second};
					pi latter = {mat[t2.first].first,mat[t2.second].second};
					val = min(val,dp[t1.first][t1.second] + dp[t2.first][t2.second] + 
							 calc(former,latter));
				}
				dp[j][j+i] = val;
			}
		}
		cout<<"#"<<tc<<" "<<dp[0][mat.size()-1]<<"\n";
	}
}