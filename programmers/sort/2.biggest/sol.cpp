#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a,int b){
    string s1 ,s2;
    s1.append(to_string(a));
    s1.append(to_string(b));

    s2.append(to_string(b));
    s2.append(to_string(a));

    return s1>s2;
}
string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(),numbers.end(),comp);
    int flag=0;
    for(int i=0;i<numbers.size();i++){
        if(numbers[i]==0&&flag==0)continue;
        flag=1;
        answer.append(to_string(numbers[i]));
    }
    if(flag ==0)return "0";

    return answer;
}
