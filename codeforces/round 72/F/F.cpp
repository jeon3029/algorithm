#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> a[10];
int visited[10];
bool bfs(int x,int y){
    queue<int> q;
    if(x==y)return 1;
    q.push(x);
    while(!q.empty()){
        int t = q.front();q.pop();
        visited[t]=1;
        for(int i=0;i<a[t].size();i++){
            if(!visited[a[t][i]])q.push(a[t][i]);
            if(a[t][i]==y)return 1;
        }
    }
    return 0;
}
int main(){
    int n,m;
    cin>>n>>m;
    int last=0;
    for(int i=0;i<m;i++){
        int t;int x,y;cin>>t>>x>>y;
        x=(x+last-1)%(n+1);
        y=(y+last-1)%(n+1);
        if(t==1){
            a[x].push_back(y);
            a[y].push_back(x);
        }
        else{
            fill(visited,visited+n+1,0);
            //cout<<bfs(x,y);
            last=bfs(x,y);
            cout<<x<<" "<<y<<" "<<last<<endl;
        }
    }
    cout<<endl;
}
