#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
//predefined
int Data[10][10];
int visited[10][10];
int N,M;
int island=0;

int graph[6][6];
const int INF = 987654321;
void input(){
  cin>>N>>M;
  rep(i,0,N)rep(j,0,M)cin>>Data[i][j];
}
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
bool isWall(int x,int y){
  return x<0||y<0||x>=N||y>=M;
}
void visit(int i,int j){
  queue<pair<int,int>> pos;
  pos.push({i,j});
  while(!pos.empty()){
    int cx = pos.front().first;
    int cy = pos.front().second;
    visited[cx][cy]=island;
    pos.pop();
    for(int d=0;d<4;d++){
      int nx = cx + dir[d][0];
      int ny = cy + dir[d][1];
      
      if(!isWall(nx,ny)&& !visited[nx][ny]&& Data[nx][ny]==1){
        pos.push({nx,ny});
        visited[nx][ny]=island;
      }
    }
  }
}
int straight_dist(int x,int y,int to){
  int min_dist = INF;

  // if(x==1 && y==6)cout<<to<<"\n";
  for(int d=0;d<4;d++){//동서남북
    int dist = 0;
    int cx = x,cy = y;
    // if(x==1 && y==6)cout<<"dir : "<<d<<"\n";
    while(1){
      cx = cx + dir[d][0];
      cy = cy + dir[d][1];
      if(x==1 && y==6){
        // cout<<"cur : "<<cx<<","<<cy<<"\n";
      }
      if(isWall(cx,cy)){
        dist = INF;break;
      }
      if(visited[cx][cy]==0){
        dist++;continue;
      }
      if(visited[cx][cy]==to){
        break;
      }
      else{
        dist = INF;break;
      }
    }
    if(dist<min_dist && dist!=1)min_dist = dist;
  }
  return min_dist;
}
//minimum distance of a and b
int calc_dist(int a,int b){
  int dist = INF;
  rep(i,0,N){
    rep(j,0,M){
      if(visited[i][j]==a){
        int cur_dist = straight_dist(i,j,b);
        if(cur_dist==1)continue;
        if(cur_dist<dist)dist = cur_dist;
      }
    }
  }
  return dist;
}
class Edge{
public:
  int from;int to;int dist;
  Edge(int a,int b,int c){
    from = a;to = b;dist = c;
  }
};
bool cmp(Edge a,Edge b){
  return a.dist<b.dist;
}
int parent[10];
int find(int u){
  if(parent[u]==-1)return u;
  return find(parent[u]);
}
void merge(int u,int v){
  u = find(u);
  v = find(v);
  if(u!=v){
    if(u<v)parent[v] = u;
    else parent[u] = v;
  }
  // parent[u] = v;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  input();
  //calc number of island
  // cout<<"num of island : ";

  rep(i,0,N){
    rep(j,0,M){
      if(!visited[i][j] && Data[i][j]==1){
        island++;
        visit(i,j);
      }
    }
  }
  // cout<<island<<"\n";

  // rep(i,0,N){
  //   rep(j,0,M){cout<<visited[i][j]<<" ";
  //   }cout<<"\n";
  // }cout<<"\n";
  vector<Edge> edge;
  for(int i=0;i<island;i++){
    for(int j=i+1;j<island;j++){
      int dis = calc_dist(i+1,j+1);
      // cout<<i+1<<","<<j+1<<"\n";
      graph[i][j] = dis;
      graph[j][i] = dis;
      if(dis!=INF){
        edge.push_back(Edge(i,j,dis));
        // cout<<i+1<<" "<<j+1<<" "<<dis<<"\n";
      }
    }
  }

  //kruskal
  int answer = 0;
  sort(edge.begin(),edge.end(),cmp);
  for(int i=0;i<island;i++)parent[i] = -1;
  for(int i=0;i<edge.size();i++){
    int x = find(edge[i].from);
    int y = find(edge[i].to);
    if(x==y)continue; //cycle
    else{
      merge(x,y);
      answer+=edge[i].dist;
    }
  }
  for(int i=0;i<edge.size();i++){
    int x = find(edge[i].from);
    int y = find(edge[i].to);
    if(x==y)continue; //cycle
    else{
      merge(x,y);
      // answer+=edge[i].dist;
    }
  }

  int pp = find(0);
  int valid = 1;
  for(int i=0;i<island;i++){
    // cout<<find(i)<<"\n";
    if(find(i)!=pp)valid = 0;
  }
  if(!valid)cout<<"-1\n";
  else cout<<answer<<"\n";
}