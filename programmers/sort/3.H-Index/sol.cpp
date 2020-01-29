#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations)
{
    int answer = 0;
    sort(citations.begin(), citations.end());
    int h = citations[0];
    for (int i = 0; citations.size(); i++)
    {
        int j;
        int cnt = 0;
        for (j = 0; j < citations.size(); j++)
        {
            if (citations[j] > i)
                cnt++;
        }
        if (i >= cnt)
        {
            answer = i;
            break;
        }
    }
    return answer;
}