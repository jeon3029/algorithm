//LIS : O(N*logN) - binary search position
#include<bits/stdc++.h>
using namespace std;
vector<int> arr(1000000);
int findpos(int size,int val){
	int left = 0;
	while(left<size){
		int m = (left+size)/2;
		if(arr[m]>=val){
			size = m;
		}else {
			left = m+1;
		}
			
	}
	return size;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;cin>>n;
	vector<int> D;
	for(int i=0;i<n;i++){
		int t;cin>>t;
		D.push_back(t);
	}
	
	int idx = 0;
	arr[0]=-1;
	for(int i=0;i<n;i++){
		if(arr[idx]<D[i]){
			arr[++idx] = D[i];
		}
		else{
			int x = findpos(idx,D[i]);
			arr[x] = D[i];
		}
	}
	cout<<idx<<"\n";
}