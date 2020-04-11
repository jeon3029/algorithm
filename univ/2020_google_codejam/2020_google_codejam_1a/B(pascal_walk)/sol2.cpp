#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pi;
//predefined

int N;
void input(){
    cin>>N;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        cout<<"Case #"<<tc<<":\n";
        input();
        int row = min(30,N);
        vector<int> rows(row);
        N-=row;
        for(int i=row;i>=0;i--){
            if(N>=(0x1<<i)-1){
                N-=(0x1<<i)-1;
                rows[i]=1;
            }
        }
        row+=N;
        rows.resize(row);
        int side = 0;
        for(int i=0;i<row;i++){
            // cout<<"A : "<<rows[i]<<" , ";
            if(rows[i]){
                if(side){
                    for(int j=0;j<=i;j++){
                        cout<<i+1<<" "<<j+1<<"\n";
                    }
                }
                else{
                    for(int j=i;j>=0;j--){
                        cout<<i+1<<" "<<j+1<<"\n";
                    }
                }
                side^=1;
            }
            else{
                if(side){
                    cout<<i+1<<" "<<"1\n";
                }
                else{
                    cout<<i+1<<" "<<i+1<<"\n";
                }
            }
        }
    }
}