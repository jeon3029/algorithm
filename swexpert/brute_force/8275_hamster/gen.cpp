#include<bits/stdc++.h>
using namespace std;
int rand(int a,int b){
    return a+rand()%(b-a+1);
}
int main(int argc,char** argv){
    srand(atoi(argv[1])+10000);
    int t = rand(1,10);
    cout<<t<<"\n";
    while(t--){
        int n=rand(2,6);
        int x=rand(1,10);
        int m=rand(1,2);
        cout<<n<<" "<<x<<" "<<m<<"\n";
        for(int i=0;i<m;i++){
            int l = rand(1,n);
            int r = rand(l,n);
            int num = rand(1,x*6);
            cout<<l<<" "<<r<<" "<<num<<"\n";
        }puts("");
    }
}