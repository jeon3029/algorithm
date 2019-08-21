#include<iostream>
#include<queue>
#define MAX 10001


using namespace std;

class Edge{
public:
  int node;
  int time;
  Edge(int _node,int _time):node(_node),time(_time){};
};
int n, start, finish;
int inDegree[MAX], result[MAX], c[MAX];
vector<Edge> a[MAX]; // nodes
vector<Edge> b[MAX]; //for backtraking uses

void topology(){
  queue<int> q;
  q.push(start);

  //최종 거리(result[finish] 및 각 노드까지 가는 데 최대값 계산(result)
  while(!q.empty()){
    int x = q.front();q.pop();
    for(int i=0;i<a[x].size();i++){
        Edge y = Edge(a[x][i].node,a[x][i].time); //연결돼 있는 노드
        if(result[y.node]<= y.time + result[x]){
          result[y.node] = y.time + result[x];//결고값을 최대 거리로 갱신
        }
        if(--inDegree[y.node]==0){
          q.push(y.node);
        }
    }
  }

  //결과 역추적
  int count = 0;
  q.push(finish);
  while(!q.empty()){
    int y = q.front();q.pop();
    for(int i=0;i<b[y].size();i++){ //b : 노드에 연결 되어있는(기리키는) 노드 정보
      Edge x = Edge(b[y][i].node,b[y][i].time);
      if(result[x.node] == result[y] - x.time){
          count++;
          if(c[x.node]==0){//c for check only once
            q.push(x.node);
            c[x.node]++;
          }
      }
    }
  }
  printf("%d\n%d\n",result[finish],count);
  return;
}
int main(void){
    int m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
      int x,y,time;
      scanf("%d%d%d",&x,&y,&time);
      a[x].push_back(Edge(y,time));
      b[y].push_back(Edge(x,time));
      inDegree[y]++;
    }
    scanf("%d%d",&start,&finish);
    topology();
    return 0;
}
//Done
