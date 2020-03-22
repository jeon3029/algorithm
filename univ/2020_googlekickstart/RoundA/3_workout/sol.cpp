//unsolved
#include<bits/stdc++.h>
using namespace std;
int Data[100000];
int N,K;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;cin>>T;
	for(int tc=1;tc<=T;tc++){
		priority_queue<int> q;
		cin>>N>>K;
		for(int i=0;i<N;i++){
			cin>>Data[i];
			if(i>0){
				q.push(Data[i]-Data[i-1]);
			}
		}
		for(int i=0;i<K;i++){
			int val = q.top();
			if(val==1)break;
			q.pop();
			if(val%2==0){
				q.push(val/2);
				q.push(val/2);
			}
			else{
				q.push(val/2);
				q.push((val/2)+1);
			}
		}
		cout<<"Case #"<<tc<<": "<< q.top()<<"\n";
	}
}