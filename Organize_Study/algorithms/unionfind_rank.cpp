/**
 * @author [jeon3029]
 * @email [jeon3029@naver.com]
 * @create date 2020-03-12 13:58:10
 * @modify date 2020-03-12 13:59:02
 * @desc [union find faster]
 */
#include<bits/stdc++.h>
using namespace std;
int p[20];
int r[20];
void make_set(int x){
    p[x]=x;
    r[x] = 0;
}
int find_set(int x){
    if(x!=p[x]) p[x] = find_set(p[x]);
    else return p[x];
}
void link(int x,int y){
    if(r[x]>r[y]){
        p[y] = x;
    }
    else{
        p[x] = y;
        if(r[x]==r[y])r[y]++;
    }
}
void union_set(int x,int y){
    link(find_set(x),find_set(y));
}

int main(){
    int N=8;
    for(int i=1;i<=N;i++)make_set(i);
    union_set(1,3);
    union_set(2,3);
    union_set(5,6);
    union_set(6,8);
    union_set(1,5);
    union_set(6,7);
    for(int i=1;i<=N;i++){
        cout<<p[i]<<" ";
    }puts("");
    for(int i=1;i<=N;i++){
        cout<<r[i]<<" ";
    }puts("");
    cout<<find_set(4)<<endl;
    cout<<find_set(5)<<endl;
}