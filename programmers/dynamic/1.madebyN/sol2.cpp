#include <string>
#include <vector>
using namespace std;
int answer = 9;
void dfs(int N,int number,int cnt,int now){
    if(cnt>8)return;
    if(now == number){
        if(cnt<answer)answer = cnt;
    }
    int next = 0;
    for(int i=1;i<=9;i++){
        next = next * 10 + N;
        dfs(N,number,cnt+i,now+next);
        dfs(N,number,cnt+i,now-next);
        if(now!=0){
            dfs(N,number,cnt+i,now*next);
            dfs(N,number,cnt+i,now/next);
        }
    }
}
int solution(int N, int number) {
    dfs(N,number,0,0);
    if(answer==9)return -1;
    else return answer;
}