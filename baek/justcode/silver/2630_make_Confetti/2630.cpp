#include<bits/stdc++.h>
using namespace std;
const int SZ = 128;
int N;int Map[SZ][SZ];
int answer;
void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>Map[i][j];
            Map[i][j]=!Map[i][j];
        }
    }
}
bool check(int x,int y,int k){
    for(int i=x;i<x+k;i++){
        for(int j=y;j<y+k;j++){
            if(Map[i][j]==0){
                return 0;
            }
        }
    }
    return 1;
}
void dfs(int x,int y,int k){
    if(k==1){
        if(Map[x][y]==1)answer++;
    }
    else if(check(x,y,k)){
        answer++;
    }
    else {
        dfs(x,y,k/2);
        dfs(x+(k/2),y,k/2);
        dfs(x,y+(k/2),k/2);
        dfs(x+(k/2),y+(k/2),k/2);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    dfs(0,0,N);
    cout << answer<<"\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            Map[i][j]=!Map[i][j];
        }
    }
    answer=0;
    dfs(0,0,N);
    cout<<answer<<"\n";
}