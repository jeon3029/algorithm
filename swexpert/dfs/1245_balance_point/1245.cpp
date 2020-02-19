#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int N;
int L, R;
vector<pi> Data(10);//x, weight
int check(long double pos) {
    long double sum = 0;
    for (auto it : Data) {
        long double diff = 10*abs(it.first - pos);
        if (it.first > pos) {
            sum +=it.second / (diff*diff);
        }
        else {
            sum -=it.second / (diff*diff);
        }
    }
    if(sum==0){
        return 0;
    }
    else {
        if (sum > 0)return 1;
        else return -1;
    }
}
double find(long double left, long double right) {
    while (1) {
        long double mid = (left + right) / 2;
        int result = check(mid);
        long double c = mid;
        if (check(c+1e-12)>0 && check(c-1e-12)<0 ||c==0) {
            return mid;
        }
        else if (result == 1) {
            right = mid - 1e-12;
        }
        else {
            left = mid + 1e-12;
        }
    }
}
int main() {
    int t; cin >> t;
     
    for (int tc = 1; tc <= t; tc++) {
        cin >> N;
        for (int i = 0; i < 10; i++) {
            Data[i].first = 0;
            Data[i].second = 0;
        }
        for (int i = 0; i < N; i++) {
            int a; cin >> a;
            Data[i].first = a;
        }
        for (int i = 0; i < N; i++) {
            int a; cin >> a;
            Data[i].second = a;
        }
        sort(Data.begin(), Data.begin() + N);
        cout << "#" << tc << " ";
        for (int i = 0; i < N - 1; i++) {
            double answer = find(Data[i].first, Data[i + 1].first);
            cout << fixed;
            cout.precision(10);
            cout << answer << " ";
        }
        cout << "\n";
    }
}