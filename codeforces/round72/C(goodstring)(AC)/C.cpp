#include<bits/stdc++.h>
using namespace std;
char in[200001];
int L[200001];
long long solve() {
    cin >> in +1;
    int n = strlen(in + 1);
    L[0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (in[i] == '0') L[i] = L[i - 1];
        else L[i] = i + 1;
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x = 0;
        for (int j = i; j > 0 && i - j <= 20; --j) {
            if (in[j] == '1') x |= 1 << (i - j);
            if (i - j + 1 == x) ++ans;
        }
        if (i - 20 > 1) {
            int l = L[i - 20 - 1];
            int mn = 22;
            int mx = i - l + 1;
            if (mn <= x && x <= mx) ++ans;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) printf("%lld\n", solve());
    return 0;
}
