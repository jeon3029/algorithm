/**
 * @author [jeon3029]
 * @email [jeon3029@naver.com]
 * @create date 2020-03-12 13:58:07
 * @modify date 2020-03-12 13:58:07
 * @desc [simple union find]
 */
#include<bits/stdc++.h>
using namespace std;
int p[20];
void make_set(int x){
    p[x]=x;
}
int find_set(int x){
    if(x==p[x])return x;
    else return find_set(p[x]);
}
void union_set(int x,int y){
    p[find_set(y)] = find_set(x);
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
    cout<<find_set(4)<<endl;
    cout<<find_set(5)<<endl;
}