#include<bits/stdc++.h>
using namespace std;
int N,M;
int red_ball_y,red_ball_x,blue_ball_y,blue_ball_x;
char Map[11][11];
int answer = 11;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};//동,서,남,북

void input(){
    cin>>N>>M;
    for(int i=0;i<N;i++)for(int j=0;j<M;j++){
        cin>>Map[i][j];
        if(Map[i][j] == 'B'){
            blue_ball_y = i;
            blue_ball_x = j;
            Map[i][j] = '.';
        }
        else if(Map[i][j] == 'R'){
            red_ball_y = i;
            red_ball_x = j;
            Map[i][j] = '.';
        }
    }
}
void bfs(int count,int cur_dir,int red_y,int red_x,int blue_y,int blue_x){
    if(count > 10 || count >= answer){
        return;
    }
    //cout<<count<<" "<<cur_dir<<" "<<red_y<<","<<red_x<<" & "<<blue_y<<","<<blue_x<<"\n";
    //move ball
    
    //방향에 따른 먼저 움직일 공 찾기
    int first_move = 0;//0 = red first, 1 = bluefirst
    int red_finish = 0,blue_finish = 0;

    if(cur_dir==0){//동쪽
        if(red_y==blue_y){
            if(blue_x>red_x){//blue first
                first_move = 1;
            }
            else{//red first
                first_move = 0;
            }
        }
    }
    else if(cur_dir==1){//서쪽
        if(red_y==blue_y){
            if(blue_x>red_x){//red first
                first_move = 0;
            }
            else{//blue first
                first_move = 1;
            }
        }
    }
    else if(cur_dir==2){//남쪽
        if(red_x==blue_x){
            if(blue_y>red_y){//blue first
                first_move = 1;
            }
            else{//red first
                first_move = 0;
            }
        }
    }
    else if(cur_dir==3){//북쪽
        if(red_x==blue_x){
            if(blue_y>red_y){//red first
                first_move = 0;
            }
            else{//red first
                first_move = 1;
            }
        }
    }
    if(first_move == 0){//red, blue
        //red
        // cout<<"redfirst\n";
        while(Map[red_y][red_x]=='.' ){
            red_y += dir[cur_dir][0];
            red_x += dir[cur_dir][1];
        }
        if(Map[red_y][red_x]=='O'){
            red_finish=1;
        }
        else if(Map[red_y][red_x]=='#'){
            red_y-=dir[cur_dir][0];
            red_x-=dir[cur_dir][1];
            Map[red_y][red_x] = 'R';
        }
        
        //blue
        while(Map[blue_y][blue_x]=='.'){
            blue_y += dir[cur_dir][0];
            blue_x += dir[cur_dir][1];
        }
        if(Map[blue_y][blue_x]=='O'){
            blue_finish=1;
        }
        else if( Map[blue_y][blue_x] == 'R' || Map[blue_y][blue_x] == '#'){
            blue_y -= dir[cur_dir][0];
            blue_x -= dir[cur_dir][1];
        }

        if(Map[red_y][red_x]!='O') Map[red_y][red_x] = '.';
    }
    else{//blue, red
        // cout<<"bluefirst\n";
        //blue
        while(Map[blue_y][blue_x]=='.' ){
            blue_y += dir[cur_dir][0];
            blue_x += dir[cur_dir][1];
        }
        // cout<<Map[blue_y][blue_x]<<"\n";
        if(Map[blue_y][blue_x]=='O'){
            blue_finish=1;
        }
        else if(Map[blue_y][blue_x]=='#'){
            blue_y -= dir[cur_dir][0];
            blue_x -= dir[cur_dir][1];
            Map[blue_y][blue_x] = 'B';
        }
        // cout<<Map[blue_y][blue_x]<<"\n";
        //red
        while(Map[red_y][red_x]=='.' ){
            red_y += dir[cur_dir][0];
            red_x += dir[cur_dir][1];
        }
        if(Map[red_y][red_x]=='O'){
            red_finish=1;
        }
        else if( Map[red_y][red_x]=='B' || Map[red_y][red_x] == '#'){
            red_y-=dir[cur_dir][0];
            red_x-=dir[cur_dir][1];
        }
        if(Map[blue_y][blue_x]!='O') Map[blue_y][blue_x] = '.';
    }
    if(red_finish == 1 && blue_finish == 1){
        return;
    }
    else if(red_finish == 1 && blue_finish ==0){
        answer = count;
        return;
    }
    else if(red_finish==0 && blue_finish==1){
        return;
    }

    //next move
    for(int i=0;i<4;i++){
        if(i != cur_dir){
            // cout<<count<<" "<<cur_dir<<" "<<red_y<<","<<red_x<<" & "<<blue_y<<","<<blue_x<<"\n";
            bfs(count+1,i,red_y,red_x,blue_y,blue_x);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++){
    //     cout<<Map[i][j];
    //     }
    //     cout<<"\n";
    // }
    // cout<<red_ball_y<<" "<<red_ball_x<<" "<<blue_ball_y<<" "<<blue_ball_x<<"\n";
    bfs(1,0,red_ball_y,red_ball_x,blue_ball_y,blue_ball_x);
    // cout<<"deli1"<<answer<<"\n";
    bfs(1,1,red_ball_y,red_ball_x,blue_ball_y,blue_ball_x);
    // cout<<"deli2"<<answer<<"\n";
    bfs(1,2,red_ball_y,red_ball_x,blue_ball_y,blue_ball_x);
    // cout<<"deli3"<<answer<<"\n";
    bfs(1,3,red_ball_y,red_ball_x,blue_ball_y,blue_ball_x);
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++){
    //     cout<<Map[i][j];
    //     }
    //     cout<<"\n";
    // }
    if(answer == 11)cout<<"-1\n";
    else cout<<answer<<"\n";
}   