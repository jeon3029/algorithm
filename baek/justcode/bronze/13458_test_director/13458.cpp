#include<bits/stdc++.h>
using namespace std;
int Data[1000000];
int N;
int B,C;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>Data[i];
    }
    cin>>B>>C;
    long long sum=0;
    for(int i=0;i<N;i++){
        if(B>=Data[i]){
            sum+=1;
        }
        else{
            sum+=1+(Data[i]-B+C-1)/C;
        }
    }    
    cout<<sum<<"\n";
    return 0;
}
