#include <string>
#include <vector>

using namespace std;

class Stack
{
private:
    vector<pair<int, int>> _stack; //<val,loc>
public:
    Stack() {}
    bool empty()
    {
        return _stack.size() == 0;
    }
    void push(int x, int y)
    {
        _stack.push_back(make_pair(x, y));
    }
    void popb()
    {
        _stack.pop_back();
    }
    void popf()
    {
        //_stack.pop_front();
        vector<pair<int, int>> temp; //<val,loc>
        for (int i = 0; i < _stack.size() - 1; i++)
        {
            temp.push_back(make_pair(_stack[i + 1].first, _stack[i + 1].second));
        }
        _stack = temp;
    }
    int end()
    {
        return _stack.back().second;
    }
    int front()
    {
        return _stack[0].second;
    }
    int frontv()
    {
        return _stack[0].first;
    }
    bool check(int val)
    {
        for (int i = 0; i < _stack.size(); i++)
        {
            if (_stack[i].first > val)
                return true;
        }
        return false;
    }
};
int solution(vector<int> priorities, int location)
{
    int answer = 0;
    Stack s;
    for (int i = 0; i < priorities.size(); i++)
    {
        s.push(priorities[i], i);
    }
    int cnt = 0;
    while (1)
    {
        int val = s.frontv();
        int loc = s.front();
        if (s.check(val) == 1)
        { //높은 개체가 있으면
            s.push(val, loc);
            s.popf();
        }
        else
        {
            cnt++;
            if (loc == location)
            {
                return cnt;
            }
            s.popf();
        }
    }
}