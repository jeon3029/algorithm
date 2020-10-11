#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
//predefined
int N;
int Data[20][20];
int answer = 987654321;
void input(){
  cin>>N;
  rep(i,0,N)rep(j,0,N)cin>>Data[i][j];
}
void calc(vector<int> arr){
  int team1=0,team2=0;
  for(int i=0;i<arr.size()-1;i++){
    for(int j=i+1;j<arr.size();j++){
      if(arr[j]==arr[i] && arr[i]==0){
        team1+=Data[i][j];
        team1+=Data[j][i];
      }
      else if(arr[j]==arr[i] && arr[i]==1){
        team2+=Data[i][j];
        team2+=Data[j][i];
      }
    }
  }
  int cur = abs(team1-team2);
  if(answer>cur)answer = cur;
  return;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  input();
  vector<int> comb(N);
  for(int i=0;i<N/2;i++)comb[i]=1;
  sort(comb.begin(),comb.end());
  do{
    calc(comb);
  }while(next_permutation(comb.begin(),comb.end()));
  cout<<answer<<"\n";
}