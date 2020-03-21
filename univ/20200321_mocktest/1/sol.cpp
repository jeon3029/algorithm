//problem 1
#include<bits/stdc++.h>
using namespace std;
int N,M,K;
int Map[40][40];
vector<vector<vector<int>>> S;
void input(){
	cin>>N>>M>>K;
	for(int i=0;i<K;i++){
		int r,c;cin>>r>>c;
		vector<vector<int>> temp;
		for(int x=0;x<r;x++){
			vector<int> t;
			for(int y=0;y<c;y++){
				int s;cin>>s;
				t.push_back(s);
			}
			temp.push_back(t);	
		}
		S.push_back(temp);
	}
}
bool possible(int x,int y,vector<vector<int>> cur){
	for(int i=0;i<cur.size();i++){
		for(int j=0;j<cur[0].size();j++){
			if(cur[i][j]==1 && Map[i+x][j+y]==1){
				return false;
			}
		}
	}
	return true;
}
void coloring(int x,int y,vector<vector<int>> cur){
	for(int i=0;i<cur.size();i++){
		for(int j=0;j<cur[0].size();j++){
			if(cur[i][j]){
				Map[i+x][j+y]=1;
			}
		}
	}
}
vector<vector<int>> rotate(vector<vector<int>> now){
	int r = now.size();
	int c = now[0].size();
	vector<vector<int>> rot(c,vector<int>(r));
	for(int i=0;i<now.size();i++){
		for (int j=0;j<now[0].size();j++){
			rot[j][r-i-1] = now[i][j];
		}
	}
	return rot;
}
void calc(int cur){
	vector<vector<int>> now = S[cur];
	for(int d=0;d<4;d++){
		if(d!=0)now = rotate(now);
		int r = now.size();
		int c = now[0].size();
		for(int i=0;i<=N-r;i++){
			for(int j=0;j<=M-c;j++){
				if(possible(i,j,now)){
					coloring(i,j,now);
					return;
				}
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	for(int i=0;i<K;i++){
		calc(i);
	}
	int answer = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(Map[i][j])answer++;
		}
	}
	cout<<answer<<"\n";
}