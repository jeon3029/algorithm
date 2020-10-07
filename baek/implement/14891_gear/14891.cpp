#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
//predefined

int Data[4][8];
int K;
int rot[100][2];

void input(){
  for(int i=0;i<4;i++){
    string s;
    cin>>s;
    for(int j=0;j<8;j++){
      Data[i][j]=s[j]-'0';
    }
  }
  cin>>K;
  for(int i=0;i<K;i++){
    cin>>rot[i][0]>>rot[i][1];
  }
}
void dir_rotate(int gear[8],int dir){
  int temp[8]; 
  if(dir==-1){//반시계방향
    for(int i=0;i<7;i++){
      temp[i] = gear[i+1];
    }
    temp[7] = gear[0];
  }
  else{
    for(int i=1;i<8;i++){
      temp[i] = gear[i-1];
    }
    temp[0] = gear[7];
  }
  for(int i=0;i<8;i++){
    gear[i] = temp[i];
  }
}
void rotate(int gear,int dir){
  if(gear==1){//2,3,4
    if(Data[0][2] != Data[1][6]){
      if(Data[1][2] != Data[2][6]){
        if(Data[2][2] != Data[3][6]){
          dir_rotate(Data[0],dir);
          dir_rotate(Data[1],-dir);
          dir_rotate(Data[2],dir);
          dir_rotate(Data[3],-dir);
        }
        else{
          dir_rotate(Data[0],dir);
          dir_rotate(Data[1],-dir);
          dir_rotate(Data[2],dir);
        }
      }
      else{
        dir_rotate(Data[0],dir);
        dir_rotate(Data[1],-dir);
      }
    }
    else{
      dir_rotate(Data[0],dir);
    }
  }
  else if(gear==2){
    if(Data[0][2] != Data[1][6]){
      dir_rotate(Data[0],-dir);
    }
    if(Data[1][2] != Data[2][6]){
      if(Data[2][2] != Data[3][6]){
        
        dir_rotate(Data[1],dir);
        dir_rotate(Data[2],-dir);
        dir_rotate(Data[3],dir);
      }
      else{
        dir_rotate(Data[1],dir);
        dir_rotate(Data[2],-dir);
      }
    }
    else{
      dir_rotate(Data[1],dir);
    }
  }
  else if(gear==3){
    if(Data[2][2] != Data[3][6]){
      dir_rotate(Data[3],-dir);
    }
    if(Data[1][2] != Data[2][6]){
      if(Data[0][2] != Data[1][6]){
        dir_rotate(Data[0],dir);
        dir_rotate(Data[1],-dir);
        dir_rotate(Data[2],dir);
      }
      else{
        dir_rotate(Data[1],-dir);
        dir_rotate(Data[2],dir);
      }
    }
    else{
      dir_rotate(Data[2],dir);
    }
  }
  else{
    if(Data[2][2] != Data[3][6]){
      if(Data[1][2] != Data[2][6]){
        if(Data[0][2] != Data[1][6]){
          dir_rotate(Data[0],-dir);
          dir_rotate(Data[1],dir);
          dir_rotate(Data[2],-dir);
          dir_rotate(Data[3],dir);
        }
        else{
          dir_rotate(Data[1],dir);
          dir_rotate(Data[2],-dir);
          dir_rotate(Data[3],dir);
        }
      }
      else{
        dir_rotate(Data[2],-dir);
        dir_rotate(Data[3],dir);
      }
    }
    else{
      dir_rotate(Data[3],dir);
    }
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  input();
  for(int i=0;i<K;i++){
    rotate(rot[i][0],rot[i][1]);
  }
  int answer = 0;
  for(int i=0;i<4;i++){
    if(Data[i][0]==1){
      answer += 1<<i;
    }
  }
  cout<<answer<<"\n";
}