#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for (int i = 0, max = completion.size(); i < max; i++)
    {

        if (participant[i] != completion[i])
            return participant[i];
    }
    return participant[participant.size() - 1];
}