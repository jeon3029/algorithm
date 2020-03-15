/**
 * @author [jeon3029]
 * @email [jeon3029@naver.com]
 * @create date 2020-03-15 18:09:29
 * @modify date 2020-03-15 19:29:50
 * @desc [2517 달리기 segtree version]
 */
#include<bits/stdc++.h>
using namespace std;
class Num{
    public:
    int val;int pos;
    Num(int a,int b){
        val = a;pos = b;
    }
    Num(){}
};
int tree[1<<20];
int base;
const int SZ=500000;
int N;
Num Data[SZ];
int range_sum(int a,int b){
    int sum=0;
    while(a<b){
        if(a%2==1)  sum+=tree[a],a++;
        if(b%2==0) sum+=tree[b],b--;
        a>>=1;
        b>>=1;
    }
    if(a==b)sum+=tree[a];
    return sum;
}
void update(int a,int b){
    tree[a] = b;
    a>>=1;
    while(a){
        tree[a] = tree[2*a]+tree[2*a+1];
        a>>=1;
    }
}
void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>Data[i].val;
        Data[i].pos=i;
    }
}
bool valCmp(Num a,Num b){
    return a.val<b.val;
}
bool posCmp(Num a,Num b){
    return a.pos<b.pos;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    sort(Data,Data+N,valCmp);
    for(int i=0;i<N;i++){
        Data[i].val=i;
    }
    sort(Data,Data+N,posCmp);
    for(base=1;base<N;base<<=1);
    for(int i=0;i<N;i++){
        update(base+Data[i].val,1);
        cout<<range_sum(base+Data[i].val+1,base+N)+1<<"\n";
    }
}