#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;

const int MAX_N = 2e1 + 5, MAX_V = MAX_N * MAX_N;

int N, M; char Mp[MAX_N][MAX_N];
int Dis[MAX_V][MAX_V];
int chNr(pi p) { return p.first * M + p.second; }
int chNr(int x, int y) { return x * M + y; }
int moveTo(int s, int k) {
    int x = s / M + "1012"[k] - '1', y = s % M + "0121"[k] - '1';
    return chNr(x, y);
}
char getMp(int s) { return Mp[s/M][s%M]; }
pi chPi(int s) { return make_pair(s/M, s%M); }

int main() {
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++) scanf("%s", Mp[i]);
    for(int i=0; i<N*M; i++) for(int j=0; j<N*M; j++) Dis[i][j] = -1;

//초기 위치 확인
    int OO = -1, RR = -1, BB = -1;
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) {
        if(Mp[i][j] == 'O') OO = chNr(i, j);
        else if(Mp[i][j] == 'R') RR = chNr(i, j);
        else if(Mp[i][j] == 'B') BB = chNr(i, j);
    }

//(R, B)로 부터 시작
    queue<pi> Q; Q.push(make_pair(RR, BB)); Dis[RR][BB] = 0;
    int ans = INF;
    while(!Q.empty()) {
        int cor[2]; tie(cor[0], cor[1]) = Q.front(); Q.pop();
        if(cor[1] == OO) continue;
        if(cor[0] == OO) { ans = Dis[cor[0]][cor[1]]; break; }
        if(Dis[cor[0]][cor[1]] >= 10) continue;
        for(int k=0; k<4; k++) {
            int next[2] ={cor[0], cor[1]};
            for(int rep=0; rep<3; rep++) for(int l=0; l<2; l++)
                while(1) {
                    if(getMp(next[l]) == 'O') break;
                    if(getMp(moveTo(next[l], k)) == '#') break;
                    if(getMp(moveTo(next[l], k)) == 'O') { next[l] = moveTo(next[l], k); break; }
                    if(moveTo(next[l], k) == next[1-l]) break;
                    next[l] = moveTo(next[l], k);
                }
            if(Dis[next[0]][next[1]] != -1) continue;
            Dis[next[0]][next[1]] = Dis[cor[0]][cor[1]] + 1;
            Q.push(make_pair(next[0], next[1]));
        }
    }
    if(ans == INF) ans = -1;
    printf("%d\n", ans);
    return 0;
}
