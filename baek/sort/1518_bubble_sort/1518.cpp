#include<bits/stdc++.h>
using namespace std;

int N;
int Data[500001];
int Sorted[500001];
long long answer = 0;
void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>Data[i];
    }
}
void merge(int* arr,int l, int r) {
    if (l >= r)return;
    int mid = (l + r + 1) / 2;
    int ll = l, rr = mid, idx = l;
    int cnt = 0;
    while (ll < mid&&rr <= r) {
        if (arr[ll] <= arr[rr]) {
            Sorted[idx] = arr[ll];
            idx++;ll++;
            answer+=cnt;
        }
        else {
            Sorted[idx] = arr[rr];
            idx++;rr++;
            cnt++;
        }
    }
    while (rr <= r){
        Sorted[idx] = arr[rr];
        idx++;rr++;
    }
    while (ll < mid){
        Sorted[idx] = arr[ll];
        idx++;ll++;
        answer+=cnt;
    }
    for (int i = l; i <= r; i++)arr[i] = Sorted[i];
}
void mergesort(int* arr,int l, int r) {
    if (l >= r) return;
    int mid = (l + r + 1) / 2;
    mergesort(arr,l, mid - 1);
    mergesort(arr,mid, r);
    merge(arr,l, r);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    mergesort(Data,0,N-1);
    cout<<answer<<"\n";
}   