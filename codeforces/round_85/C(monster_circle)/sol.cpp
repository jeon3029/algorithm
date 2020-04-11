#include<bits/stdc++.h>
using namespace std;
int N;
long long A[300001],B[300001];
void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i]>>B[i];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        long long answer = 0;
        for(int i=0;i<N;i++){
            answer+=max(0LL,A[(i+1)%N] - B[i]);
        }
        long long m = 1LL<<60;
        for(int i=0;i<N;i++){
            m = min({m,A[i],B[i]});
        }
        cout<<answer+m<<endl;
    }
}