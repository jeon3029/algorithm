#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int Data[10][10];
int N;
vector<pi> points;
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
int calc(vector<int> p){
    int answer = 0;
    // pi cur=startP;
    // for(auto it:p){
    //     answer+=getD(cur,points[it]);
    //     if(answer>ans)return 987654321;
    //     cur=points[it];
    // }
    answer +=getD(startP,points[p[0]]);
    for(int i=0;i<N-1;i++){
        answer+=Data[p[i]][p[i+1]];
        if(answer>ans)return 987654321;
    }
    answer+=getD(points[p[N-1]],endP);
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        vector<int> permu;
        ans=987564321;
        for(int i=0;i<N;i++){
            permu.emplace_back(i);
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i!=j){
                    Data[i][j]=getD(points[i],points[j]);
                }
            }
        }
        do{
            int cur = calc(permu);
            if(ans>cur)ans=cur;
        }while(next_permutation(permu.begin(),permu.end()));
        cout<<"#"<<tc<<" "<<ans<<"\n";
    }
}