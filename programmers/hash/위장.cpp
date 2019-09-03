#include <string>
#include <vector>
#include<iostream>
using namespace std;
int answer = 0;
int clo[30]={0,};int n_clo=0;
bool visited[30];
void dfs(int sel,int depth,int n,int sol){//depth = current selected / n = total selected number
    if(sel==n){
        answer += sol;
        cout<<sol<<endl;
        return;
    }
    for(int i=depth;i<n_clo;i++){//select
        if(!visited[i]){
            visited[i]=true;
            sel++;
            dfs(sel,i,n,sol*clo[i]);
            visited[i]=false;
            sel--;
        }
    }
}
int solution(vector<vector<string>  > clothes) {

    for(int i=0;i<clothes.size()-1;i++){
        for(int j=i+1;j<clothes.size();j++){
            int n = clothes[i].size();
            int m = clothes[j].size();
            if(!n||!m)continue;

            if(clothes[i][n-1]==clothes[j][m-1]){//병합
                clothes[i].pop_back();
                for(int k=0;k<m;k++){
                    clothes[i].push_back(clothes[j][k]);
                }
                clothes[j].clear();
            }
        }
    }

    for(int i=0;i<clothes.size()-1;i++){
        if(clothes[i].size()!=0){
            clo[n_clo++]=clothes[i].size()-1;
        }
    }
    for(int i=1;i<=n_clo;i++){ //i = selected clothes
       dfs(0,0,i,1);
    }
    return answer;
}
int main(void){
  int n,m[30];
  vector<vector<string>  > s;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>m[i];
    vector<string> temp_s;
    for(int j=0;j<m[i];j++){
      string temp;cin>>temp;
      //cout<<temp;
      temp_s.push_back(temp);
    }
    s.push_back(temp_s);
  }
  cout<<solution(s);
}
