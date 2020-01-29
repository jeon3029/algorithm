#include <string>
#include <vector>
#include <map>
using namespace std;
int solution(vector<vector<string>> clothes)
{
    map<string, int> data;
    for (int i = 0; i < clothes.size(); i++)
    {
        for (int j = 0; j < clothes[i].size() - 1; j++)
        {
            string x = clothes[i][clothes[i].size() - 1];
            data[x]++;
        }
    }
    int sum = 1;
    for (auto it = data.begin(); it != data.end(); it++)
    {
        sum *= it->second + 1;
    }
    return sum - 1;
}