#include<bits/stdc++.h>
#define MAX 1002
using namespace std;

int n;
typedef struct Point{
  int x;int y;
}Point;
typedef struct Cops{
  Point Cop1;
  Point Cop2;
  int result;
}Cops;

Cops D[2][MAX];
Point Data[MAX];

int distance(Point a,Point b){
  return abs(a.x-b.x) + abs(a.y-b.y);
}
int main(void){
  cin>>n;
  int t;cin>>t;
  D[0][0].Cop1.x = 1;D[0][0].Cop1.y = 1;
  D[0][0].Cop2.x = n;D[0][0].Cop2.y = n;
  D[1][0].Cop1.x = 1;D[1][0].Cop1.y = 1;
  D[1][0].Cop2.x = n;D[1][0].Cop2.y = n;  //default : 0second
  D[0][0].result = 0;D[1][0].result=0;
  int result=0;
  for(int i=1;i<=t;i++){//from 1second
    int x,y;cin>>x>>y;
    Data[i].x = x; Data[i].y = y;
    D[0][i].result = 0;D[1][i].result=0;
    //Cop1 selected
    D[0][i].result = D[0][i-1].result + distance(D[0][i-1].Cop1,Data[i]);
    D[0][i].Cop1.x = x; D[0][i].Cop1.y = y;
    D[0][i].Cop2.x = D[0][i-1].Cop2.x; D[0][i].Cop2.y = D[0][i-1].Cop2.y;

    //Cop2 selected
    D[1][i].result = D[1][i-1].result + distance(D[1][i-1].Cop2,Data[i]);
    D[1][i].Cop2.x = x; D[1][i].Cop2.y = y;
    D[1][i].Cop1.x = D[1][i-1].Cop1.x; D[1][i].Cop1.y = D[1][i-1].Cop1.y;
  }
  result = min(D[0][t].result,D[1][t].result);
  cout<<result<<endl;
  vector<int> back;
  for(int i=t;i>=1;i--){//Back tracking
    if(D[0][i].Cop1.x == Data[i].x && D[0][i].Cop1.y == Data[i].y){
      back.push_back(1);
    }
    else{
      back.push_back(2);
    }
  }
  for(int i=0;i<t;i++){
    cout<<back.back()<<endl;
    back.pop_back();
  }
  return 0;
}
