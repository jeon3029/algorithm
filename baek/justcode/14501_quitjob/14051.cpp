#include<bits/stdc++.h>
using namespace std;
const int SZ=15;
int N;
int Data[SZ][2];
int visited[SZ];
void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>Data[i][0]>>Data[i][1];
    }
}
int calc(int jobs){
    int sum=0;
    for(int i=0;i<N;i++){
        if(jobs & (0x1<<i)){
            if(i+Data[i][0]>N)return -1;
            for(int j=i;j<i+Data[i][0];j++){
                if(visited[j])return -1;
            }
            sum+=Data[i][1];
            for(int j=i;j<i+Data[i][0];j++){
                visited[j]=1;
            }
        }
    }
    return sum;
}
int main(){
    input();
    int ans = 0;
    for(int i=0;i<(0x1<<N);i++){
        memset(visited,0,sizeof(visited));
        ans = max(ans,calc(i));
    }
    cout<<ans<<"\n";
}