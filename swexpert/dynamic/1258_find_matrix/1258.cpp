#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int M[100][100];
int V[100][100];
bool cmp(pi p1,pi p2){
	int t1 =p1.first*p1.second;
	int t2 = p2.first*p2.second;
	if(t1==t2){
		return p1.first<p2.first;
	}
	return t1<t2;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;cin>>T;
	for(int tc=1;tc<=T;tc++){
		memset(V,0,sizeof(V));
		int n;cin>>n;
		vector<pi> answer;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>M[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(!V[i][j] && M[i][j]){
					int x,y;
					for(x=i;x<n;x++){
						if(M[x][j]==0)break;
					}
					for(y=j;y<n;y++){
						if(M[i][y]==0)break;
					}
					answer.push_back({x-i,y-j});
					for(int t1=i;t1<x;t1++){
						for(int t2=j;t2<y;t2++){
							V[t1][t2]=1;
						}
					}
				}
			}
		}
		sort(answer.begin(),answer.end(),cmp);
		cout<<"#"<<tc<<" "<<answer.size()<<" ";
		for(auto it:answer){
			cout<<it.first<<" "<<it.second<<" ";
		}cout<<"\n";
	}
}