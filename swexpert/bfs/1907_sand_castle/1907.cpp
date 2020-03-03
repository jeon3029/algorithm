#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int N,M;
short Data[1001][1001];
short outer[1000001][2];
int answer;
int dir[8][2]={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
void input(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string s;cin>>s;
        for(int j=0;j<M;j++){
            if(s[j]=='.')Data[i][j]=0;
            else Data[i][j]=s[j]-'0';
        }
    }
}
inline bool isWall(int x,int y){
    return x<0||y<0||x>=N||y>=M;
}
int calc(){
    int cnt=0;
    int len=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(Data[i][j]==0) {
                outer[len][0]=i;outer[len][1]=j;
                len++;
            }
        }
    }
    int layer=0;
    for(int i=0;i<len;i++){
        pi cp={outer[i][0],outer[i][1]};
        for(int d=0;d<8;d++){
            int nx=cp.first+dir[d][0];
            int ny=cp.second+dir[d][1];
            if(!isWall(nx,ny) && Data[nx][ny]>0){
                Data[nx][ny]--;
                if(!Data[nx][ny]){
                    outer[len+layer][0]=nx;
                    outer[len+layer][1]=ny;
                    layer++;
                }
            }
        }
        if(i==len-1){
            if(layer){
                len+=layer;
                layer=0;
                cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        answer=calc();
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
}