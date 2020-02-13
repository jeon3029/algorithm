#include<bits/stdc++.h>
using namespace std;
int rand(int a,int b){
    return a+rand()%(b-a+1);
}
int main(int argc,char** argv){
    srand(atoi(argv[1]));
    int n = rand(3,16);
    cout<<n<<"\n";
    //set<int> used;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            x=rand(1,100);
            if(x==50) cout<<1<<" ";
            else cout<<0<<" ";
        }
        puts("");
    }
}