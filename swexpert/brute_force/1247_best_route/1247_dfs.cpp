#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int INF = 987654321;
int N;
vector<pi> points;
int visited[10];
pi startP;
pi endP;
int ans;
void input(){
    cin>>N;
    cin>>startP.first>>startP.second;
    cin>>endP.first>>endP.second;
    points.clear();
    for(int i=0;i<N;i++){
        int x,y;cin>>x>>y;
        points.emplace_back(x,y);
    }
}
int getD(pi a,pi b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}
void dfs(int sum,int len,int pos){
    if(len==N){
        sum+=getD(points[pos],endP);
        ans = min(ans,sum);
        return;
    }
    for(int i=0;i<points.size();i++){
        if(!visited[i]){
            int d;
            if(pos==-1){
                d=getD(startP,points[i]);
            }
            else {
                d=getD(points[pos],points[i]);
            }
            if(sum+d<ans){
                visited[i]=1;    
                dfs(sum+d,len+1,i);
                visited[i]=0;
            }
            else return;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        vector<int> permu;
        ans=INF;
        dfs(0,0,-1);
        cout<<"#"<<tc<<" "<<ans<<"\n";
    }
}