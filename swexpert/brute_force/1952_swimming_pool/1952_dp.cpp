#include<stdio.h>
int T;
int cost[4];
int plan[12];
int min_cost;
int DP[3][12];
#define INF 987654321
int min(int a, int b){
    return a>b ? b:a;
}
int main() {
    scanf("%d", &T);
    for (int test = 1; test <= T; test++) {
        for (int i = 0; i < 4; i++)
            scanf("%d", cost + i);
        for (int i = 0; i < 12; i++)
            scanf("%d", plan + i);
        int min_cost = cost[3];
        DP[0][0] = min(plan[0] * cost[0], cost[1]);
        DP[1][0] = cost[2];
        DP[2][0] = INF;
        for (int i = 1; i < 12; i++) {
            DP[0][i] = min(DP[0][i - 1] + min(plan[i] * cost[0], cost[1]), DP[2][i - 1]);
            DP[1][i] = DP[0][i - 1] + cost[2];
            DP[2][i] = DP[1][i - 1];
        }
        for (int i = 0; i < 3; i++)
            if (DP[i][11] < min_cost)
                min_cost = DP[i][11];
        printf("#%d %d\n", test, min_cost);
    }
    return 0;
}