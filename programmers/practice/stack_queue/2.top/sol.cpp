#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights)
{
    vector<int> answer(heights.size());
    for (int i = heights.size() - 1; i > 0; i--)
    {
        int std = heights[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (heights[j] > std)
                break;
        }
        answer[i] = j + 1;
    }
    answer[0] = 0;

    return answer;
}