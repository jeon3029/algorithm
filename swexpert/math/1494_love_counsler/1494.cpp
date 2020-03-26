#include<bits/stdc++.h>
using namespace std;
int Data[20][2];
int N;
long long answer;
void solve(int pos,int visited,int count){
    if(count == N/2){
        long long val;
        long long x = 0;
        long long y = 0;
        for(int i=0;i<N;i++){
            if(visited & (1<<i)){
                x+=Data[i][0];
                y+=Data[i][1];
            }
            else{
                x-=Data[i][0];
                y-=Data[i][1];
            }
        }
        val = x*x + y*y;
        answer = min(answer,val);
        return;
    }
    if(pos==N)return;
    int temp = visited | 0x1<<pos;
    solve(pos+1,temp,count+1);
    solve(pos+1,visited,count);
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
        solve(0,0,0);
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
}