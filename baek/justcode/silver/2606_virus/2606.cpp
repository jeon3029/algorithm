#include<bits/stdc++.h>
using namespace std;
int N,V;
vector<vector<int>> g(100);
vector<int> visited(100,0);
void input(){
    cin>>N>>V;
    for(int i=0;i<V;i++){
        int a,b;
        cin>>a>>b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
}
int bfs(int k){
    queue<int> q;
    q.push(k);
    int answer=0;
    while(!q.empty()){
        int x = q.front();q.pop();
        if(!visited[x]){
            answer++;
            visited[x]=1;
        }
        for(int i=0;i<g[x].size();i++){
            int y=g[x][i];
            if(!visited[y]){
                visited[y]=1;
                answer++;
                q.push(y);
            }
        }
    }
    return answer-1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    int ans = bfs(0);
    cout<<ans;
}