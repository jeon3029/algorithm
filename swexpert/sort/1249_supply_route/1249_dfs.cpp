/**
 * @author [jeon3029]
 * @email [jeon3029@naver.com]
 * @create date 2020-03-13 12:51:45
 * @modify date 2020-03-13 15:12:24
 * @desc [1249 보급로 dfs version]
 */
#include<bits/stdc++.h>
using namespace std;
int N;
int Data[100][100];
const int INF = 987654321;
int Dist[100][100];
int answer;
void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        string s;cin>>s;
        for(int j=0;j<N;j++){
            Data[i][j] = s[j]-'0';
        }
    }
}
bool isWall(int x,int y){
    return x>=N ||y>=N || x<0 ||y<0;
}
void dfs(int x,int y,int d,int sum){
    if(x==N-1 && y==N-1){
        answer = min(answer,sum);
        return;
    }
    if(sum>answer)return;
    if(sum>=Dist[x][y])return;
    Dist[x][y] = sum;
    if(!isWall(x+1,y)){
        dfs(x+1,y,d+1,sum+Data[x+1][y]);
    }
    if(!isWall(x,y+1)){
        dfs(x,y+1,d+1,sum+Data[x][y+1]);
    }
    if(!isWall(x-1,y)){
        dfs(x-1,y,d+1,sum+Data[x-1][y]);
    }
    if(!isWall(x,y-1)){
        dfs(x,y-1,d+1,sum+Data[x][y-1]);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        for(int i=0;i<N;i++)for(int j=0;j<N;j++)Dist[i][j]=INF;
        answer = INF;
        int x=0,y=0;
        int sum = 0;
        while(1){//greedy answer : only think right and down direction
            if(x==N-1 && y==N-1){
                answer=sum;break;
            }
            if(!isWall(x+1,y) && !isWall(x,y+1)){
                if(Data[x+1][y]>Data[x][y+1]){
                    sum+=Data[x+1][y];
                    x++;
                }
                else{
                    sum+=Data[x][y+1];
                    y++;
                }
            }
            else if(!isWall(x+1,y) && isWall(x,y+1)){
                sum+=Data[x+1][y];
                x++;
            }
            else{
                sum+=Data[x][y+1];
                y++;
            }
        }
        dfs(0,0,1,0);
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
}