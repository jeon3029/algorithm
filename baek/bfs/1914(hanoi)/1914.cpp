#include<iostream>
#include<cstdio>
using namespace std;
int K;
char data[100];

void hanoi(int n, int s, int e){ //개수, start, end
  if(n==0)return;
  hanoi(n-1 , s , 6-s-e);
  cout<< s <<" "<< e;
  printf("\n");
  hanoi(n-1 , 6-s-e , e);
}
void print(){//print 2^n -1 ---- using character
  int cnt=1;//자릿수
  data[0] = '1';
  for(int i=0;i<K;i++){//2*2*...2 k 번 반복
    int addctr=0;
     for(int j=0;j<cnt;j++){
       int tmp = (data[j]-'0')*2;
       if(addctr==1){
         tmp++;addctr=0;
       }
       if(tmp>=10){
         if(j==cnt-1){
           data[cnt]='1';
           cnt++;
           data[j] = (tmp%10)+'0';
           break;
         }
         tmp = tmp % 10;
         addctr = 1;
       }
       data[j] = tmp + '0';
     }
  }
  data[0]--;
  for(int i=cnt-1;i>=0;i--){
    cout<<data[i];
  }printf("\n");
  return;
}
int main(void){
  cin>>K;
  print();
  if(K<=20){
    hanoi(K,1,3);
  }
  return 0;
}
