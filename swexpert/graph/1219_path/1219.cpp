#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	T=10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int t;cin>>t;
        int N;cin>>N;
        int answer = 0;
        vector<vector<int>>graph;
        for(int i=0;i<N;i++){
            vector<int> temp;
            graph.push_back(temp);
        }    
        for(int i=0;i<N;i++){
            int a,b;
            cin>>a>>b;
            graph[a].push_back(b);
        }
        vector<int> visited(N,0);
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int i=0;i<graph[x].size();i++){
                int y = graph[x][i];
                if(y==99){//도착
                    answer = 1;
                    break;
                }
                if(visited[y])continue;
                else{
                    q.push(y);
                    visited[y]=true;

                }
            }
        }
        cout<<"#"<<test_case<<" " <<answer<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}