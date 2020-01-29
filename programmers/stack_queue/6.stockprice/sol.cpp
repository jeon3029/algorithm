#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size(), 0);
    stack<pair<int, int>> s;
    for (int i = 0; i < prices.size(); i++)
    {
        if (s.empty() || s.top().first <= prices[i])
        {
            s.push(make_pair(prices[i], i));
        }
        else
        {
            while (!s.empty() && s.top().first > prices[i])
            {
                int time = s.top().second;
                answer[time] = i - time;
                s.pop();
            }
            s.push(make_pair(prices[i], i));
        }
    }
    while (!s.empty())
    {
        int time = s.top().second;
        answer[time] = prices.size() - time - 1;
        s.pop();
    }
    return answer;
}