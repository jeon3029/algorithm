#include<bits/stdc++.h>
#define f(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef pair<int,int> pi;
int N,K;
int Data[10][10];
int answer;
int height;
vector<pi> possible;
void input(){
    height=0;
    answer=0;
    possible.clear();
    cin>>N>>K;
    f(i,N){
        f(j,N){
            cin>>Data[i][j];
            height=max(height,Data[i][j]);
        }
    }
    f(i,N){
        f(j,N){
            if(Data[i][j]==height){
                possible.push_back({i,j});
            }
        }
    }
}
bool isWall(int x,int y){
    return x<0||y<0||x>=N||y>=N;
}
void bfs(){
    for(int i=0;i<possible.size();i++){
        int count=0;
        vector<vector<int>> length(N,vector<int>(N,0));
        int x = possible[i].first;int y=possible[i].second;
        if(Data[x][y]==height){
            queue<pair<pi,int>> q;
            q.push({{x,y},1});
            while(!q.empty()){
                pi cp =q.front().first;
                int len = q.front().second;
                q.pop();
                if(length[cp.first][cp.second]<len){
                    length[cp.first][cp.second]=len;
                }
                count = max(len,count);
                int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
                for(int d=0;d<4;d++){
                    int nx=cp.first+dir[d][0];
                    int ny=cp.second+dir[d][1];
                    if(!isWall(nx,ny)&&Data[nx][ny]<Data[cp.first][cp.second]&&length[nx][ny]<len+1){
                        length[nx][ny]=len+1;
                        q.push({{nx,ny},len+1});
                    }
                }
            }
        }
        answer=max(answer,count);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;cin>>T;
    f(tc,T){
        input();
        f(i,N){
            f(j,N){
                int temp = Data[i][j];
                f(k,K){
                    Data[i][j] = temp-k-1;
                    bfs();
                }
                Data[i][j]=temp;
            }
        }
        cout<<"#"<<tc+1<<" "<<answer<<"\n";
    }

}