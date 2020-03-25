#include<bits/stdc++.h>
using namespace std;
int tree[30][2];
int N;
void preorder(int node){
    cout<<char(node+'A'-1);
    if(tree[node][0]){
        preorder(tree[node][0]);
    }
    if(tree[node][1]){
        preorder(tree[node][1]);
    }
}
void inorder(int node){
    if(tree[node][0]){
        inorder(tree[node][0]);
    }
    cout<<char(node+'A'-1);
    if(tree[node][1]){
        inorder(tree[node][1]);
    }
}
void postorder(int node){
    if(tree[node][0]){
        postorder(tree[node][0]);
    }
    if(tree[node][1]){
        postorder(tree[node][1]);
    }
    cout<<char(node+'A'-1);
}
int main(){
    cin>>N;
    while(N--){
        char a,b,c;
        cin>>a>>b>>c;
        if(b!='.'){
            tree[a-'A'+1][0] = b-'A'+1;
        }
        if(c!='.'){
            tree[a-'A'+1][1] = c-'A'+1;
        }
    }
    preorder(1);cout<<"\n";
    inorder(1);cout<<"\n";
    postorder(1);cout<<"\n";
}