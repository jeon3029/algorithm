#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0;i<commands.size();i++){
        int x = commands[i][0];
        int y = commands[i][1];
        int z = commands[i][2];
        vector<int> temp;
        temp.insert(temp.begin(),array.begin()+x-1,array.begin()+y);
        sort(temp.begin(),temp.end());
        answer.push_back(temp[z-1]);
    }
    return answer;
}
