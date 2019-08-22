#include<iostream>
#include<vector>
#define MAX 51
using namespace std;

class Shark_{
private:
  int size;
  int speed;
  int brain;
public:
  Shark_(int _size,int _speed,int _brain):size(_size),speed(_speed),brain(_brain){}
  bool operator<(const Shark_ &k)const{
    if(size<=k.size && speed<=k.speed && brain<=k.brain)return true;
    return false;
  }
};

int N;
Shark_ * sh[MAX];
bool check[MAX];//to check
int dest[MAX];//final graph`
vector<int> a[MAX];
bool dfs(int x){
  for(int i = 0 ; i < a[x].size();i++){
    int y = a[x][i];
    if(check[y])continue;
    check[y] = true;
    if(dest[y]==-1 || dfs(dest[y])){
      dest[y] = x;
      return true;
    }
  }
  return false;
}
void getData(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int si,sp,b;
    scanf("%d%d%d",&si,&sp,&b);
    sh[i] = new Shark_(si,sp,b);
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(i==j)continue;
      if(*sh[i]>*sh[j])a[i].push_back(j);
    }
  }
}
int main(void){
  int count=0;
  getData();
  //return 0;
  fill(dest,dest+MAX,-1);
  for(int i=0;i<N;i++){
    fill(check,check+MAX,false);
    if(dfs(i)) count++;
  }
  printf("%d\n",count);/*
  for(int i=0;i<N;i++){
    printf("%d -> %d\n",dest[i]+1,i+1);
  }*/
  return 0;
}
//done
