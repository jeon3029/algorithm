#include<bits/stdc++.h>
using namespace std;
int Map[301][301];
int N,M;
vector<int> ice_count;
void input(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>Map[i][j];
        }
    }
}
bool isWall(int x,int y){
    return x<0||x>=N||y<0||y>=M;
}
int melt(){//returns count of ices
    vector<vector<int> > melting(N,vector<int>(M,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(Map[i][j]!=0){
                int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
                for(int d=0;d<4;d++){
                    int x = i+dir[d][0];
                    int y = j+dir[d][1];
                    if(!isWall(x,y) && Map[x][y]==0){
                        melting[i][j]++;
                    }
                }
            }
        }
    }
    int answer=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            Map[i][j]-=melting[i][j];
            if(Map[i][j]<0)Map[i][j]=0;
            if(Map[i][j]>0)answer++;
        }
    }
    return answer;
}
int count_ice(){
    vector<vector<int>> visited(N,vector<int>(M,0));
    int cnt = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(Map[i][j]!=0 && visited[i][j]==0){
                queue<pair<int,int>> q;
                if(cnt==1) return 2;
                cnt++;
                q.push(make_pair(i,j));
                while(!q.empty()){
                    
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    visited[x][y] = 1;
                    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
                    for(int d=0;d<4;d++){
                        int xx = x+dir[d][0];
                        int yy = y+dir[d][1];
                        if(!isWall(xx,yy) && visited[xx][yy]==0 && Map[xx][yy]!=0){
                            q.push(make_pair(xx, yy));
                            visited[xx][yy]=1;
                        }
                    }
                }
            }
        }
    }
    return cnt;
}
int main(int argc,char ** argv){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    int time;
    for(time=0;;time++){
        int ice = count_ice();
        if(ice==2){
            cout<<time;return 0;
        }
        int count = melt();
        if(count ==0){
            cout<<"0";return 0;
        }
    }
    return 0;
}