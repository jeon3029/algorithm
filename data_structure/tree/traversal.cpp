#include<bits/stdc++.h>
using namespace std;
int Tree[100][2];
void pre_order(int d){
    cout<<d<<" ";
    if(Tree[d][0])pre_order(Tree[d][0]);
    if(Tree[d][1])pre_order(Tree[d][1]);
}
void in_order(int d){
    if(Tree[d][0])pre_order(Tree[d][0]);
    cout<<d<<" ";
    if(Tree[d][1])pre_order(Tree[d][1]);
}
void post_order(int d){
    if(Tree[d][0])pre_order(Tree[d][0]);
    if(Tree[d][1])pre_order(Tree[d][1]);
    cout<<d<<" ";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b;
        cin>>a>>b;
        if(!Tree[a][0]){
            Tree[a][0] = b;
        }
        else{
            Tree[a][1]=b;
        }
    }
    cout<<"pre order : ";pre_order(1);cout<<"\n";
    cout<<"in order : ";in_order(1);cout<<"\n";
    cout<<"post order : ";post_order(1);cout<<"\n";
}