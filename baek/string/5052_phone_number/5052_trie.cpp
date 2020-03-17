#include<bits/stdc++.h>
using namespace std;
const int NUM = 10;//0~9
class Trie{
public:
	bool isTerminal;
	Trie *child[NUM];
	Trie(){
		isTerminal=false;
		memset(child,0,sizeof(child));
	}
	~Trie(){
		for(int i=0;i<NUM;i++){
			if(child[i])delete child[i];
		}
	}
	void insert(const char*key){
		if(*key=='\0'){
			isTerminal = true;
		}
		else{
			int index = *key - '0';
			if(!child[index]){
				child[index] = new Trie();
			}
			child[index]->insert(key+1);
		}
	}
};
bool dfs(Trie* t){
	vector<int> next;
	for(int i=0;i<NUM;i++){
		if(t->child[i])next.push_back(i);
	}
	if(t->isTerminal && next.size()!=0){
		return true;
	}
	for(int i=0;i<next.size();i++){
		bool ret = dfs(t->child[next[i]]);
		if(ret)return true;
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;cin>>T;
	while(T--){
		int k;
		Trie* root = new Trie();
		cin>>k;
		for(int i=0;i<k;i++){
			char phoneNum[11];
			cin>>phoneNum;
			root->insert(phoneNum);
		}
		//search for common prefix
		bool ans = dfs(root);
		if(ans){
			cout<<"NO"<<"\n";
		}
		else{
			cout<<"YES"<<"\n";
		}
	}
}