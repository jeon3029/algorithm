#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
bool isOperand(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/')return true;
    else return false;
}
bool is_valid(vector<string> tree, int current)
{
    //operand
    if(isOperand(tree[current][0])){
        if(current*2+2<tree.size()){
            return is_valid(tree, current * 2 + 1) && is_valid(tree, current * 2 + 2);
        }
        else return false;
    }
    //number
    if(current*2+2<tree.size()){ //자식이 있으면 유효 X
        return false;
    }
    else return true;
}
int main(int argc, char **argv)
{
    int test_case;
    int T;
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    T = 10;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        bool answer;
        string input;
        int N;
        getline(cin, input);
        N = atoi(input.c_str());
        vector<string> tree(N, "");
        for (int i = 0; i < N; i++)
        {
            getline(cin, input);
            istringstream ss(input);
            string str;
            getline(ss, str, ' ');
            int index = atoi(str.c_str());
            getline(ss, str, ' ');
            tree[index - 1] = str;
        }
        answer = is_valid(tree,0);
        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;
}