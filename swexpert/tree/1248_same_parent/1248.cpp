#include<bits/stdc++.h>
using namespace std;
int N,E,c1,c2;
int Data[10001][3];//left,right,parent
void input(){
    cin>>N>>E>>c1>>c2;
    memset(Data,0,sizeof(Data));
    for(int i=0;i<E;i++){
        int a,b;cin>>a>>b;
        if(Data[a][0])Data[a][1]=b;
        else Data[a][0]=b;
        Data[b][2]=a;
    }
}
int search(int p){
    queue<int> q;
    q.push(p);
    int ans=0;
    while(!q.empty()){
        int c=q.front();q.pop();
        ans++;
        if(Data[c][0])q.push(Data[c][0]);
        if(Data[c][1])q.push(Data[c][1]);
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        vector<int> c1_p;
        vector<int> c2_p;
        while(c1!=0){
            c1_p.emplace_back(Data[c1][2]);
            c1=Data[c1][2];
        }
        while(c2!=0){
            c2_p.emplace_back(Data[c2][2]);
            c2=Data[c2][2];
        }
        int p=0;
        for(auto it1:c1_p){
            for(auto it2:c2_p){
                if(it1==it2){
                    p=it1;break;
                }
            }if(p)break;
        }
        int cnt = search(p);
        cout<<"#"<<tc<<" "<<p<<" "<<cnt<<"\n";
    }
}