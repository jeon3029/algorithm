#include<bits/stdc++.h>
#define MAX 5002
using namespace std;
int n;
int w[MAX],h[MAX];
int s[MAX];
int D[MAX];
int back[MAX];
bool cmp(const int a,const int b){
  if(w[a] == w[b]) return h[a]<h[b];
  return w[a]<w[b];
}
int main(){

  cin>>n;
  for(int i=0;i<=n;i++){
    scanf("%d%d",&w[i],&h[i]);
    s[i] = i;
    D[i] = 0;
    back[i] = -1;
  }
  sort(s,s+n+1,cmp);//remember sorting position
  for(int i=0;i<=n;i++){
    //cout<<s[i]<<endl;
  }
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      if(i==j)continue;
      if(w[s[j]]> w[0] && h[s[j]]>h[0] && w[s[i]]>= w[0] && h[s[i]]>=h[0] &&
         w[s[i]]< w[s[j]] && h[s[i]]< h[s[j]] && D[s[j]] < D[s[i]]+1){
        D[s[j]] = D[s[i]]+1;
        back[s[j]] = s[i]; //j 노드 바로 이전이 i 노드
      }
    }
  }
  int max = 0;
  int k=0;
  for(int i=0;i<=n;i++){
    if(max < D[s[i]]){
      max = D[s[i]];
      k = s[i];
    }
  }
  cout<<max<<endl;
  //for(int i=0;i<=n;i++){
  //  cout<<back[i]<<endl;
  //}
  //back tracking
  vector<int> tr;
  while(k!=-1 && k!=0){
    tr.push_back(k);
    k=back[k];
  }
  int size = tr.size();
  for(int i=0;i<size;i++){
    cout<<tr.back()<<" ";
    tr.pop_back();
  }cout<<endl;
  return 0;
}
