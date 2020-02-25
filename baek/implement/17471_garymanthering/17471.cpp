#include<bits/stdc++.h>
using namespace std;
int N;
vector<vector<int>> G(10,vector<int>());
int pop[10];
void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>pop[i];
    }
    for(int i=0;i<N;i++){
        int t;cin>>t;
        for(int j=0;j<t;j++){
            int a;
            cin>>a;
            G[i].push_back(a-1);
            G[a-1].push_back(i);
        }
    }
}
int calc(int order){
    vector<int> gary(N,0);
    int div1=-1,div2=-1;
    for(int i=0;i<N;i++){
        if(order&(0x1<<i)){
            gary[i]=1;
            div1=i;
        }
        else{
            gary[i]=2;
            div2=i;
        }
    }
    int sum1=0,sum2=0;
    queue<int> q;
    if(div1!=-1)q.push(div1);
    vector<int> visited(N,0);
    while(!q.empty()){
        int x = q.front();
        sum1+=pop[x];
        q.pop();
        visited[x]=1;
        for(int i=0;i<G[x].size();i++){
            int y=G[x][i];
            if(!visited[y]&&gary[y]==1){
                q.push(y);
                visited[y]=1;
            }
        }
    }
    if(div2!=-1)q.push(div2);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        sum2+=pop[x];
        visited[x]=1;
        for(int i=0;i<G[x].size();i++){
            int y=G[x][i];
            if(!visited[y]&&gary[y]==2){
                q.push(y);
                visited[y]=1;
            }
        }
    }
    for(int i=0;i<N;i++){
        if(!visited[i])return -1;
    }
    return abs(sum1-sum2);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    int answer = 987654321;
    for(int i=0;i<(0x1<<N);i++){       
        int temp=calc(i);
        // cout<<i<<" : "<<temp<<"\n";
        if(temp!=-1){
            answer = min(answer,temp);
        }
    }
    if(answer==987654321)cout<<"-1\n";
    else
    cout<<answer<<"\n";
}