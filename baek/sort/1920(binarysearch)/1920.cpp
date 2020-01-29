#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 100001
using namespace std;
int n,m;
vector<int> a;
vector<int> b;
bool search(vector<int> arr, int num){
  int i=0,j=n-1;
  if(num > arr[j] || num<arr[i])return false;

  while(i <= j){
    int mid = (i+j)/2;
    if(arr[mid] == num){
      return true;
    }
    else if(arr[mid]>num){
      j=mid - 1;
    }
    else{
      i=mid + 1;
    }
  }
  return false;
}

int main(void){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int temp;
    scanf("%d",&temp);
    a.push_back(temp);
  }
  scanf("%d",&m);
  for(int i=0;i<m;i++){
    int temp;
    scanf("%d",&temp);
    b.push_back(temp);
  }
  sort(a.begin(),a.end());
  //sort(b.begin(),b.end());
  for(int i=0;i<m;i++){
    if(search(a,b[i])){
      printf("1\n");
    }
    else{
      printf("0\n");
    }
  }
  return 0;
}
