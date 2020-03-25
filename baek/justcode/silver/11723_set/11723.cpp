#include<bits/stdc++.h>
using namespace std;
int Set=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int M;cin>>M;
    while(M--){
        string s;cin>>s;
        if(s=="add"){
            int t;cin>>t;
            Set |= 0x1<<t;
        }
        else if(s=="remove"){
            int t;cin>>t;
            Set &= ~(0x1<<t);
        }
        else if(s=="check"){
            int t;cin>>t;
            cout<<(bool)(Set & 0x1<<t) <<"\n";
        }
        else if(s=="toggle"){
            int t;cin>>t;
            Set ^= 0x1 <<t;
        }
        else if (s == "all"){
            Set = 0x7fffffff;
        }
        else if (s == "empty"){
            Set = 0;
        }
    }
}