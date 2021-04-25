#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int sum = brown + red;
    for(int i=3;;i++){
        if(sum % i==0){
            int x = sum/i;// x * i = sum
            if(x<i)continue; //x = 가로, i = 세로
            if((x-2)*(i-2)==red){
                answer.push_back(x);
                answer.push_back(i);
                break;
            }
        }
    }
    return answer;
}
