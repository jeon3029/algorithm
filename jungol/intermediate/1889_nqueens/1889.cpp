#include <string>
#include <vector>
#include <iostream>
using namespace std;
int answer = 0;
int N;
using namespace std;
void back(vector<int> list) {
	if (list.size() == N) {
		answer++;
		return;
	}
	for (int i = 0; i < N; i++) {
		int check = 0;
		int v = 1;
		for (int j = list.size() - 1; j >= 0; j--) {
			if (i - v == list[j] || i + v == list[j]) {
					check = 1;
                	break;
			}
            if (list[j] == i) {
				check = 1;
                break;
			}
            v++;
		}
		if (check == 1) {
			continue;
		}
		list.push_back(i);
		back(list);
		list.pop_back();
	}
}
int main() {
	cin>>N;
    vector<int> list;
	back(list);
	cout << answer << endl;
	return 0;
}