//unsolved
#include<bits/stdc++.h>
using namespace std;
const int ALPHA = 26;
int N,K;
int score;
class Trie{
	public:
	bool isTerminal;
	int count;
	int depth;
	Trie *child[ALPHA];
	Trie(){
		isTerminal = false;
		count = 0;
		depth = 0;
		memset(child,0,sizeof(child));
	}
	~Trie(){
		for(int i=0;i<ALPHA;i++){
			if(child[i])delete child[i];
		}
	}
	void insert (const char* key,int d){
		count++;
		depth = d;
		if(*key =='\0'){
			isTerminal = true;
		}
		else{
			int index = *key - 'A';
			if(child[index]==0){
				child[index] = new Trie();
			}
			child[index]->insert(key+1,depth+1);
		}
	}
	Trie *find(const char* key){
		if(*key==0){
			return this;
		}
		int index = *key - 'A';
		if(child[index]==0){
			return nullptr;
		}
		return child[index]->find(key+1);
	}
	bool stringExist(const char*key){
		if(*key==0 && isTerminal){
			return true;
		}
		int index = *key - 'A';
		if(child[index]==0){
			return false;
		}
		return child[index]->stringExist(key+1);
	}
	int search(){
		
		int temp = 0;
		for(int i=0;i<ALPHA;i++){
			if(child[i]){
				temp += child[i]->search();
			}
		}
		count -=temp;
		if(count == K){
			score += depth;
			// cout<<score<<"\n";
			return count + temp;
		}
		return temp;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;cin>>T;
	for(int tc=1;tc<=T;tc++){
		Trie *root = new Trie();
		cin>>N>>K;
		for(int i=0;i<N;i++){
			char s[200000];
			cin>>s;
			root->insert(s,0);
		}
		score = 0;
		root->search();
		cout<<"Case #"<<tc<<": "<<score<<"\n";
	}
}