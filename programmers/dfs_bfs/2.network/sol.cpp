#include <string>
#include <vector>
#include <queue>

bool check[201];
using namespace std;
void bfs(int x, int n, vector<vector<int>> computer)
{
    queue<int> q;
    q.push(x);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        check[x] = 1;
        for (int i = 0; i < n; i++)
        {
            if (x == i)
                continue;
            if (check[i] == 0 && computer[x][i] == 1)
            {
                q.push(i);
            }
        }
    }
}
int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        if (check[i] == 0)
        {
            bfs(i, n, computers);
            answer++;
        }
    }
    return answer;
}