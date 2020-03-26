#include<bits/stdc++.h>
using namespace std;
int Data[20][2];
int N;
long long answer;
void solve(int pos,int count,long long x,long long y){
    if(count==N/2 && pos == N){
        long long val = x*x + y*y;
        answer = min(answer,val);
        return;
    }
    if(count>N/2)return;
    if((N/2-count)>N-pos)return;
    if(pos==N)return;
    solve(pos+1,count+1,x+Data[pos][0],y+Data[pos][1]);
    solve(pos+1,count,x-Data[pos][0],y-Data[pos][1]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>Data[i][0]>>Data[i][1];
        }
        answer = 9876543210123;
        solve(0,0,0,0);
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
}