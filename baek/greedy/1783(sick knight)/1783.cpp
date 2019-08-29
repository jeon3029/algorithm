#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n,m;
  cin>>n>>m;
  if(n==1){//높이 1인경우 움직을 수 없음
    cout<<"1"<<endl;
  }
  else if(n==2){//4번이상 움직일수 없음.
    if(m>=7){
      cout<<"4"<<endl;
    }
    else{
      cout<<(m+1)/2<<endl;
    }
  }
  else{//n>=3
    int cnt=0;
    if(m<7){//4번이동하기 전까지는 제약이 있음
      switch(m){
        case 1:
          cnt+=1;break;
        case 2:
          cnt+=2;break;
        case 3:
          cnt+=3;break;
        case 4:
          cnt+=4;break;
        case 5:
          cnt+=4;break;
        case 6:
          cnt+=4;break;
      }
      cout<<cnt<<endl;
    }
    else cout<<m-2<<endl;//이미 1번씩 사용한 상태이므로 m+1될때마다계속 1씩 추가됨
  }
  return 0;
}
