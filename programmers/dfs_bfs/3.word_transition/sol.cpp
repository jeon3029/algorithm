#include <string>
#include <vector>
#include <queue>
using namespace std;
bool compare(string s1, string s2)
{
    if (s1.size() != s2.size())
        return false;
    int count = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1.at(i) != s2.at(i))
            count++;
    }
    if (count <= 1)
        return true;
    else
        return false;
}
int answer = 0;
int D[100];
void bfs(vector<string> words, string begin, string target)
{
    queue<pair<string, int>> q; //string,count
    q.push(make_pair(begin, 0));

    for (int i = 0; i < words.size(); i++)
        D[i] = 987654321;

    //check all the cases
    while (!q.empty())
    {
        string current = q.front().first;
        int count = q.front().second;
        q.pop();
        for (int i = 0; i < words.size(); i++)
        {
            if (compare(current, words[i]))
            {
                if (D[i] > count + 1)
                {
                    D[i] = count + 1;
                    q.push(make_pair(words[i], D[i]));
                }
            }
        }
    }
    for (int i = 0; i < words.size(); i++)
    {
        if (target == words[i])
        {
            answer = D[i];
            return;
        }
    }
    answer = 0;
}
int solution(string begin, string target, vector<string> words)
{
    //단어 없는 경우
    int i;
    for (i = 0; i < words.size(); i++)
    {
        if (target == words[i])
            break;
    }
    if (i == words.size())
        return 0;

    vector<int> D(words.size(), 0);

    bfs(words, begin, target);
    return answer;
}