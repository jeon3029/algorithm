#include<bits/stdc++.h>
using namespace std;
string S;int N;
int answer;
void dfs(int cur,int len){
    if(len==N){
        int temp = atoi(S.c_str());
        answer = max(answer,temp);
        return;
    }
    for(int i=cur;i<S.size();i++){
        for(int j=i+1;j<S.size();j++){
            if(S[i]<=S[j]){
                swap(S[i],S[j]);
                dfs(i,len+1);
                swap(S[i],S[j]);
            }
        }
    }
}
int main(){
    int t;cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>S>>N;
        answer=0;
        dfs(0,0);
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
}