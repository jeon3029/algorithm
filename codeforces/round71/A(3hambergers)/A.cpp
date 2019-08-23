//Accepted
#include<iostream>
using namespace std;
int t;
int b,p,f;//bun, patty, cutlets
int h,c;//dollar=s

int main(void){
  scanf("%d",&t);
  for (int i=0;i<t;i++){
    scanf("%d%d%d%d%d",&b,&p,&f,&h,&c);
    int profit=0;
    //cout<<b<<p<<f<<h<<c;
    b/=2;
    if(h>c){//hamberger>chicken
      int cnt=0;//hambergercount;
      while(b>0 && p>0){
        b--;p--;
        cnt++;
      }
      //cout<<cnt<<endl;
      profit+=cnt*h;
      cnt=0;
      while(b>0 && f>0){
        b--;f--;
        cnt++;
      }
      //cout<<cnt<<endl;
      profit+=cnt*c;
    }
    else{//chicken>hamberger
      int cnt=0;//hambergercount;
      //cout<<b<<" " <<f<<endl;
      while(b>0&&f>0){
        b--;f--;
        cnt++;
      }
      //cout<<cnt<<endl;
      profit+=cnt*c;
      cnt=0;
      while(b>0&&p>0){
        b--;p--;
        cnt++;
      }
      //cout<<cnt<<endl;
      profit+=cnt*h;
    }
    printf("%d\n",profit);
  }
  return 0;
}
