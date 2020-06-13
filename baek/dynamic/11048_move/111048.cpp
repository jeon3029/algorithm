#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
//predefined
int N,M;
int visited[1001][1001];
int Data[1001][1001];
void input(){
    cin>>N>>M;
    rep(i,0,N)rep(j,0,M){
        cin>>Data[i][j];
    }
}
void dp(){
    rep(i,0,N)rep(j,0,M){
        if(i==0){
            if(j==0)visited[i][j] = Data[i][j];
            else{
                visited[i][j] = visited[i][j-1] + Data[i][j];
            }
        }
        else{
            if(j==0){
                visited[i][j] = visited[i-1][j] + Data[i][j];
            }
            else{
                visited[i][j] = max({visited[i-1][j],visited[i-1][j-1],visited[i][j-1]}) + Data[i][j];
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    dp();
    cout<<visited[N-1][M-1]<<"\n";
}