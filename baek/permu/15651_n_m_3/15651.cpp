#include<bits/stdc++.h>
using namespace std;
vector<int> Data;
vector<vector<int>> answer;
int N,M;
void dfs(vector<int>current,int len){
    if(len==M){
        answer.push_back(current);
    }
    else{
        for(int i=0;i<Data.size();i++){
            current.push_back(Data[i]);
            dfs(current,len+1);
            current.pop_back();
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        Data.push_back(i);
    }
    sort(Data.begin(),Data.end());
    dfs(vector<int>(),0);
    for(int i=0;i<answer.size();i++){
        for(int j=0;j<answer[i].size();j++){
            cout<<answer[i][j]<<" ";
        }cout<<"\n";
    }
    return 0;
}