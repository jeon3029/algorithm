#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string arrangement)
{
    int answer = 0;
    stack<char> s;
    for (int i = 0; i < arrangement.size(); i++)
    {
        if (arrangement[i] == '(')
            s.push('(');
        else
        {
            if (arrangement[i - 1] == '(')
            { //Laser
                s.pop();
                answer += s.size();
            }
            else
            { //Edge
                answer++;
                s.pop();
            }
        }
    }
    return answer;
}