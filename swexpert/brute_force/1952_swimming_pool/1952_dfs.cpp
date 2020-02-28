#include<bits/stdc++.h>
using namespace std;
int P[4];
int M[12];
int answer;
void dfs(int cur,int len){
    if(len>=12){
        answer=cur;
    }
    if(cur+P[0]*M[len]<answer){
        dfs(cur+P[0]*M[len],len+1);
    }
    if(cur+P[1]<answer){
        dfs(cur+P[1],len+1);
    }
    if(cur+P[2]<answer){
        dfs(cur+P[2],len+3);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        for(int i=0;i<4;i++){
            cin>>P[i];
        }
        for(int i=0;i<12;i++){
            cin>>M[i];
        }
        answer=P[3];
        dfs(0,0);
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
}