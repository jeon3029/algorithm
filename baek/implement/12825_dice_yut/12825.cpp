#include<iostream>
#include<vector>
#include<queue>
#define SIZE 10
using namespace std;
int map[33][6]={//[x][0] = value, [x][1~5] = 주사위 던졌을 때 나오는 위치
    {0,1,2,3,4,5},//start 0
    {2,2,3,4,5,6},//1
    {4,3,4,5,6,7},//2
    {6,4,5,6,7,8},//3
    {8,5,6,7,8,9},//4
    {10,21,22,23,24,25},//5
    {12,7,8,9,10,11},//6
    {14,8,9,10,11,12},//7
    {16,9,10,11,12,13},//8
    {18,10,11,12,13,14},//9
    {20,27,28,24,25,26},//10
    {22,12,13,14,15,16},//11
    {24,13,14,15,16,17},//12
    {26,14,15,16,17,18},//13
    {28,15,16,17,18,19},//14
    {30,29,30,31,24,25},//15
    {32,17,18,19,20,32},//16
    {34,18,19,20,32,32},//17
    {36,19,20,32,32,32},//18
    {38,20,32,32,32,32},//19
    {40,32,32,32,32,32},//20
    {13,22,23,24,25,26},//21
    {16,23,24,25,26,20},//22
    {19,24,25,26,20,32},//23
    {25,25,26,20,32,32},//24
    {30,26,20,32,32,32},//25
    {35,20,32,32,32,32},//26
    {22,28,24,25,26,20},//27
    {24,24,25,26,20,32},//28
    {28,30,31,24,25,26},//29
    {27,31,24,25,26,20},//30
    {26,24,25,26,20,32},//31
    {0,32,32,32,32,32}//32 end
};
vector<int> dice_data(SIZE,0);
int rollDice(int dice_sequence){
    int dice_pos[4] = {0,0,0,0};
    int score = 0;
    for(int i=0;i<SIZE;i++){
        int currentDice = (dice_sequence>>(i*2)) & 0x3;
        int curPos = dice_pos[currentDice];
        if (curPos == 32)return 0;
        int nextPos = map[curPos][dice_data[i]]; 
        int flag = 0;
        for(int i=0;i<4;i++){//이미 다음 위치에 말이 있는 경우 제외
            if(dice_pos[i]==0 || dice_pos[i]==32)continue;
            if(nextPos == dice_pos[i])flag = 1;
        }
        if(flag ==1)return 0;
        score +=map[nextPos][0];
        dice_pos[currentDice] = nextPos;
    }
    return score;
}
int main(int argc, char** argv){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	for(int test_case = 0; test_case < SIZE; ++test_case){
       cin>>dice_data[test_case];
	}
    int answer = 0;
    for(int i=0;i<(1<<20);i++){
        int cur_score = rollDice(i);
        if(answer<cur_score)answer = cur_score;
    }
    cout<<answer<<endl;
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}