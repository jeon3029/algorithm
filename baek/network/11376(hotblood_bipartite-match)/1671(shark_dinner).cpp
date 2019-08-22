#include <iostream>
#include <vector>
#define MAX 51
using namespace std;

class CShark  {
public:
  int size;
  int speed;
  int brain;
public:
  CShark (){};
  CShark (int _size, int _speed, int _brain){
    size = _size;speed = _speed; brain = _brain;
  }
  bool operator <(const CShark &k)const{
    if((size <= k.size) && (speed <= k.speed) && (brain <= k.brain)){
      //cout<<"size,speed,brain : "<<size<<" "<<k.size<<" "<<speed<<" "<<k.speed<<" "<<brain<<" "<<k.brain<<endl;
      return true;
    }
    return false;
  }
  bool operator ==(const CShark &k)const{
    if((size == k.size) && (speed == k.speed) && (brain == k.brain)){
      //cout<<"size,speed,brain : "<<size<<" "<<k.size<<" "<<speed<<" "<<k.speed<<" "<<brain<<" "<<k.brain<<endl;
      return true;
    }
    return false;
  }
  ~CShark (){};
};

int N;
CShark* sh[MAX];//get input
bool check[MAX];//to check
int dest[MAX];//final graph`
vector<int> a[MAX];

/*bool doesnthasInput(int *a,int input){
  for(int i=0;i<N;i++){
    if(a[i]==input){
      return false;
    }
  }
  return true;
}*/
bool dfs(int x){ //남는 자리 있는지 확인
  for(int i = 0 ; i < a[x].size();i++){
    int y = a[x][i];
    if(check[y]) continue;
    check[y] = true;
    if(dest[y]== -1 || dfs(dest[y])){
      dest[y] = x;
      return true;
    }
  }
  return false;
}
void getData(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){//input
    int si,sp,b;//size, speed, brain
    scanf("%d%d%d",&si,&sp,&b);
    sh[i] = new CShark (si,sp,b);
  }
  for(int i=0;i<N;i++){//Calc smaller shark
    for(int j=0;j<N;j++){
      if(i==j)continue;
      if((*sh[i]) == (*sh[j]))
      {
        //cout<<i+1<<" == "<<j+1<<endl;
        if(i>j){
          a[j].push_back(i);
        }
        if(j<i){
          continue;
        }
      }
      else if((*sh[i]) < (*sh[j])){
        //cout<<i+1<<" < "<<j+1<<endl;
        a[j].push_back(i);
      }
    }
  }
  return;
}
int main(void){
  int count=0;
  getData();
  fill(dest,dest+MAX,-1);
  for(int k=0;k<2;k++){
    for(int i=0 ; i < N;i++){
      fill(check,check+MAX,false);
      if(dfs(i)) count++;
    }
  }
  printf("%d\n",N-count);
  /*for(int i=0;i<N;i++){
    if(dest[i]!=-1)
    printf("%d -> %d\n",dest[i]+1,i+1);
  }*/
  return 0;
}
//done
