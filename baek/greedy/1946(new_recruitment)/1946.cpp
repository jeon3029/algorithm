#include<bits/stdc++.h>
using namespace std;
class Applicant{
public:
  int x;
  int y;
public:
  Applicant(){}
  Applicant(int _x,int _y):x(_x),y(_y){}
  bool operator <(const Applicant &k)const{
    if(x < k.x /*&& y < k.y*/)return true;
    return false;
  }
  void print(){
    cout<<x<<" , "<<y;
  }
};
int main(void){
  int T;cin>>T;
  while(T--){
    int n;cin>>n;
    vector<Applicant> A;
    //vector<int> G[n+1];
    int inDegree[n+1];
    fill(inDegree,inDegree+n+1,0);
    for(int i=0;i<n;i++){
      int x,y;cin>>x>>y;
      A.push_back(Applicant(x,y));
      //A[i]->print();
    }
    /*for(int i=0;i<n;i++){  //O(n^2)
      for(int j=0;j<n;j++){
        if(i==j)continue;
        if((*A[i])<(*A[j])){
          //G[i][j]=1;
          //A[i]->print();cout<<" < ";A[j]->print();cout<<endl;
          inDegree[j]++;
        }
      }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
      if(inDegree[i]==0){
        cnt++;
      }
    }*/
    sort(A.begin(),A.end());
    int min = 987654321;
    int cnt=0;
    for(int i=0;i<n;i++){
      //A[i].print();cout<<endl;
      if(min>A[i].y){
        min = A[i].y;
        cnt++;
      }
    }
    cout<<cnt<<endl;
  }
  return 0;
}
