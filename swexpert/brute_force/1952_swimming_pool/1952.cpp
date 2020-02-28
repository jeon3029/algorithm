#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int P[4];
int M[12];
int H[12];
int answer;
int price(){
    int sum=0;
    for(int i=0;i<12;i++){
        if(sum>answer)return INF;
        if(H[i]==0){
            sum+=P[0]*M[i];
        }
        else if(H[i]==1){
            sum+=P[1];
        }
        else{
            sum+=P[2];
            i+=2;
        }
    }
    return sum;
}
int calc(int order){
    for(int i=0;i<12;i++){
        int num = order %3;
        order/=3;
        if(num==0){
            if(M[i]*P[0]>P[1])return INF;
            H[i]=0;//일할
        }
        else if(num==1){
            H[i]=1;//월할
        }
        else if(num==2){
            H[i]=2;
            i+=2;
        }
    }
    return price();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        for(int i=0;i<4;i++){
            cin>>P[i];
        }
        for(int i=0;i<12;i++){
            cin>>M[i];
        }
        answer=P[3];
        for(int i=0;i<(531441);i++){//531441 = 3^^12
            answer = min(answer,calc(i));
        }
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
}