#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int custom_rand(int a,int b){
  return rand()%(b-a+1)+a;
}
int main(){
  time_t t = time(NULL);
  srand((unsigned)time(NULL));
//  srand((unsigned)t);
  struct tm tm = *localtime(&t);
  int cur_hour = tm.tm_hour;
  int rand_hour;
  //점심시간 회피 
  while(1){
    rand_hour = custom_rand(cur_hour,17);
    if(rand_hour!=12)break;
  }
  if(cur_hour == rand_hour){
    int cur_min = tm.tm_min;
    int rand_min = custom_rand(cur_min,59);
    if(rand_min == cur_min){
      printf("%d시%d분 %d초",rand_hour,rand_min,custom_rand(tm.tm_sec,59));
    }
    else{
      printf("%d시%d분 %d초",rand_hour,rand_min,custom_rand(0,59));
    }
  }
  
  else{
    printf("%d시%d분 %d초",rand_hour,custom_rand(0,59),custom_rand(0,59));
  }
  return 0;
}
