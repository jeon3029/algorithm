#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
typedef pair<int,int> pi;
#define fi first
#define se second
//predefined
int N,M;
int Data[10][10];
int answer = 0;
vector<pi> zeros;
queue<pi> virus;
void input(){
    cin>>N>>M;
    rep(i,0,N)rep(j,0,M){
        cin>>Data[i][j];
        if(Data[i][j]==0)zeros.push_back({i,j});
        if(Data[i][j]==2)virus.push({i,j});
    }
}
bool isWall(int x,int y){
    return x<0||y<0||x>=N||y>=M;
}
int calc(vector<int> combi){
    int Map[10][10];
    int visited[10][10];
    rep(i,0,N)rep(j,0,M)Map[i][j] = Data[i][j];
    memset(visited,0,sizeof(visited));
    rep(i,0,combi.size()){
        if(combi[i]==1){
            int x = zeros[i].fi;
            int y = zeros[i].se;
            Map[x][y] = 1;
        }
    }
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    queue<pi> v = virus;
    while(!v.empty()){
        int x = v.front().fi;
        int y = v.front().se;
        visited[x][y] = 1;
        v.pop();
        for(int d=0;d<4;d++){
            int nx = x+dir[d][0];
            int ny = y+dir[d][1];
            if(!isWall(nx,ny) && !visited[nx][ny] && Map[nx][ny]==0){
                v.push({nx,ny});
                visited[nx][ny] = 1;
                Map[nx][ny] = 2;
            }
        }
    }
    int ret=0;
    rep(i,0,N)rep(j,0,M)if(Map[i][j]==0)ret++;
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    vector<int> combi(zeros.size());
    combi[0]  = 1;
    combi[1]  = 1;
    combi[2]  = 1;
    sort(combi.begin(),combi.end());
    do{
        answer = max(answer,calc(combi));
    }while(next_permutation(combi.begin(),combi.end()));
    cout<<answer<<"\n";
}