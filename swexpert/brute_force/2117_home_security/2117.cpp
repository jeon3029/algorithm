#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define SZ(x) ((int)(x).size())
//predefined
int answer = 0;
int N,M;
int Map[20][20];
void input(){
    cin>>N>>M;
    rep(i,0,N)rep(j,0,N)cin>>Map[i][j];
}
bool isWall(int x,int y){
    return x<0||y<0||x>=N||y>=N;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        answer = 0;
        rep(i,0,N){
            rep(j,0,N){
                per(k,1,N+2){
                    int cost = (k*k) + ((k-1)*(k-1));
                    int count = 0;
                    int val = 0;
                    for(int x=i-k+1;x<=i;x++){
                        for(int y=j-val;y<=j+val;y++){
                            // cout<<x<<","<<y<<"\n";
                            if(isWall(x,y))continue;
                            if(Map[x][y]==1)count++;
                        }
                        val++;
                    }
                    val--;
                    for(int x=i+1;x<=i+k-1;x++){
                        val--;//check
                        for(int y=j-val;y<=j+val;y++){
                            // cout<<x<<","<<y<<"\n";
                            if(isWall(x,y))continue;
                            if(Map[x][y]==1)count++;
                        }
                    }
                    if(count * M >= cost){
                        if(count>answer)answer = count;
                    }
                }
            }
        }
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
}