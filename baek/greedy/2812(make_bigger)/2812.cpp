#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int n,k;
  cin>>n>>k>>s;
  int i=0;
  vector<char> result;//vector를 stack처럼 사용
  for(int i=0;i<s.size();i++){
    //자신보다 낮은 수가 제일 마지막에 있으면 뺀다. 그것을 자기보다 높은 수를 만날때까지 반복한다.
    //물론 stack은 비어있지 않고, 빼야할 수(k)도 0이면 안된다
    while(!result.empty() && result.back()<s[i] && k!=0){
      k--;
      result.pop_back();
    }
    //자신보다 높은수를 만났을 때 stack에 넣어준다
    result.push_back(s[i]);
  }
  while(k--){//이미 스택에는 내림차순으로 정렬되어있음
    result.pop_back();
  }
  for(int i=0;i<result.size();i++){
    cout<<result[i];
  }cout<<endl;
  return 0;
}
