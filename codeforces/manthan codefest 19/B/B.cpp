#include<bits/stdc++.h>
using namespace std;

vector<int> a;
int n;

bool check(vector<int> A,int x1,int x2){
  //check is there any better solution to check duplicete
  if(x1==x2){
    sort(A.begin(),A.end());
    for(int i=0;i<A.size()-1;i++){
      if(A[i] == A[i+1]){
        return false;
      }
    }
    return true;
  }
  else{
    A.erase (A.begin()+x1,A.begin()+x2);


    sort(A.begin(),A.end());
    for(int i=0;i<A.size()-1;i++){
      if(A[i] == A[i+1]){
        return false;
      }
    }
    return true;
  }
}
int main(void){
  cin>>n;
  for(int i=0;i<n;i++){
    int x;cin>>x;
    a.push_back(x);
  }
  if(check(a,0,0)){
      cout<<0<<endl;
      return 0;
  }
  int min = 3000;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<=n;j++){//check all the cases
      //cout<<i<<",  "<<j<<endl;
      if(check(a,i,j)){
        //cout<<i<<",  "<<j<<endl;
        if(min>j-i){
          min = j-i;
        }
        break;
      }
    }
  }
  cout<<min<<endl;
  return 0;
}
