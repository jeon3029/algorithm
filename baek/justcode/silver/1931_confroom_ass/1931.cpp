#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int SZ=1e6;
int N;
vector<pi> Data;
bool cmp(pi a, pi b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second<b.second;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++){
        int a,b;cin>>a>>b;
        Data.push_back({a,b});
    }
    sort(Data.begin(),Data.end(),cmp);
    int answer=0;
    int cur = -1;
    for(auto it:Data){
        int a = it.first;
        int b = it.second;
        if(a>=cur){
            answer++;
            cur=b;
        }
    }
    cout<<answer;
}