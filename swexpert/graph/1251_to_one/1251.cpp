#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int N;
pi Data[1000];
long long Map[1000][1000];
double E;
void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>Data[i].first;
    }
    for(int i=0;i<N;i++){
        cin>>Data[i].second;
    }
    cin>>E;
}
long long getD(pi a,pi b){
    return pow(abs(a.first-b.first),2)+pow(abs(a.second-b.second),2);
}
int findRoot(vector<int> p,int i){
    if(p[i]==-1)return i;
    return findRoot(p,p[i]);
}
void doUnion(vector<int> &p,int x,int y){
    int xRoot = findRoot(p,x);
    int yRoot = findRoot(p,y);
    p[xRoot]=yRoot;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        long long answer=0;
        priority_queue<pair<long long,pi>> q;
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                long long d = getD(Data[i],Data[j]);
                Map[i][j]=d;
                q.push({-Map[i][j],{i,j}});
            }
        }
        vector<int> parent(N,-1);
        int cnt=0;
        while(cnt<N-1){
            long long d = q.top().first;
            pi p=q.top().second;
            q.pop();
            int x = findRoot(parent,p.first);
            int y = findRoot(parent,p.second);
            if(x==y){//cycle
                continue;
            }
            else{//union
                doUnion(parent,x,y);
                cnt++;
                answer-=d;
            }
        }
        cout<<"#"<<tc<<" "<<(long long)round(answer*E)<<"\n";
    }
}