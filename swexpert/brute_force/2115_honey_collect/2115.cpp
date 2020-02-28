#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int N,M,C;
int Data[10][10];
using namespace std;
int visited[10][10];
void input(){
    cin>>N>>M>>C;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>Data[i][j];
        }
    }
}
int calc(int x,int st){
    int answer=0;
    for(int order=0;order<(0x1<<M);order++){//all the cases
        int sum=0;
        int sq_sum=0;
        for(int i=0;i<M;i++){
            if(order&(0x1<<i)){
                sum+=Data[x][st+i];
                sq_sum+=Data[x][st+i]*Data[x][st+i];
                if(sum>C)break;
            }
        }
        if(sum>C)continue;
        else{
            answer = max(answer,sq_sum);
        }
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        int answer = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<=N-M;j++){//choose first one
                memset(visited[i]+j,1,sizeof(int)*M);
                int s1 = calc(i,j);
                int s2=0;
                for(int a=i;a<N;a++){
                    for(int b=0;b<=N-M;b++){
                        if(!visited[a][b] && !visited[a][b+M-1]){
                            s2=max(s2,calc(a,b));
                        }
                    }
                }
                memset(visited[i]+j,0,sizeof(int)*M);
                answer = max(answer,s1+s2);
            }    
        }
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
}