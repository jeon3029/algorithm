#include<bits/stdc++.h>
using namespace std;

int main(void){
  int n;cin>>n;
  vector<int> d;
  while(n--){
    int x;scanf("%d",&x);d.push_back(x);
  }
  sort(d.begin(),d.end());
  if(d[0]>1){//1이 있는지 확인
    cout<<"1"<<endl;return 0;//없으면 1 무조건 만들 수 없음.
  }
  int result = 1;
  for(int i=1;i<d.size();i++){
    if(result+1>=d[i]){//1이 있다고 가정했으므로 이제 사용하게될 무게 +1 을 만들수 있는가 체크
      result+=d[i];
    }
    else break;
  }
  cout<<result+1<<endl;//지금까지 만들수 있는 무게 = result 이므로 result+1 출력
  return 0;
}
