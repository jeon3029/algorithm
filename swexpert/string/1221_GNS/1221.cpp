#include<bits/stdc++.h>
using namespace std;
int cnt[10];
char num[10][4] = { "ZRO","ONE","TWO","THR","FOR","FIV","SIX","SVN","EGT","NIN" };
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        string s; cin >> s;
        memset(cnt, 0, sizeof(cnt));
        int n; cin >> n;
        while (n--) {
            cin >> s;
            if (s == "ZRO") {
                cnt[0]++;
            }
            else if (s == "ONE") {
                cnt[1]++;
            }
            else if (s == "TWO") {
                cnt[2]++;
            }
            else if (s == "THR") {
                cnt[3]++;
            }
            else if (s == "FOR") {
                cnt[4]++;
            }
            else if (s == "FIV") {
                cnt[5]++;
            }
            else if (s == "SIX") {
                cnt[6]++;
            }
            else if (s == "SVN") {
                cnt[7]++;
            }
            else if (s == "EGT") {
                cnt[8]++;
            }
            else if (s == "NIN") {
                cnt[9]++;
            }
        }
        cout << "#" << tc << "\n";
        for (int i = 0; i < 10; i++) {
            if (cnt[i]) {
                for (int j = 0; j < cnt[i]; j++) {
                    cout << num[i] << " ";
                }
            }
        }cout << "\n";
    }
}