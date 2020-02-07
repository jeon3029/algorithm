#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> workflow(vector<vector<int> > work)
{
    vector<int> inNode(work.size(),0); // 각 노드별 차수(나게게 들어오는 노드의 개수)
    vector<int> visited(work.size(), 0);
    queue<int> q; //work 순서대로 계산
    vector<int> answer;
    //inNode 계산
    for (int i = 0; i < work.size(); i++)
    {
        for (int j = 0; j < work[i].size(); j++)
        {
            inNode[work[i][j]]++;
        }
    }
    //차수 0인것 입력
    for (int i = 0; i < work.size(); i++)
    {
        if (inNode[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        answer.push_back(x);
        if (visited[x] == 0)
        {
            visited[x] = 1;
            for (int i = 0; i < work[x].size(); i++)
            {
                inNode[work[x][i]]--;
                if (inNode[work[x][i]] == 0)
                {
                    q.push(work[x][i]);
                }
            }
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
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int v, e;
        cin >> v >> e;
        vector<vector<int> > work;
        //initiate work
        for (int i = 0; i < v; i++)
        {
            vector<int> temp;
            work.push_back(temp);
        }
        for (int i = 0; i < e; i++)
        {
            int x, y;
            cin >> x >> y;
            work[x - 1].push_back(y - 1);
        }
        vector<int> answer = workflow(work);

        cout << "#" << test_case << " ";
        for (int i = 0; i < answer.size(); i++)
        {
            cout << answer[i] + 1 << " ";
        }
        cout << endl;
    }
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}