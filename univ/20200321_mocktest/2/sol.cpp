//problem 2
#include<bits/stdc++.h>
using namespace std;
int N,M,G,R;
int Map[50][50];
class Point{
	public:
	int x;int y;
	Point(int a,int b){
		x=a;y=b;
	}
};
vector<Point> Grow;
int visited[50][50];//seconds
int type_visited[50][50];//0=x 1=green 2=red, 3=flower 
void input(){
	cin>>N>>M>>G>>R;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>Map[i][j];//0호수 1X 2O
			if(Map[i][j]==2){
				Grow.push_back(Point(i,j));	
			}
		}
	}
}
bool isWall(int x,int y){
	return x<0||y<0||x>=N||y>=M||Map[x][y]==0;
}
int bfs(queue<Point> q){
	int time = 1;
	while(!q.empty()){
		int len = q.size();
		time++;
		for(int i=0;i<len;i++){
			int x = q.front().x;
			int y = q.front().y;q.pop();
			int c_type = type_visited[x][y];
			if(c_type==3)continue;//flower
			int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
			for(int d=0;d<4;d++){
				int nx = x+dir[d][0];
				int ny = y+dir[d][1];
				if(!isWall(nx,ny)){
					if(visited[nx][ny]==0){
						visited[nx][ny]=time;
						type_visited[nx][ny]=c_type;
						q.push(Point(nx,ny));
					}
					else if(visited[nx][ny]==time){//도착 시간 같을때
						if(c_type==1 && type_visited[nx][ny]==2){//서로 종류 다르다면
							type_visited[nx][ny]=3;
						}
						else if(c_type==2 && type_visited[nx][ny]==1){
							type_visited[nx][ny]=3;
						}
					}
				}
			}
		}
	}
	int answer=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(type_visited[i][j]==3)answer++;
		}
	}
	return answer;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	vector<int> combi;
	for(int i=0;i<G;i++){
		combi.push_back(1);
	}
	for(int i=0;i<R;i++){
		combi.push_back(2);
	}
	for(int i=0;i<Grow.size()-R-G;i++){
		combi.push_back(0);
	}
	int answer = 0;
	sort(combi.begin(),combi.end());
	do{
		memset(visited,0,sizeof(visited));
		memset(type_visited,0,sizeof(type_visited));
		queue<Point> q;
		for(int i=0;i<Grow.size();i++){
			int x = Grow[i].x;
			int y = Grow[i].y;
			if(combi[i]==0)continue;
			else if(combi[i]==1){//green
				visited[x][y]=1;
				type_visited[x][y]=1;
				q.push(Point(x,y));
			}
			else{//red
				visited[x][y]=1;
				type_visited[x][y]=2;
				q.push(Point(x,y));
			}
		}
		answer = max(answer,bfs(q));
	}while(next_permutation(combi.begin(),combi.end()));
	cout<<answer<<"\n";
}