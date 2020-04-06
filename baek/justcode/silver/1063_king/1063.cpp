#include<bits/stdc++.h>
#define Xp first;
#define Yp second;
using namespace std;
typedef pair<int,int> pi;
pi king,dol;
int N;
vector<string> Move;
void input(){
    string s1,s2;
    cin>>s1>>s2;
    cin>>N;
    king.first = 7-(s1[1]-'1');
    king.second = s1[0]-'A';
    dol.first = 7-(s2[1]-'1');
    dol.second = s2[0]-'A';
    Move = vector<string>(N);
    for(int i=0;i<N;i++){
        cin>>Move[i];
    }
}
bool isWall(int x,int y){
    return x<0||y<0||x>=8||y>=8;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    int dir[8][2]={{0,1},{0,-1},{1,0},{-1,0},{-1,1},{-1,-1},{1,1},{1,-1}};
    for(int i=0;i<N;i++){
        // cout<<king.first<<king.second<<" "<<dol.first<<dol.second<<"\n";
        int d = 0;
        if(Move[i]=="R"){
            d=0;
        }
        else if(Move[i]=="L"){
            d=1;
        }
        else if(Move[i]=="B"){
            d=2;
        }
        else if(Move[i]=="T"){
            d=3;
        }
        else if(Move[i]=="RT"){
            d=4;
        }
        else if(Move[i]=="LT"){
            d=5;
        }
        else if(Move[i]=="RB"){
            d=6;
        }
        else if(Move[i]=="LB"){
            d=7;
        }
        int nx=king.first+dir[d][0];
        int ny=king.second+dir[d][1];
        if(isWall(nx,ny)){
            continue;
        }
        if(nx==dol.first && ny==dol.second){
            int nnx = nx+dir[d][0];
            int nny = ny+dir[d][1];
            if(isWall(nnx,nny)){
                continue;
            }
            else{
                dol.first=nnx;
                dol.second=nny;
                king.first=nx;
                king.second=ny;
            }
        }
        else{
            king.first=nx;
            king.second=ny;
        }
    }
    char k1,k2;
    k1=king.second+'A';
    k2=(7-king.first)+'1';
    char d1,d2;
    d1=dol.second+'A';
    d2=(7-dol.first)+'1';
    cout<<k1<<k2<<"\n"<<d1<<d2<<"\n";
}