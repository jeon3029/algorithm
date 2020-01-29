#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool dfs(const string from, const vector<vector<string>>& tickets, vector<bool>& visit, vector<string>& temp, vector<string>& answer, int cnt) {
    temp.push_back(from);
    if (cnt == tickets.size()) { //종료조건
        answer = temp;
        return true;
    }
    for (int i=0 ; i<tickets.size() ; i++) {
        if (tickets[i][0] == from && visit[i] == false) {
            visit[i] = true;
            bool success = dfs(tickets[i][1], tickets, visit, temp, answer, cnt+1);
            if (success) return true; 
            visit[i] = false;
        }
    }
    temp.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer,temp;
    vector<bool> visit(tickets.size(), false);
    sort(tickets.begin(),tickets.end());
    dfs("ICN",tickets,visit,temp,answer,0);
    return answer;
}
