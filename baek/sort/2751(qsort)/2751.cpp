#include<iostream>
#include<algorithm>
using namespace std;
int N;
int data[1000001];
void qsort(int *data,int left,int right){
  int pivot = data[left];
  if(left>=right)return;

  int i=left+1, j=right, temp;
  while(i<=j){
    while(data[i]<=pivot){
      i++;
    }
    while(data[j]>=pivot && j>left){
      j--;
    }
    if(i > j){
      temp = data[j];
      data[j] = pivot;
      data[left] = temp;
    }
    else{
      temp = data[i];
      data[i] = data[j];
      data[j] = temp;
    }
  }
  qsort(data,left,j-1);
  qsort(data,j+1,right);
  return;
}
int main(){
  //입력
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>data[i];
  }
  //for(int i=0;i<N;i++){
  //  cout<<data[i]<<endl;
  //}
  //qsort(data,0,N-1);
  std::sort(data,data+N);
  for(int i=0;i<N;i++){
    cout<<data[i]<<endl;
  }
  return 0;
}
