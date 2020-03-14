/**
 * @author [jeon3029]
 * @email [jeon3029@naver.com]
 * @create date 2020-03-13 13:50:41
 * @modify date 2020-03-14 16:42:48
 * @desc [swexpert 1249 : 보급로 dijkstra version]
 */

#include<bits/stdc++.h>
using namespace std;
int N;
int Data[100][100];
const int INF = 987654321;
int Dist[100][100];
int visited[100][100];
int answer;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        string s;cin>>s;
        for(int j=0;j<N;j++){
            Data[i][j] = s[j]-'0';
        }
    }
}
bool isWall(int x,int y){
    return x>=N ||y>=N || x<0 ||y<0;
}
class Point{
    public:
    int x;int y;int val;
    Point(int a,int b,int c){
        x=a;y=b;val=c;
    }
    bool operator<(const Point p)const{
        return val>p.val;
    }
};
void dijkstra(){
    int x = 0,y = 0;
    priority_queue<Point> pq;
    visited[0][0] =1;
    Dist[0][1] = Data[0][1];
    Dist[1][0] = Data[1][0];
    pq.push(Point(1,0,Dist[0][1]));
    pq.push(Point(0,1,Dist[1][0]));

    while(!pq.empty()){
        Point cur = pq.top();
        pq.pop();
        if(visited[cur.x][cur.y])continue;
        visited[cur.x][cur.y]=1;
        for(int d=0;d<4;d++){// adjacent of cur
            int nx = cur.x+dir[d][0];
            int ny = cur.y+dir[d][1];
            if(!isWall(nx,ny)){
                Dist[nx][ny] = min(Dist[nx][ny],Dist[cur.x][cur.y]+Data[nx][ny]);
                pq.push(Point(nx,ny,Dist[nx][ny]));
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        answer = INF;   
        memset(visited,0,sizeof(visited));
        for(int i=0;i<N;i++)for(int j=0;j<N;j++)Dist[i][j]=INF;
        Dist[0][0] = 0;
        dijkstra();
        cout<<"#"<<tc<<" "<<Dist[N-1][N-1]<<"\n";
        
    }
}