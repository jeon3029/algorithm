/**
 * @author [jeon3029]
 * @email [jeon3029@naver.com]
 * @create date 2020-04-19 17:34:15
 */
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
//predefined

int N,M;
int Data[500][500];
int answer = 0;
void input(){
    cin>>N>>M;
    rep(i,0,N)rep(j,0,M)cin>>Data[i][j];
}
bool isWall(int x,int y){
    return x<0||y<0||x>=N||y>=M;
}
/**
* 0000
**/
int type1(int x,int y){
    int ret = 0;
    if(!isWall(x,y+3)){
        int cur = Data[x][y]+Data[x][y+1]+Data[x][y+2]+Data[x][y+3];
        ret = max(ret,cur);
    }
    if(!isWall(x+3,y)){
        int cur = Data[x][y]+Data[x+1][y]+Data[x+2][y]+Data[x+3][y];
        ret = max(ret,cur);
    }
    return ret;
}
/**
* 00
* 00
**/
int type2(int x,int y){
    int ret = 0;
    if(!isWall(x+1,y+1)){
        ret = Data[x][y] +Data[x][y+1] +Data[x+1][y] +Data[x+1][y+1];
    }
    return ret;
}
/**
* 000
*   0
**/
int type3(int x,int y){
    int ret = 0;
    if(!isWall(x+1,y+2)){
        ret = max(ret,Data[x][y] +Data[x][y+1] +Data[x][y+2] +Data[x+1][y+2]);
    }
    if(!isWall(x+1,y+2)){
        ret = max(ret,Data[x][y] +Data[x][y+1] +Data[x][y+2] +Data[x+1][y]);
    }
    if(!isWall(x+1,y+2)){
        ret = max(ret,Data[x+1][y] +Data[x+1][y+1] +Data[x+1][y+2] +Data[x][y+2]);
    }
    if(!isWall(x+1,y+2)){
        ret = max(ret,Data[x+1][y] +Data[x+1][y+1] +Data[x+1][y+2] +Data[x][y]);
    }

    if(!isWall(x+2,y+1)){
        ret = max(ret,Data[x][y] +Data[x+1][y] +Data[x+2][y] +Data[x+2][y+1]);
    }
    if(!isWall(x+2,y+1)){
        ret = max(ret,Data[x][y+1] +Data[x+1][y+1] +Data[x+2][y+1] +Data[x+2][y]);
    }
    if(!isWall(x+2,y+1)){
        ret = max(ret,Data[x][y+1] +Data[x][y] +Data[x+1][y] +Data[x+2][y]);
    }
    if(!isWall(x+2,y+1)){
        ret = max(ret,Data[x][y+1] +Data[x][y] +Data[x+1][y+1] +Data[x+2][y+1]);
    }
    return ret;
}
/**
* 00
*  00
**/
int type4(int x,int y){
    int ret = 0;
    if(!isWall(x+1,y+2)){
        ret = max(ret,Data[x][y] +Data[x][y+1] +Data[x+1][y+1] +Data[x+1][y+2]);
    }
    if(!isWall(x+1,y+2)){
        ret = max(ret,Data[x+1][y] +Data[x][y+1] +Data[x+1][y+1] +Data[x][y+2]);
    }

    if(!isWall(x+2,y+1)){
        ret = max(ret,Data[x][y] +Data[x+1][y] +Data[x+1][y+1] +Data[x+2][y+1]);
    }
    if(!isWall(x+2,y+1)){
        ret = max(ret,Data[x][y+1] +Data[x+1][y+1] +Data[x+1][y] +Data[x+2][y]);
    }
    return ret;
}
/**
* 000
*  0
**/
int type5(int x,int y){
    int ret = 0;
    if(!isWall(x+1,y+2)){
        ret = max(ret,Data[x][y] +Data[x][y+1] +Data[x][y+2] +Data[x+1][y+1]);
    }
    if(!isWall(x+1,y+2)){
        ret = max(ret,Data[x+1][y] +Data[x+1][y+1] +Data[x+1][y+2] +Data[x][y+1]);
    }

    if(!isWall(x+2,y+1)){
        ret = max(ret,Data[x][y] +Data[x+1][y] +Data[x+2][y] +Data[x+1][y+1]);
    }
    if(!isWall(x+2,y+1)){
        ret = max(ret,Data[x][y+1] +Data[x+1][y+1] +Data[x+2][y+1] +Data[x+1][y]);
    }
    return ret; 
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    rep(i,0,N)rep(j,0,M){
        answer = max(answer,type1(i,j));
        answer = max(answer,type2(i,j));
        answer = max(answer,type3(i,j));
        answer = max(answer,type4(i,j));
        answer = max(answer,type5(i,j));
    }
    cout<<answer<<"\n";
}