#include<bits/stdc++.h>
using namespace std;
int N,M,K;
int answer=0;
class Virus{
    public:
    int pos;
    int val;int dir;
    Virus(int a,int b,int c,int d){
        pos=a*N+b;
        val=c;dir=d;
    }
};
vector<Virus> V;
bool inZone(int pos){
    return (pos/N)==0||pos/N==(N-1)||(pos%N)==0 ||(pos%N)==(N-1);
}
int changeD(int d){
    if(d==1)return 2;
    else if(d==2)return 1;
    else if(d==3)return 4;
    else return 3;
}
void input(){
    cin>>N>>M>>K;
    V.clear();
    for(int i=0;i<K;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        answer+=c;
        V.push_back(Virus(a,b,c,d));
    }
}
bool cmp(Virus a,Virus b){
    if(a.pos==b.pos)return a.val>b.val;
    return a.pos<b.pos;
}
void calc(){
    int dir[5] = {0,-N,N,-1,1};
    for(int i=0;i<V.size();i++){
        int np = V[i].pos+dir[V[i].dir];
        if(inZone(np)){
            V[i].dir = changeD(V[i].dir);
            answer -= (V[i].val - (V[i].val/2));
            V[i].val /= 2;
            if(V[i].val==0){
                V.erase(V.begin()+i);
                i--;
                continue;
            }
        }
        V[i].pos=np;
    }
    sort(V.begin(),V.end(),cmp);
    for(int i=0;i<V.size()-1;i++){
        if(V[i].pos==V[i+1].pos){
            V[i].val+=V[i+1].val;
            V.erase(V.begin()+i+1);
            i--;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        answer=0;
        input();
        for(int i=0;i<M;i++){
            calc();
        }
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
}