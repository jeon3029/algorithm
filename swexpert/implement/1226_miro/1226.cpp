#include<iostream>
#include<vector>
#include<queue>
#include<string>
#define N 16
using namespace std;
class Point{
    public:
    int x,y;
    Point(){}
    Point (int x,int y){
        this->x = x;this->y = y;
    }
    bool operator==(const Point &A){
        return (this->x==A.x) && (this->y == A.y);
    }
};
bool isWall(Point x){
    if(x.x<0 ||x.y<0 ||x.x>=N ||x.y>=N)return true;
    else return false;
}
bool bfs_search(vector<string>map,Point start,Point end){
    vector<vector<int> > visited;
    queue<Point> q;
    //visited initiate
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};//동,서, 남, 북 방향
    for(int i=0;i<N;i++){
        vector<int> temp(N,0);
        visited.push_back(temp);
    }
    q.push(start);
    while(!q.empty()){
        Point cur = q.front();q.pop();
        visited[cur.x][cur.y] = 1;
        if(cur==end){
            return true;
        }
        for(int i=0;i<4;i++){
            Point nextpoint = Point(cur.x+dir[i][0],cur.y+dir[i][1]);
            if(!isWall(nextpoint) && map[nextpoint.x][nextpoint.y]!='1' && visited[nextpoint.x][nextpoint.y]==0 ){
                q.push(nextpoint);
            }
        }
    }
    return false;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	//freopen("input", "r", stdin);
	T=10;
	for(test_case = 1; test_case <= T; ++test_case){
        int t;cin>>t;
        vector<string > map;
        Point startpoint,endpoint;
        for(int i=0;i<N;i++){
            string temp;
            cin>>temp;
            for(int j=0;j<N;j++){
                if(temp[j]=='2'){
                    startpoint = Point(i,j);
                }
                if(temp[j]=='3'){
                    endpoint = Point(i,j);
                }
            }
            map.push_back(temp);
        }   
        bool answer = bfs_search(map,startpoint,endpoint);
        cout <<"#"<<t<<" "<<answer<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}