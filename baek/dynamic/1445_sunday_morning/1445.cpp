#include<bits/stdc++.h>
using namespace std;
int n, m, dp[55][55], g[55][55], sx, sy, ex, ey;
char a[55][55];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int chk(int x, int y) {
    return 0 <= x&&x < n && 0 <= y&&y < m;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        getchar();
        for (int j = 0; j < m; j++) {
            scanf("%c", &a[i][j]);
            if (a[i][j] == 'S')
                sx = i, sy = j;
            else if (a[i][j] == 'F')
                ex = i, ey = j;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'g')
                g[i][j] = 3000;
            else if (a[i][j] == '.') {
                int f = 0;
                for (int d = 0; d < 4; d++) {
                    if (chk(i + dir[d][0], j + dir[d][1]) && a[i + dir[d][0]][j + dir[d][1]] == 'g')
                        f = 1;
                }
                if (f)g[i][j] = 1;
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push(make_pair(g[sx][sy],make_pair(sx,sy)));
    while (pq.size()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int cost = -pq.top().first;
        pq.pop();
        if (dp[x][y] != -1)continue;
        dp[x][y] = cost;
        for (int d = 0; d < 4; d++) {
            int cx = x + dir[d][0];
            int cy = y + dir[d][1];
            if (!chk(cx, cy) || dp[cx][cy] != -1)continue;
            pq.push(make_pair(-cost - g[cx][cy],make_pair(cx,cy) ));
        }
    }
    printf("%d %d\n", dp[ex][ey] / 3000, dp[ex][ey] % 3000);
    return 0;
}