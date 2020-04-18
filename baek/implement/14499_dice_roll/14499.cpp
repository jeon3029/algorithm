#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pi;
//predefined

int dx,dy;
int Map[20][20];
int K;
int N,M;
vi Order;
typedef struct _dice{
    int left;
    int right;
    int bot;
    int top;
    int front;
    int back;
}dice;

void input(){
    cin>>N>>M>>dx>>dy>>K;
    rep(i,0,N)rep(j,0,M)cin>>Map[i][j];
    rep(i,0,K){
        int o;cin>>o;
        Order.pb(o);
    }
}
bool isWall(int x,int y){
    return x<0||y<0||x>=N||y>=M;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    dice D;
    memset(&D,0,sizeof D);
    int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
    rep(i,0,K){
        int d = Order[i];
        int nx = dx + dir[d-1][0];
        int ny = dy + dir[d-1][1];
        if(isWall(nx,ny))continue;
        dx = nx; dy = ny;
        // cout<<dx<<","<<dy <<" : ";
        if(d == 1){//동
            int temp = D.bot;
            D.bot = D.right;
            D.right = D.top;
            D.top = D.left;
            D.left = temp;
        }
        else if(d == 2){//서
            int temp = D.bot;
            D.bot = D.left;
            D.left = D.top;
            D.top = D.right;
            D.right = temp;
        }
        else if(d == 4){//남
            int temp = D.bot;
            D.bot = D.front;
            D.front = D.top;
            D.top = D.back;
            D.back = temp;
        }
        else if(d == 3){//북
            int temp = D.bot;
            D.bot = D.back;
            D.back = D.top;
            D.top = D.front;
            D.front = temp;
        }

        if(Map[dx][dy]!=0){
            D.bot = Map[dx][dy];
            Map[dx][dy]=0;
        }
        else{
            Map[dx][dy]=D.bot;
        }
        cout<<D.top<<"\n";
    }
}