/**
 * @author [jeon3029]
 * @email [jeon3029@naver.com]
 * @create date 2020-03-14 19:09:26
 * @modify date 2020-03-14 19:09:26
 * @desc [Prim V^2 version]
 * 참조 : https://www.weeklyps.com/entry/%ED%94%84%EB%A6%BC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Prims-algorithm
 */
#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int dist[10];
bool selected[10];
int N,V;
class Node{
    public:
    int v;
    int val;
    Node(int a,int b){
        v=a;val=b;
    }
};
vector<vector<Node>> G(10);
int mst_prim(){
    int ret = 0;
    for(int i=0;i<N;i++){
        dist[i]=INF;
        selected[i]=false;
    }
    dist[0] = 0;
    for(int i=0;i<N;i++){
        int min_dist = INF;
        int now = -1;
        for(int j=0;j<N;j++){
            if(!selected[j] && min_dist>dist[j]){
                min_dist = dist[j];
                now = j;
            }
        }
        if(now<0)return -1;//not possible
        ret+=min_dist;
        selected[now] = true;
        for(auto e:G[now]){
            dist[e.v]=min(dist[e.v],e.val);
        }
    }
    return ret;
}
int main(){
    cin>>N>>V;
    for(int i=0;i<V;i++){
        int a,b,c;
        cin>>a>>b>>c;
        G[a].push_back(Node(b,c));
        G[b].push_back(Node(a,c));
    }
    cout<<mst_prim()<<"\n";
    return 0;
}