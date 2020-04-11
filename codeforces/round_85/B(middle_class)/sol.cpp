#include<bits/stdc++.h>
using namespace std;
int N,X;
long long Data[100001];
void input(){
    cin>>N>>X;
    for(int i=0;i<N;i++){
        cin>>Data[i];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        int answer = 0;
        sort(Data,Data+N);
        long long sum = 0;//int아님을 주의
        int cnt = 0;
        for(int i=N-1;i>=0;i--){
            if(((sum + Data[i]) / (cnt+1))>=X){
                answer++;
                cnt++;
                sum+=Data[i];
            }
            else break;
        }
        cout<<answer<<"\n"; 
    }
    return 0;
}