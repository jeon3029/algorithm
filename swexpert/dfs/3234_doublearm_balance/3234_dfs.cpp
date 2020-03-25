//952ms - in scoring site
#include<bits/stdc++.h>
using namespace std;
int N;
int answer = 0;
int power2[12] = {1,2,4,8,16,32,64,128,256,512,1024};
vector<int> combi;
void dfs(int pos,int lsum,int rsum,int tot){
    if(lsum<rsum)return;
    if(pos==N){
        answer++;
        return;
    }
    if( lsum<<1 >= tot){
        answer+=power2[N-pos];
        return;
    }
    dfs(pos+1,lsum+combi[pos],rsum,tot);
    dfs(pos+1,lsum,rsum+combi[pos],tot);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        cin>>N;
        combi.clear();
        combi = vector<int>(N);
        int sum=0;
        for(int i=0;i<N;i++){
            cin>>combi[i];
            sum+=combi[i];
        }
        sort(combi.begin(),combi.end());
        answer = 0;
        do{
            dfs(0,0,0,sum);
        }while(next_permutation(combi.begin(),combi.end()));
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
}