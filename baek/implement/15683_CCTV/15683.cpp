/**
 * @author [jeon3029]
 * @email [jeon3029@naver.com]
 * @create date 2020-04-07 22:39:42
 * @modify date 2020-04-07 23:31:53
 * @desc [구현문제]
 */
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int N,M;
vector<vector<int>> Data;
class CctvData{
public:
    int x;
    int y;
    int type;
    CctvData(int a,int b,int c){
        x=a;y=b;type=c;
    }
};
vector<CctvData> Cctv;
int N_Cctv;
vector<int> dir_cctv;
int answer = 0;//커버 가능 갯수 (출력과는 다름)

void input(){
    cin>>N>>M;
    Data=vector<vector<int>>(N,vector<int>(M,0));
    Cctv.clear();
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>Data[i][j];
            if(Data[i][j]>=1 && Data[i][j]<=5){
                Cctv.push_back(CctvData(i,j,Data[i][j]));
            }
        }
    }
    N_Cctv=Cctv.size();
}
void goEast(vector<vector<int>> &arr,int x,int y){
    for(int j=y+1;j<M;j++){
        if(arr[x][j]==6)return;
        else if(arr[x][j]==0)arr[x][j]=7;
        else continue;
    }
}
void goWest(vector<vector<int>> &arr,int x,int y){
    for(int j=y-1;j>=0;j--){
        if(arr[x][j]==6)return;
        else if(arr[x][j]==0)arr[x][j]=7;
        else continue;
    }
}
void goSouth(vector<vector<int>> &arr,int x,int y){
    for(int i=x+1;i<N;i++){
        if(arr[i][y]==6)return;
        else if(arr[i][y]==0)arr[i][y]=7;
        else continue;
    }
}
void goNorth(vector<vector<int>> &arr,int x,int y){
    for(int i=x-1;i>=0;i--){
        if(arr[i][y]==6)return;
        else if(arr[i][y]==0)arr[i][y]=7;
        else continue;
    }
}
//direction
//1 : 동 서 남 북 : 0,1,2,3
//2 : 동서  남북 : 0,1
//3 : 북동 동남 남서 서북 : 0,1,2,3
//4 : 서북동 북동남 동남서 남서북 : 0,1,2,3
//5 : 동서남북 : 0
void calc(){
    vector<vector<int>> tempData = Data;
    for(int i=0;i<N_Cctv;i++){
        int x = Cctv[i].x;
        int y = Cctv[i].y;
        int type=Cctv[i].type;
        if(type==1){
            switch(dir_cctv[i]){
                case 0:goEast(tempData,x,y);break;
                case 1:goWest(tempData,x,y);break;
                case 2:goSouth(tempData,x,y);break;
                case 3:goNorth(tempData,x,y);break;
            }
        }
        else if(type==2){
            switch(dir_cctv[i]){
                case 0:goEast(tempData,x,y);goWest(tempData,x,y);break;
                case 1:goSouth(tempData,x,y);goNorth(tempData,x,y);break;
            }
        }
        else if(type==3){
            switch(dir_cctv[i]){
                case 0:goEast(tempData,x,y);goNorth(tempData,x,y);break;
                case 1:goEast(tempData,x,y);goSouth(tempData,x,y);break;
                case 2:goSouth(tempData,x,y);goWest(tempData,x,y);break;
                case 3:goWest(tempData,x,y);goNorth(tempData,x,y);break;
            }
        }
        else if(type==4){
            switch(dir_cctv[i]){
                case 0:goEast(tempData,x,y);goWest(tempData,x,y);goNorth(tempData,x,y);break;
                case 1:goEast(tempData,x,y);goSouth(tempData,x,y);goNorth(tempData,x,y);break;
                case 2:goEast(tempData,x,y);goWest(tempData,x,y);goSouth(tempData,x,y);break;
                case 3:goWest(tempData,x,y);goSouth(tempData,x,y);goNorth(tempData,x,y);break;
            }
        }
        else if(type==5){
            goEast(tempData,x,y);goWest(tempData,x,y);goSouth(tempData,x,y);goNorth(tempData,x,y);
        }
    }
    int cnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(tempData[i][j]>0)cnt++;
        }
    }
    answer = max(cnt,answer);
}
void combi(int pos){
    if(pos==N_Cctv){
        calc();
        return;
    }
    if(Cctv[pos].type==1||Cctv[pos].type==3||Cctv[pos].type==4){
        for(int i=0;i<4;i++){
            dir_cctv[pos]=i;
            combi(pos+1);
        }
    }
    else if(Cctv[pos].type==2){
        for(int i=0;i<2;i++){
            dir_cctv[pos]=i;
            combi(pos+1);
        }
    }
    else{
        dir_cctv[pos]=0;
        combi(pos+1);       
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    dir_cctv=vector<int> (N_Cctv);
    combi(0);
    int output = N*M-answer;
    cout<<output<<"\n";
}