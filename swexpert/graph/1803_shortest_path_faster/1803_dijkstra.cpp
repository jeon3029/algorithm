#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
const ll INF =987654321234; 
int N,M;
int sp,ep;
vector<vector<pil>> G;
ll Dist[100001]; 
int visited[100001];
void dijkstra(){
    for(int i=1;i<=N;i++){
        Dist[i] = INF;
    }
    memset(visited,0,sizeof(visited));
    priority_queue<pli> pq;//dist, point
    Dist[sp]=0;
    visited[sp]=0;
    for(int i=0;i<G[sp].size();i++){
        Dist[G[sp][i].first] = G[sp][i].second;
        pq.push({
            -G[sp][i].second,
            G[sp][i].first
        });
    }
    while(!pq.empty()){
        int cur = pq.top().second;
        ll val = -pq.top().first;
        pq.pop();
        if (visited[cur])
            continue;
        visited[cur]=1;
        for(int i=0;i<G[cur].size();i++){
            int next = G[cur][i].first;
            if(Dist[next]> val + G[cur][i].second){
                Dist[next] = val + G[cur][i].second;
                pq.push({-Dist[next],next});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        cin>>N>>M>>sp>>ep;
        G.clear();
        G = vector<vector<pil>>(N+1);
        for(int i=0;i<M;i++){
            int a,b,c;
            cin>>a>>b>>c;
            G[a].push_back({b,c});
            G[b].push_back({a, c});
        }
        dijkstra();
        cout<<"#"<<tc<<" "<<Dist[ep]<<"\n";
    }
}