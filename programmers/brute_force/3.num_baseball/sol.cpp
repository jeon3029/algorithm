#include <string>
#include <vector>

using namespace std;
int check[1000];
int solution(vector<vector<int>> baseball) {
    int answer = 0;
    for(int i=111;i<=999;i++){
        int k = i;
        int k_1 = k%10;//1의자리
        k/=10;
        int k_2 = k%10;//10의자리
        k/=10;
        int k_3 = k%10;//100의자리
        int possible=1;
        if(k_1==0 || k_2==0||k_3==0||k_1==k_2||k_1==k_3||k_2==k_3)continue;
        for(int j=0;j<baseball.size();j++){
            int ball=0,strike=0;
            k=baseball[j][0];
            int b_1 = k%10;//1의자리
            k/=10;
            int b_2 = k%10;//10의자리
            k/=10;
            int b_3 = k%10;//100의자리
            if(b_1==k_1)strike++;
            if(b_2==k_2)strike++;
            if(b_3==k_3)strike++;
            if(b_1!=k_1 &&(k_1==b_2||k_1==b_3))ball++;
            if(b_2!=k_2 &&(k_2==b_1||k_2==b_3))ball++;
            if(b_3!=k_3 &&(k_3==b_2||k_3==b_1))ball++;
            if(strike == baseball[j][1] && ball == baseball[j][2]){
                continue;
            }
            else{
                possible=0;break;
            }
        }
        if(possible){
            answer++;
        }
    }
    return answer;
}
