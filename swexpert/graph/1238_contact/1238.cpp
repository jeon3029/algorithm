#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int workflow(const vector<vector<int> > work,const int start){
    vector<int> visited(work.size(), 0);
    queue<pair<int,int> > q; //방문했는지, 방문차수가 몇 차수인지
    int answer = -1;
    q.push(make_pair(start,1));
    int cnt = 1;
    while (!q.empty()){
        int x = q.front().first;
        int count = q.front().second;
        q.pop();
        if(visited[x]==0){
            visited[x] = count;
            for (int i = 0; i < work[x].size(); i++){
                q.push(make_pair(work[x][i],count+1));   
            }
        }
    }
    for(int i=0;i<work.size();i++){
        if(visited[i]>=cnt){
            answer = i+1;
            cnt = visited[i];
        }
    }
    return answer;
}
int main(int argc, char **argv)
{
    int test_case;
    int T;
    //freopen("input.txt", "r", stdin);
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    T = 10;
    for (test_case = 1; test_case <= T; ++test_case){
        int e,start;
        cin >> e>>start;
        vector<vector<int> > work;
        //initiate work
        for (int i = 0; i < 100; i++){
            vector<int> temp;
            work.push_back(temp);
        }
        for (int i = 0; i < e/2; i++){
            int x, y;
            cin >> x >> y;
            work[x - 1].push_back(y - 1);
        }
        int answer = workflow(work,start-1);

        cout << "#" << test_case << " "<<answer << endl;
    }
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}