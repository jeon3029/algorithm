#include<bits/stdc++.h>
using namespace std;

char Data[6144][6144];
void printstar(int x,int y,int n){
  if(n==3){
    Data[x][y]='*';
    Data[x+1][y-1]='*';
    Data[x+1][y]=' ';
    Data[x+1][y+1]='*';

    Data[x+2][y-2]='*';
    Data[x+2][y-1]='*';
    Data[x+2][y]='*';
    Data[x+2][y+1]='*';
    Data[x+2][y+2]='*';
    return;
  }
  printstar(x,y,n/2);
  printstar(x+n/2,y-n/2,n/2);
  printstar(x+n/2,y+n/2,n/2);
  for(int i=0;i<n/2;i++){
    for(int j=0;j<n-i*2-1;j++){
      Data[x+n/2+i][y-n/2+j+i+1]=' ';
    }
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  int N;cin>>N;
  for(int i=0;i<N*2;i++){
    for(int j=0;j<N*2;j++){
      Data[i][j]=' ';
    }
  }
  printstar(0,N,N);
  // cout<<3*1024*2;
  for(int i=0;i<N;i++){
    for(int j=1;j<N*2;j++){
      cout<<Data[i][j];
    }cout<<"\n";
  }
}