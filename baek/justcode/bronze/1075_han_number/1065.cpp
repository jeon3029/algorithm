#include<iostream>
using namespace std;
int main(void){
  int n;
  int count=0;
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    if(i<100){
      count++;continue;
    }
    int first,second,third,fourth;
    int k=i;
    first = k%10;k/=10;
    second = k%10;k/=10;
    third = k%10;k/=10;
    fourth = k%10;
    if(fourth)break;
    if(second-first == third - second){
      count++;
    }

  }
  printf("%d\n",count);
}
