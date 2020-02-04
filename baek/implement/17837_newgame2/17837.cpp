#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class ChessPiece{
    public:
    int dir;//1,2,3,4 = 동서북남
    int id;
    ChessPiece(int i,int d){
        id = i;dir=d;
    }
};
vector<vector<int> > chess; //2차원 기판의 상태
vector<vector<vector<ChessPiece> > > piece;//2차원 말의 상태
int N,K;
void input(){
    cin >> N >> K;
    //input chess map
    for (int i = 0; i < N; i++) {
        vector<int> temp;
        for (int j = 0; j < N; j++){
            int t;
            cin >> t;
            temp.push_back(t);
        }
        chess.push_back(temp);
    }
    //initiate piece
    for (int i = 0; i < N; i++) {
        vector<vector<ChessPiece>> temp;
        for(int j=0;j<N;j++){
            vector<ChessPiece> temp2;
            temp.push_back(temp2);
        }
        piece.push_back(temp);
    }
    //input chess piece
    for (int i = 1; i <= K; i++){
        int a, b, c;
        cin>>a>>b>>c;
        piece[a-1][b-1].push_back(ChessPiece(i,c));
    }
}
bool isWall(int x,int y){
    if(x<0||y<0||x>=N||y>=N)return true;
    return false;
}
int changeDir(int d){
    switch (d){
    case 1:
        return 2;
    case 2:
        return 1;
    case 3:
        return 4;
    case 4:
        return 3;
    }
}
void move_piece(int x,int y,int nx,int ny,int pos,bool reversed){
    vector<ChessPiece> temp;
    temp.insert(temp.end(),piece[x][y].begin()+pos,piece[x][y].end());
    if(reversed)reverse(temp.begin(),temp.end());
    piece[nx][ny].insert(piece[nx][ny].end(),temp.begin(),temp.end());
    int len = piece[x][y].size();
    for(int i=pos;i<len;i++){
        piece[x][y].pop_back();     
    }
    return;
}
bool move(){
    int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
    for(int id=1;id<=K;id++){ //1~K까지 이동
        int x,y,pos;
        //find id piece in piece map
        for(int a=0;a<N;a++){
            for(int b=0;b<N;b++){
                for(int c=0;c<piece[a][b].size();c++){
                    if(piece[a][b][c].id==id){
                        x=a,y=b;pos=c;
                        break;
                    }
                }
            }
        }
        int nextX = x + dir[piece[x][y][pos].dir-1][0];
        int nextY = y + dir[piece[x][y][pos].dir-1][1];
        if(isWall(nextX,nextY) || chess[nextX][nextY]==2){//이동하는 위치가 파란색 또는 벽인경우
            piece[x][y][pos].dir = changeDir(piece[x][y][pos].dir);
            nextX = x + dir[piece[x][y][pos].dir-1][0];
            nextY = y + dir[piece[x][y][pos].dir-1][1];
            //반대로 갈 때에도 빨간 블록 확인해줘야함!!
            if(isWall(nextX,nextY) ||chess[nextX][nextY]==2) 
                x=x;
            else if(chess[nextX][nextY]==1)
                move_piece(x, y, nextX, nextY, pos, true);
            else
                move_piece(x, y, nextX, nextY, pos, false);
        }
        else if (chess[nextX][nextY] == 1){//reverse move
            move_piece(x,y,nextX,nextY,pos,true);
        }
        else{//common move(white chess map)
            move_piece(x,y,nextX,nextY,pos,false);
        }
        //말이 4개이상 한 곳에 있는지 확인
        for(int a=0;a<N;a++){
            for(int b=0;b<N;b++){
                if(piece[a][b].size()>=4){
                    return true;
                }
            }
        }
        
    }
    return false;   
}
int main(int argc, char **argv)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    int turn;
    for(turn=1;turn<=1000;turn++){
        if(move()) 
            break;
    }
    if(turn<1001)
        cout << turn << endl;
    else
        cout<<"-1"<<endl;
    return 0;
}