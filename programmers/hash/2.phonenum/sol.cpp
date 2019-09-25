#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());
    int i;
    for (i = 0; i < phone_book.size() - 1; i++)
    {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
        {
            break;
        }
    }
    if (i == phone_book.size() - 1)
        answer = true;
    else
        answer = false;
    return answer;
}