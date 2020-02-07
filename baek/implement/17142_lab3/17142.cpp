#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
#include <cstring>
#define MAX 987654321
using namespace std;
class Virus{
public:
    int x; 
    int y;
    bool activated = false;
    int time = 0;
    Virus(int i,int j,int t=0){
        x=i,y=j,activated=false;
        time = t;
    }
};
vector<vector<int> >map;//0 empty, 1 wall 2 virus
vector<Virus> virus;
int N,M;
void input(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        vector<int> temp;
        for(int j=0;j<N;j++){
            int t;cin>>t;
            if(t==2){
                Virus v(i,j);
                virus.push_back(v);
            }
            temp.push_back(t);
        }
        map.push_back(temp);
    }
}
bool isActivated(int x,int y){
    for(int i=0;i<virus.size();i++){
        if(virus[i].x ==x&&virus[i].y==y){
            return virus[i].activated;
        }
    }
    return false;
}
bool isWall(int x,int y){
    if(x<0 ||y<0 ||x>=N||y>=N)return true;
    return false;
}
int spread_virus(vector<int> check){
    queue<Virus> q;
    int timeMap[N][N];
    memset(timeMap,0,sizeof(timeMap));
    for(int i=0;i<virus.size();i++){
        virus[i].activated = check[i];
        virus[i].time = 0;
        if(check[i]) q.push(virus[i]);
    }
    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    while(!q.empty()){
        Virus v = q.front();q.pop();
        for(int i=0;i<4;i++){
            int nextX = v.x+dir[i][0];
            int nextY = v.y+dir[i][1];
            if(isWall(nextX,nextY))continue;
            if(map[nextX][nextY]==0){
                if(timeMap[nextX][nextY]==0 ||timeMap[nextX][nextY]>timeMap[v.x][v.y]+1) {
                    timeMap[nextX][nextY] = v.time+1;
                    Virus temp(nextX,nextY,v.time+1);
                    q.push(temp);
                }
            }
            if(map[nextX][nextY]==2 && !isActivated(nextX,nextY)){//비활성된 바이러스는 벽이 아님!!
                if(timeMap[nextX][nextY]==0 ||timeMap[nextX][nextY]>timeMap[v.x][v.y]+1) {
                    timeMap[nextX][nextY] = v.time+1;
                    Virus temp(nextX,nextY,v.time+1);
                    q.push(temp);
                }
            }
        }
    }
    int max = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j]==0 && max<timeMap[i][j]) max = timeMap[i][j];
            if(map[i][j]==0 && timeMap[i][j]==0){//도달하지 못한 경우
                return -1;
            }
        }
    }
    return max;
}
int main(int argc, char **argv)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int answer = MAX;
    input();
    vector<int> check(virus.size(),0);
    for(int i=0;i<M;i++){
        check[i] = 1;
    }
    sort(check.begin(),check.end());
    do{
        int temp = spread_virus(check);
        if(temp==-1 && answer != MAX){
            continue;
        }
        else{
            if(temp!=-1 && temp<answer)answer = temp;
        }
    }while(next_permutation(check.begin(),check.end()));
    if(answer == MAX)answer = -1;
    cout<<answer<<endl;
    return 0;
}