#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int Data[100000];
int N,M;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        cin>>N>>M;
        
        ll l=1,r=0;
        for(int i=0;i<N;i++){
            cin>>Data[i];
            r=max((int)r,Data[i]);
        }
        r=r*M;
        while(l<=r){
            ll m = (l+r)/2;
            ll tot = 0;
            for(int i=0;i<N;i++){
                tot+=m/Data[i];
            }
            if(tot<M){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        cout<<"#"<<tc<<" "<<l<<"\n";
    }
}