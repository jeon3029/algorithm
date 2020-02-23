#include<bits/stdc++.h>
using namespace std;
vector<string> answer;
int K;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> K;
		answer.clear();
		string s; cin >> s;
		for(int i=0;i<s.size();i++){
			for(int j=i;j<s.size();j++){
				string p = s.substr(i,j-i+1);
				answer.push_back(p);
			}
		}
		int pos=0;
		int i;
		sort(answer.begin(),answer.end());
		for(i=0;i<answer.size();i++){
			if(answer[i]!=answer[i+1]){
				pos++;
			}
			if(pos==K){
				break;
			}
		}
		if (i >= answer.size()) {
			cout << "#"<< tc << " "<<"none"<<"\n";
		}
		else{
			cout<<"#"<<tc<<" "<<answer[i]<<"\n";
		}
	}
}