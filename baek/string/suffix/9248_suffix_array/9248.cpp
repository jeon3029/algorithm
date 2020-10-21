#include <iostream>
#include <algorithm>
#include <cstring>
#define LEN 500010
using namespace std;
char str[LEN];
int t, n, g[LEN], tg[LEN], SA[LEN], RANK[LEN], LCP[LEN];
bool cmp(int x, int y){
    // 현재 보고있는 단어가 같으면 t번째 기준으로 정렬
    if (g[x] == g[y])
        return g[x + t] < g[y + t];
    // 현재 보고있는 단어가 다르다면 바로 정렬
    return g[x] < g[y];
}
void getSA(const char* str){
    t = 1;
    n = strlen(str);
    //첫 글자에 의한 그룹을 정해주는 전처리
    for (int i = 0; i < n; i++){
        SA[i] = i;
        g[i] = str[i] - 'a';
    }
 
    //1,2,4,8... 씩 단어의 길이보다 작은 경우를 탐색
    while (t <= n){
        sort(SA, SA + n, cmp);    //그룹에 의한 정렬
        tg[SA[0]] = 0;    //다음 그룹을 할당하기 위하여 tempgroup의 첫번째 번호 배정
        //다음 그룹 배정 
        for (int i = 1; i < n; i++){
            //그룹이 다를 경우 다음 그룹 번호 할당
            if (cmp(SA[i - 1], SA[i]))
                tg[SA[i]] = tg[SA[i - 1]] + 1;
 
            //그룹이 같을 경우 같은 그룹 번호 할당
            else
                tg[SA[i]] = tg[SA[i - 1]];
        }
 
        //새로운 그룹 할당
        for (int i = 0; i < n; i++)
            g[i] = tg[i];
 
        t <<= 1; // t *= 2;
    }
}
int main(){
    // scanf("%d", &n);
    scanf("%s", &str);
    getSA(str);
    for (int i = 0; i < n; i++)
        RANK[SA[i]] = i;
    int len = 0;
    for (int i = 0; i < n; i++){
        int k = RANK[i];
        if (k){
            int j = SA[k - 1];
            while (j+len < n && i + len<n &&str[j + len] == str[i + len])
                len++;
            LCP[k] = len;
            if (len)
                len--;
        }
    }
    for(int i=0; i<n; i++){
        printf("%d ",SA[i]+1);
    }puts("");
    for(int i=0; i<n; i++){
        if(i)
            printf("%d ",LCP[i]);
        else
            printf("x ");
    }puts("");
    return 0;
}