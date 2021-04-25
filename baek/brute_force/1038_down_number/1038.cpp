#include<bits/stdc++.h>
using namespace std;
int N;
void input(){
  cin>>N;
}
int calc_len(long long n){
  int cnt = 0;
  while(1){
    n = n/10;
    cnt++;
    if(n==0)break;
  }
  return cnt;
}
bool check_num_downfall(long long num){
  int up = -1;
  for(;;){
    if(up < num % 10){
      up = num % 10;
      num = num / 10;
      if(num == 0)break;
    }
    else{
      return false;
    }
  }
  return true;
}
long long solve(){
  long long num = 1;
  int cnt = 0;
  if(N==0)return 0;
  if(N==1022)return 9876543210;
  if(N>1022)return -1;
  while(1){
    bool flag = check_num_downfall(num);
    if(flag == 1){
      cnt++;
  //   cout<<"num : "<<num<<" / cnt : "<<cnt<<"\n";
      if(cnt == N){
        return num;
      }
      num++;
    }
    else{//올라가는 지점에서 백트래킹
      int len = calc_len(num);
      long long temp = num;
      int up = -1;
 //     cout<<"elses"<<"\n";
      for(int i = 0 ; i < len ; i++) {
        int now = temp % 10;
        if(now <= up){
          num -= num%int(pow(10,i+1));
          num += (now+1)*pow(10,i);
          break;
        }
        else{
          up = now;
          temp = temp / 10; 
        }
      }
    }
  }
  return num;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  input();
  cout<<solve()<<"\n";/*
  cout<<check_num_downfall(11)<<"\n";
  cout<<check_num_downfall(12)<<"\n";
  cout<<check_num_downfall(13)<<"\n";
  cout<<check_num_downfall(14)<<"\n";
  cout<<check_num_downfall(15)<<"\n";
  cout<<check_num_downfall(213)<<"\n";*/
}
