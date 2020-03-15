/**
 * @author [jeon3029]
 * @email [jeon3029@naver.com]
 * @create date 2020-03-15 16:54:32
 * @modify date 2020-03-15 16:54:32
 * @desc [백준 2517 달리기 merger version]
 */
#include<bits/stdc++.h>
using namespace std;
const int SZ = 500000;
class Num{
    public:
    int val;int pos;
    Num(int a,int b){
        val = a;pos = b;
    }
    Num(){}
};
int N;
Num Data[SZ];
Num Sorted[SZ];
int Rank[SZ];
void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        int temp;cin>>temp;
        Data[i] = Num(temp,i);
        Rank[i] = i;
    }
}
void merge_sort(int l,int r){
    if(l>=r)return;
    int mid = (l+r+1)/2;
    int ll=l;
    int rr=mid;
    int cnt = l;
    while(ll<mid && rr<=r){
        if(Data[ll].val>Data[rr].val){
            Sorted[cnt++] = Data[ll++];
        }
        else{
            Sorted[cnt++] = Data[rr];
            Rank[Data[rr++].pos] -= mid-ll;
        }
    }
    while(ll<mid)Sorted[cnt++]=Data[ll++];
    while(rr<=r)Sorted[cnt++]=Data[rr++];
    for(int i=l;i<=r;i++)Data[i] = Sorted[i];
}
void merge(int l,int r){
    if(l>=r)return;
    int mid = (l+r+1)/2;
    merge(l,mid-1);
    merge(mid,r);
    merge_sort(l,r);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    merge(0,N-1);
    for(int i=0;i<N;i++){
        cout<<Rank[i]+1<<"\n";
    }
}
