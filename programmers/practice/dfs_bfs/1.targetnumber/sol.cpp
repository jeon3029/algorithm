#include <string>
#include <vector>
int cnt = 0;
int num = 0;
using namespace std;
void dfs(int depth, int sum, vector<int> const arr)
{
    if (depth >= arr.size())
    {
        if (sum == num)
            cnt++;
        return;
    }
    dfs(depth + 1, sum + arr[depth], arr);
    dfs(depth + 1, sum - arr[depth], arr);
}
int solution(vector<int> numbers, int target)
{
    int answer = 0;
    num = target;
    dfs(0, 0, numbers);
    return cnt;
}