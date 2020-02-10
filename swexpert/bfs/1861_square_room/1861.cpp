#include<bits/stdc++.h>
using namespace std;
int N;
int Map[1000][1000];
bool isWall(int x,int y){
    return x<0||y<0||x>=N||y>=N;
}
void calc(int x,int y,int len,int &answer){
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    bool possible = false;
    for(int d=0;d<4;d++){
        int nextX=x+dir[d][0];
        int nextY=y+dir[d][1]; 
        if(!isWall(nextX,nextY) && Map[nextX][nextY] == Map[x][y]+1){
            calc(nextX,nextY,len+1,answer);
            possible = true;
            break;
        }
    }
    if(!possible)
        answer = len;
}
int main(){
    int T;cin>>T;
    for(int t=1;t<=T;t++){
        cin>>N;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>Map[i][j];
            }
        }
        int answer = 0;
        int number = 987654321;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                int current;
                calc(i,j,1,current);
                if(answer<current){
                    answer = current;
                    number = Map[i][j];
                }
                else if(answer == current){
                    if (number > Map[i][j])number = Map[i][j];
                }
            }
        }
        cout<<"#"<<t<<" "<<number<<" "<<answer<<"\n";
    }
}