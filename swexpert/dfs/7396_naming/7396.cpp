/**
 * @author [jeon3029]
 * @email [jeon3029@naver.com]
 * @create date 2020-03-12 12:07:29
 * @modify date 2020-03-13 02:07:29
 * @desc [swexpert : 7396[종구의 딸이름 짓기]
 * 시작점으로부터 같은 거리상에 있는 것들중 제일 작은 것 골라서 도착지점까지 진행
 */
#include<bits/stdc++.h>
using namespace std;
int N,M;
char Data[2000][2000];
int visited[2000][2000];
string answer;
void input(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>Data[i];
    }
}
bool isWall(int x,int y){
    return x>=N||y>=M;
}
class Point{
    public:
    int x;int y;char val;
    Point(int a,int b,char c){
        x=a;y=b;val=c;
    }
    bool operator<(const Point p)const{
        return val>p.val;
    }
};
void bfs(){
    priority_queue<Point> pq;
    vector<Point> list;
    pq.push(Point(0,0,Data[0][0]));
    visited[0][0] = 1;
    while(!pq.empty()){
        int size = pq.size();
        Point first = pq.top();
        for(int i=0;i<size;i++){
            Point now = pq.top();
            pq.pop();
            if(first.val == now.val){
                if(!isWall(now.x,now.y+1) && !visited[now.x][now.y+1]){
                    list.push_back(Point(now.x,now.y+1,Data[now.x][now.y+1]));
                    visited[now.x][now.y+1]=1;
                }
                if(!isWall(now.x+1,now.y) && !visited[now.x+1][now.y]){
                    list.push_back(Point(now.x+1,now.y,Data[now.x+1][now.y]));
                    visited[now.x+1][now.y]=1;
                }
            }
            else{break;}
        }
        pq = priority_queue<Point>();
        for(int i=0;i<list.size();i++){
            pq.push(list[i]);
        }
        list.clear();
        answer+=first.val;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        memset(visited,0,sizeof(visited));
        answer = "";
        bfs();
        cout<<"#"<<tc<<" "<<answer<<endl;
    }
}