#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int to;
    int val;
    Node(int a,int b){
        to=a;
        val = b;
    }
};
int N,M;
int answer;
int visited[401];
vector<vector<Node>> G;
void input(){
    cin>>N>>M;
    G.clear();
    G=vector<vector<Node>>(N+1);
    for(int i=0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;
        G[a].push_back(Node(b,c));
    }
}
void dfs(int parent,int cur,int val){
    if(answer!=-1 && val>answer){
        return;
    }
    if(cur==parent && visited[cur]==1){
        answer=val;
        return;
    }
    if(visited[cur])return;
    visited[cur]=1;
    for(int i=0;i<G[cur].size();i++){
        Node &now=G[cur][i];
        dfs(parent,now.to,val+now.val);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        answer = -1;
        for(int i=1;i<=N;i++){
            memset(visited,0,sizeof(visited));
            dfs(i,i,0);
        }
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
}