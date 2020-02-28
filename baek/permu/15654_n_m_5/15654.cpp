#include<bits/stdc++.h>
using namespace std;
vector<int> Data;
vector<vector<int>> answer;
vector<int> visited;
int N,M;
void dfs(vector<int>current,int len){
    if(len==M){
        answer.push_back(current);
    }
    else{
        for(int i=0;i<Data.size();i++){
            if(!visited[i]){
                current.push_back(Data[i]);
                visited[i]=1;
                dfs(current,len+1);
                visited[i]=0;
                current.pop_back();
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        int t;cin>>t;
        Data.push_back(t);
    }
    sort(Data.begin(),Data.end());
    visited = vector<int>(N,0);
    dfs(vector<int>(),0);
    for(int i=0;i<answer.size();i++){
        for(int j=0;j<answer[i].size();j++){
            cout<<answer[i][j]<<" ";
        }cout<<"\n";
    }
    return 0;
}