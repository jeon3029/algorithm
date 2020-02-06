#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int r,c,m;
int answer;
class Shark{
    public:
    int speed;
    int dir;//1,2,3,4 : 북,남,동,서
    int size;
    bool isShark;
    Shark(){
        isShark = false;
    }
    void allocate(int sp,int d,int si){
        speed=sp;dir=d;size=si;
        isShark = true;
    }
    bool operator <(const Shark &t)const{
        return (this->size)<(t.size);
    }
};
vector<vector<Shark>> sharks;
void input(){
    cin>>r>>c>>m;
    for(int i=0;i<r+1;i++){
        vector<Shark> temp;
        for(int j=0;j<c+2;j++){
            Shark ttt;
            temp.push_back(ttt);
        }
        sharks.push_back(temp);
    }
    for(int i=0;i<m;i++){
        int a,b,s,d,e;
        cin>>a>>b>>s>>d>>e;
        if (d==3||d==4)s%=(c-1)*2;
        else s%=(r-1)*2;
        sharks[a][b].allocate(s,d,e);
    }
}
void chase_shark(int pos){
    for(int i=1;i<=r;i++){
        if(sharks[i][pos].isShark){
            sharks[i][pos].isShark = false;
            answer += sharks[i][pos].size;
            return;
        }
    }
}
bool isWall(int x,int y){
    if(x<=0 || y<=0 || x>r||y>c)return true;
    else return false;
}
int changedir(int d){
    if(d==1)return 2;
    else if(d==2)return 1;
    else if(d==3)return 4;
    else if(d==4)return 3;
    else return 0;
}
void move_shark(){
    vector<vector<Shark>> new_sharks;
    for(int i=0;i<r+1;i++){//initiate new_shark
        vector<Shark> temp;
        for(int j=0;j<c+2;j++){
            Shark ttt;
            temp.push_back(ttt);
        }
        new_sharks.push_back(temp);
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(sharks[i][j].isShark){
                int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};//북,남,동,서
                int curX = i;int curY = j;
                for(int move = 0;move<sharks[i][j].speed;move++){
                    int nextX = curX+dir[sharks[i][j].dir-1][0];
                    int nextY = curY+dir[sharks[i][j].dir-1][1];
                    if(isWall(nextX,nextY)){
                        sharks[i][j].dir = changedir(sharks[i][j].dir);
                        curX=curX+dir[sharks[i][j].dir-1][0];
                        curY=curY+dir[sharks[i][j].dir-1][1];
                    }
                    else{
                        curX=nextX;curY = nextY;
                    }
                }

                if(new_sharks[curX][curY].isShark){ //겹치는 경우
                    if(new_sharks[curX][curY].size>sharks[i][j].size)continue;
                    else{
                        new_sharks[curX][curY].allocate(sharks[i][j].speed, sharks[i][j].dir, sharks[i][j].size);
                    }
                }
                else{
                    new_sharks[curX][curY].allocate(sharks[i][j].speed, sharks[i][j].dir, sharks[i][j].size);
                }
            }
        }
    }
    sharks = new_sharks;
}
int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    input();
    for(int turn = 1;turn<=c+1;turn++){
        //turn : pos of people
        //1. move people : for loop
        //2. chase shark
        chase_shark(turn);
        //3. move shark
        move_shark();
    }
    cout<<answer<<endl;
    return 0;
}