#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int INF = 987654321;
int answer = 0;
int sx,sy,ex,ey;
int rdir[2][2] = {{0,1},{0,-1}};
int cdir[2][2] = {{1,0},{-1,0}};
void input(){
    cin>>sx>>sy>>ex>>ey;
}
void bfs(){
    queue<pair<pi,pi>>q;//val,dir,x,y
    q.push({{0,0},{sx,sy}});
    q.push({{0,1},{sx,sy}});
    while(!q.empty()){
        int val = q.front().first.first;
        int dir = q.front().first.second;
        pi cp = q.front().second;
        q.pop();
        if(cp.first==ex && cp.second==ey){
            answer = val;
            return;
        }
        if(answer!=INF)return;
        int nx,ny;
        if(dir==0){
            if(ex>cp.first){
                nx=cp.first+1;
            }
            else{
                nx=cp.first-1;
            }
            ny=cp.second;
        }
        else{
            if(ey>cp.second){
                ny=cp.second+1;
            }
            else{
                ny=cp.second-1;
            }
            nx=cp.first;
        }
        q.push({{val+1,!dir},{nx,ny}});
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        answer = INF;
        bfs();
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
}