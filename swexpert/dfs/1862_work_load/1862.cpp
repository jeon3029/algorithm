#include<bits/stdc++.h>
using namespace std;
int N;
double work[16][16];
double Max;
int visited[16];
void dfs(int pos,double tot){
    if(tot <=Max){
        return;
    }
    if(pos == N){
        Max = max(Max,tot);
        return;
    }
    for(int i=0;i<N;i++){
        if(!visited[i]){
            visited[i] = 1;
            dfs(pos+1,tot*work[pos][i]);
            visited[i] = 0;
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&N);
        memset(visited,0,sizeof(visited));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                int temp;scanf("%d",&temp);
                work[i][j] = temp/100.0;
            }
        }
        Max = 0;
        dfs(0,1);
        printf("#%d %.6lf\n",t,Max*100);
    }
}