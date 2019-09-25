#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int a_ans[5] = {1, 2, 3, 4, 5};
int b_ans[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int c_ans[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    //int cor[3]={0,};
    vector<int> cor;
    cor.push_back(0);
    cor.push_back(0);
    cor.push_back(0);
    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == a_ans[i % 5])
            cor[0]++;
        if (answers[i] == b_ans[i % 8])
            cor[1]++;
        if (answers[i] == c_ans[i % 10])
            cor[2]++;
    }
    int high;
    high = *max_element(cor.begin(), cor.begin() + 3);
    for (int i = 0; i < 3; i++)
    {
        if (high == cor[i])
            answer.push_back(i + 1);
    }
    return answer;
}
