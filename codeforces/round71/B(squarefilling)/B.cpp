//Accepted
#include<iostream>
using namespace std;

int A[51][51];
int B[51][51];

int n,m;
int k;
int answer[2500][2];
bool partialCompare(int i,int j){
  if(A[i][j]==B[i][j] && A[i+1][j]==B[i+1][j] &&A[i][j+1]==B[i][j+1] &&A[i+1][j+1]==B[i+1][j+1]){
    return true;
  }
  return false;
}
bool sameCompare(){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if (A[i][j]!=B[i][j]) {
        return false;
      }
    }
  }
  return true;
}
int main(void){
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>A[i][j];
    }
  }
  for(int i=0;i<n-1;i++){
    for(int j=0;j<m-1;j++){
      int a,b,c,d;
      a=B[i][j];b=B[i+1][j];c=B[i][j+1];d=B[i+1][j+1];
      B[i][j]=1;
      B[i+1][j]=1;
      B[i][j+1]=1;
      B[i+1][j+1]=1;
      if(partialCompare(i,j)){
        answer[k][0]=i;answer[k++][1]=j;
      }
      else{
        B[i][j]=a;
        B[i+1][j]=b;
        B[i][j+1]=c;
        B[i+1][j+1]=d;
      }
    }
  }
  if(sameCompare()){
    printf("%d\n",k);
    for(int i=0;i<k;i++){
      printf("%d %d\n",answer[i][0]+1,answer[i][1]+1);
    }
  }
  else{
    printf("-1\n");
  }
  return 0;
}
