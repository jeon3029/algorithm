#include<bits/stdc++.h>
using namespace std;
int rand(int a,int b){
    return a+rand()%(b-a+1);
}
int main(int argc,char** argv){
    srand(atoi(argv[1]));
    int n = rand(2,20);
    cout<<n<<"\n";
    set<int> used;
    for(int i=0;i<n;i++){
        int x;
        do{
            x=rand(1,20);
        }while(used.count(x));
        cout<<x<<" ";
        used.insert(x);
    }puts("");
}