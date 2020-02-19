#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int N;
int Data[100][100];
int visited[100][100];
void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        string s;cin>>s;
        for(int j=0;j<N;j++){
            Data[i][j]=s[j]-'0';
        }
    }
    memset(visited,0,sizeof(visited));
}
bool isWall(int x,int y){
    return x<0||y<0||x>=N||y>=N;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        priority_queue<pair<int,pi>> q;
        q.push({0,{0,0}});
        int answer;
        while(1){
            int t=q.top().first;
            pi c=q.top().second;
            q.pop();
            visited[c.first][c.second]=1;
            if(c.first==N-1&& c.second==N-1){
                answer = t;
                break;
            }
            int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
            for(int d=0;d<4;d++){
                int nx=c.first+dir[d][0];
                int ny=c.second+dir[d][1];
                if(!isWall(nx,ny) && !visited[nx][ny]){
                    visited[nx][ny]=1;
                    q.push({t-Data[nx][ny],{nx,ny}});
                }
            }
        }
        cout<<"#"<<tc<<" "<<-answer<<"\n";
    }
}