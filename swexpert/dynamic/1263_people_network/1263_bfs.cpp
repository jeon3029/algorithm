#include<bits/stdc++.h>
using namespace std;
const int INF = 987564321;
vector<vector<int>> G;
int visited[1000];
int N;
int answer;
void input(){
	cin>>N;
	G= vector<vector<int>>(N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			int t;cin>>t;
			if(t) G[i].push_back(j);
		}
	}
}
void bfs(int start){
	queue<int> q;
	q.push(start);
	int d=0;
	int sum=0;
	visited[start]=1;
	while(!q.empty()){
		d++;
		int len = q.size();
		for(int i=0;i<len;i++){
			int cur= q.front();q.pop();
			for(int j=0;j<G[cur].size();j++){
				int y = G[cur][j];
				if(!visited[y]){
					visited[y] =1;
					sum+=d;
					q.push(y);
					if(sum>=answer)return;
				}
			}
		}
	}
	answer = min(sum,answer);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;cin>>T;
	for(int tc=1;tc<=T;tc++){
		input();
		answer=INF;
		for(int i=0;i<N;i++){
			memset(visited,0,sizeof(visited));
			bfs(i);
		}
		cout<<"#"<<tc<<" "<<answer<<"\n";
	}
}