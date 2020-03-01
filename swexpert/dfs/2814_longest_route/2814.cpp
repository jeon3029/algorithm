#include<bits/stdc++.h>
using namespace std;
int N;
vector<vector<int>> G;
vector<int> visited;
int answer=1;
void input(){
    int M;
    cin>>N>>M;
    G = vector<vector<int>>(N,vector<int>());
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
}
void dfs(vector<int> cur,int pos){
    answer = max((int)cur.size(),answer);
    for(int i=0;i<G[pos].size();i++){
        int y = G[pos][i];
        if(!visited[y]){
            cur.push_back(y);
            visited[y]=1;
            dfs(cur,y);
            visited[y]=0;
            cur.pop_back();
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
        answer=-1;
        visited = vector<int>(N,0);
        for(int i=0;i<N;i++){
            visited[i]=1;
            dfs(vector<int>(),i);
            visited[i]=0;
        }
        cout<<"#"<<tc<<" "<<answer+1<<"\n";
    }
}
