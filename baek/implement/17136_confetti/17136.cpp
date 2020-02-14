#include<bits/stdc++.h>
#define N 10
#define f(i,n) for(int i=0;i<n;i++)
using namespace std;
vector<int> Confetti = {0,5,5,5,5,5};
vector<vector<int> > Map(N,vector<int>(N,0));
int cnt = 0;
int answer=1000;
void input(){
    f(i,N){
        f(j,N){
            cin>>Map[i][j];
            if(Map[i][j])cnt++;
        }
    }
}
void M_set(vector<vector<int>>& p,int x,int y,int num,int val){
    for(int i=x;i<x+num;i++){
        for(int j=y;j<y+num;j++){
            p[i][j]=val;
        }
    }
}
void dfs(vector<vector<int> > CMap,vector<int> Confe,int cx,int cy,int cur_cnt,int tot){
    if(cur_cnt>answer)return;
    if(tot==0){
        if(cur_cnt<answer)answer=cur_cnt;
        return;
    }
    if(cx==N){
        return;
    }
    int nx, ny;
    if(cy==9){
        nx=cx+1;
        ny=0;
    }
    else{
        nx=cx;
        ny=cy+1;
    }
    if(CMap[cx][cy]==0){
        dfs(CMap, Confe, nx, ny, cur_cnt, tot);
    }
    int num = 1;
    //find max size(num) form cx cy
    for(num=5;num>=1;num--){
        int temp=0;int f=0;
        for(int i=cx;i<cx+num;i++){
            for(int j=cy;j<cy+num;j++){
                if(i>=N||j>=N){
                    f=1;break;
                }
                assert(i>=0 && i<N);
                assert(j>=0 && j<N);
                if(CMap[i][j]==1)temp++;
                else{
                    f=1;break;
                }
            }
            if(f==1)break;
        }
        if(temp==num*num)break;
    }
    for(;num>=1;num--){
        M_set(CMap,cx,cy,num,0);
        if(Confe[num]==0)return;
        Confe[num]--;
        dfs(CMap,Confe,nx,ny,cur_cnt+1,tot-num*num);
        Confe[num]++;
        M_set(CMap,cx,cy,num,1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    dfs(Map,Confetti,0,0,0,cnt);
    if(answer==1000)answer=-1;
    cout<<answer<<"\n";
}
