#include<bits/stdc++.h>
using namespace std;
int N,X,M;
class Order{
    public:
    int l;int r;int num;
    Order(int a,int b,int c){
        l=a;r=b;num=c;
    }
};
vector<Order> Chk;
vector<int> answer_order(6);
int cur[6];
int answer=0;
void input(){
    cin>>N>>X>>M;
    Chk.clear();
    for(int i=0;i<M;i++){
        int a,b,c;cin>>a>>b>>c;
        Chk.emplace_back(a-1,b-1,c);
        if(c>(b-a+1)*X)answer=-1;
    }
}
void calc(int order){
    int sum=0;
    for(int i=0;i<N;i++){
        int num = order%(X+1);
        order/=(X+1);
        cur[i]=num;
        sum+=num;
    }
    if(sum<answer)return;
    for(int i=0;i<M;i++){
        int c_sum=0;
        for(int j=Chk[i].l;j<=Chk[i].r;j++){
            c_sum+=cur[j];
        }
        if(c_sum!=Chk[i].num)return;
    }
    if(sum>answer){
        for(int i=0;i<N;i++)answer_order[i]=cur[i];
        answer=sum;
    }
    else if(sum==answer){
        for(int i=0;i<N;i++){
            if(cur[i]<answer_order[i]){
                // answer=sum;
                for(int i=0;i<N;i++)answer_order[i]=cur[i];
                return;
            }
            else if(cur[i]==answer_order[i])continue;
            else{
                return;
            }
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
        if(answer==-1){
            cout<<"#"<<tc<<" "<<"-1\n";continue;
        }
        for(int i=0;i<N;i++)answer_order[i]=0;
        int len = pow(X+1,N);
        for(int i=len-1;i>=0;i--){
            calc(i);
        }
        if(answer==0){
            cout<<"#"<<tc<<" "<<"-1\n";
        }
        else{
            cout<<"#"<<tc<<" ";
            for(int i=0;i<N;i++){
                cout<<answer_order[i]<<" ";
            }cout<<"\n";
        }
    }
}