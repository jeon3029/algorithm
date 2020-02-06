#include<iostream>
#include<vector>
using namespace std;
int R,C,T;
int cleanerX=-1,cleanerY=-1;
vector<vector<int> > map;
void input(){
    cin>>R>>C>>T;
    for(int i=0;i<R;i++){
        vector<int> temp;
        for(int j=0;j<C;j++){
            int t;cin>>t;
            if(cleanerX==-1 && t==-1){
                cleanerX = i;cleanerY = j;
            }
            temp.push_back(t);
        }
        map.push_back(temp);
    }
}
bool isWall(int x,int y){//벽이거나 공기청정기일경우  true
    if(x<0||y<0 || x>=R ||y>=C||((x==cleanerX ||x==cleanerX+1)&&y==cleanerY))return true;
    return false;
}
void diffusion(){
    vector<vector<int> >new_map;
    for(int i=0;i<R;i++){//initiate
        vector<int> temp(C,0);
        new_map.push_back(temp);
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(map[i][j]==0)continue;
            else if(map[i][j]==-1)new_map[i][j]=map[i][j];
            else{
                int divide = map[i][j]/5;
                
                int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
                int cnt = 0;
                for(int d=0;d<4;d++){
                    int newX = i+dir[d][0];
                    int newY = j+dir[d][1];
                    if(!isWall(newX,newY)){
                        new_map[newX][newY]+=divide;
                        cnt++;
                    }
                }
                new_map[i][j] += map[i][j] - (cnt * divide);
            }
        }
    }
    map = new_map;
}
void purify(){
    //upper area
    for(int i=cleanerX-1;i>=1;i--){
        map[i][0] = map[i-1][0];
    }
    for(int i=0;i<C-1;i++){
        map[0][i] = map[0][i+1];
    }
    for(int i=0;i<cleanerX;i++){
        map[i][C-1] = map[i+1][C-1];
    }
    for(int i=C-1;i>=2;i--){
        map[cleanerX][i] = map[cleanerX][i-1];
    }
    map[cleanerX][cleanerY+1] = 0;
    //lower area
    for(int i=cleanerX+2;i<R-1;i++){
        map[i][0] = map[i+1][0];
    }
    for(int i=0;i<C-1;i++){
        map[R-1][i] = map[R-1][i+1];
    }
    for(int i=R-1;i>cleanerX+1;i--){
        map[i][C-1] = map[i-1][C-1];
    }
    for(int i=C-1;i>=2;i--){
        map[cleanerX+1][i] = map[cleanerX+1][i-1];
    }
    map[cleanerX+1][cleanerY+1]=0;
}
int main(int argc,char** argv){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    for(int i=0;i<T;i++){
        diffusion();
        purify();
    }
    int sum=0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){   
            if(map[i][j]!=-1)sum+=map[i][j];
        }
    }
    cout<<sum<<endl;
}
