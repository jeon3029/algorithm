/**
 * @author [jeon3029]
 * @email [jeon3029@naver.com]
 * @create date 2020-04-16 16:53:03
 * @desc [implement]
 */
#include<bits/stdc++.h>
using namespace std;

int N;
string s;
int Data[200][200];
void input(){
    cin>>N;
    cin>>s;
    memset(Data,0,sizeof Data);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    int x = 53,y=53;
    int d = 1;//동남서북
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int min_x=53,min_y=53;
    int max_x=53,max_y=53;
    Data[x][y] = 1;
    for(int i=0;i<N;i++){
        char c = s[i];
        if(c=='R'){
            d = (d+1)%4;
        }
        else if(c=='L'){
            d = (d+3)%4;
        }
        else{
            x = x+dir[d][0];
            y = y+dir[d][1];  
        }
        Data[x][y] = 1;
        if(min_x>x)min_x = x;
        if(min_y>y)min_y = y;
        if(max_x <x)max_x = x;
        if(max_y <y)max_y = y;
    }
    for(int i=min_x;i<=max_x;i++){
        for(int j=min_y;j<=max_y;j++){
            if(Data[i][j]==1)cout<<".";
            else cout<<"#";
        }
        cout<<"\n";
    }
}