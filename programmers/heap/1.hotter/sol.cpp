#include <vector>
#include<queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> pq;
    for(int i=0;i<scoville.size();i++)pq.push(-scoville[i]);
    while(!pq.empty()){
        int x = pq.top();pq.pop();
        if(-x>=K)break;
        else{
            if(!pq.empty()){
                int y = pq.top();
                pq.pop();
                pq.push(x+y*2);
                answer++;
            }
            else{
                answer=-1;break;
            }
        }
    }
    return answer;
}
