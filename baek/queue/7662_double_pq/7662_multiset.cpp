#include <iostream>
#include <set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    int k;
    while (T--) {
        multiset<int> ms;
        cin >> k; 
        while (k--) {
            char i;
            int num;
            cin >> i >> num;  
            if (i == 'I') {
                ms.insert(num);
            }
            else if (i == 'D') {
                if (ms.empty()) continue;
                if (num == 1) {
                    //최댓값 삭제
                    ms.erase(--ms.end());
                }
                else {
                    //최솟값 삭제
                    ms.erase(ms.begin());
                }
            }
        }
        if (ms.empty()) cout << "EMPTY" << '\n';
        else cout << *(--ms.end()) << ' ' << *ms.begin() << "\n";
    }
    return 0;
}
