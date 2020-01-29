#include<iostream>
using namespace std;

int a[10][10]={
  {1},
  {2,4,8,6},
  {3,9,7,1},
  {4,6},
  {5},
  {6},
  {7,9,3,1},
  {8,4,2,6},
  {9,1}
};
int n;

int main(void){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    int xx = x%10;
    int k;
    switch(xx){
      case 1:
       k=1;break;
    case 2:
     k=4;break;
    case 3:
     k=4;break;
    case 4:
     k=2;break;
    case 5:
     k=1;break;
    case 6:
     k=1;break;
    case 7:
     k=4;break;
    case 8:
     k=4;break;
    case 9:
     k=2;break;
     case 0:
     k=0; break;
    }
    if(k==0)cout<<"10"<<endl;
    else{cout<<a[xx-1][(y-1)%k]<<endl;}
  }
  return 0;
}
