#include<bits/stdc++.h>
#define SZ 16
#define f(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef pair<int,int> pi;
int N,M,D;
int Map[SZ][SZ];
int position;
void input(){
    cin>>N>>M>>D;
    f(i,N){
        f(j,M){
            cin>>Map[i][j];
        }
    }
}
int dis(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}
bool cmp(pi a,pi b){
    if(dis(a.first,a.second,N,position)==dis(b.first,b.second,N,position)){
        return a.second<b.second;
    }
    return dis(a.first,a.second,N,position)<dis(b.first,b.second,N,position);
}
int shoot_enemy(vector<int> archor){
    vector<pi>shooted;
    shooted.clear();
    int answer=0;
    for(int i=0;i<archor.size();i++){
        if(archor[i]==1){
            position = i;
            vector<pi> possible;
            possible.clear();
            for(int x=0;x<N;x++){
                for(int y=0;y<M;y++){
                    if(Map[x][y]==1 && dis(x,y,N,i)<=D){
                        possible.push_back({x,y});
                    }
                }
            }
            if(possible.size()==0)continue;
            sort(possible.begin(),possible.end(),cmp);
            shooted.push_back(possible[0]);
        }
    }
    for(auto it:shooted){
        if(Map[it.first][it.second]==1){
            answer++;
            Map[it.first][it.second]=0;
        }
    }
    return answer;
}
void move_down(){
    for(int i=N-1;i>=1;i--){
        for(int j=0;j<M;j++){
            Map[i][j] = Map[i-1][j];
        }
    }
    for(int i=0;i<M;i++){
        Map[0][i] = 0;
    }
}
int calc(vector<int> archor){
    int answer=0;
    for(int i=0;i<N;i++){
        answer += shoot_enemy(archor);
        move_down();
    }
    return answer;
}
int main(){
    cin.tie(0);cout.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    vector<int> combi(3,1);
    vector<int> added(M-3,0);
    combi.insert(combi.begin(),added.begin(),added.end());
    int Max = 0;
    sort(combi.begin(),combi.end());
    int temp[SZ][SZ];
    f(i,N){
        f(j,M){
            temp[i][j]=Map[i][j];
        }
    }
    do{
        f(i,N){
        f(j,M){
            Map[i][j]=temp[i][j];
        }
    }
        int cur = calc(combi);
        if(Max<cur)Max = cur;
    }while(next_permutation(combi.begin(),combi.end()));
    cout<<Max<<"\n";
}