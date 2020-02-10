#include<bits/stdc++.h>
using namespace std;
int N;
vector<int> point(100,0);
bool check[100*100+1];
int answer;
void dfs(int pos,int cur_point){
    if(pos==N){
        return;
    }
    if(!check[cur_point]){
        answer++;
        cout<<answer<<" ";
        check[cur_point]=1;
    }
    
    dfs(pos+1,cur_point + point[pos]);//맞은 경우
    dfs(pos+1,cur_point);//틀린 경우
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    for(int t_case=1; t_case<=t;t_case++){
        cin>>N;
        answer=0;
        memset(check,0,sizeof(check));
        for(int i=0;i<N;i++){
            cin>>point[i];
        }  
        dfs(0,0);
        cout<<"#"<<t_case<<" "<<answer<<"\n";
    }
}