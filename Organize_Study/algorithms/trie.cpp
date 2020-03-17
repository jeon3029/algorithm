#include<bits/stdc++.h>
using namespace std;
const int ALPHA = 26;
//trie alphabet
class Trie{
	public:
	bool isTerminal;
	Trie *child[ALPHA];
	Trie(){
		isTerminal = false;
		memset(child,0,sizeof(child));
	}
	~Trie(){
		for(int i=0;i<ALPHA;i++){
			if(child[i])delete child[i];
		}
	}
	void insert (const char* key){
		if(*key =='\0'){
			isTerminal = true;
		}
		else{
			int index = *key - 'A';
			if(child[index]==0){
				child[index] = new Trie();
			}
			child[index]->insert(key+1);
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
};
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Trie *root = new Trie();
	const char* words[5] = {"be","bee","can","cat","cd"};
	for(int i=0;i<5;i++){
		root->insert(words[i]);
	}
	printf("%s : be\n", root->find("be") != 0 ? "Prefix Exist" : "Prefix Not Exist");
	printf("%s : can\n", root->find("can") != 0 ? "Prefix Exist" : "Prefix Not Exist");
	printf("%s : a\n", root->find("a") != 0 ? "Prefix Exist" : "Prefix Not Exist");
	printf("%s : cat\n", root->find("cat") != 0 ? "Prefix Exist" : "Prefix Not Exist");
	printf("%s : c\n", root->find("c") != 0 ? "Prefix Exist" : "Prefix Not Exist");

	printf("\n");

	printf("%s : c\n", root->stringExist("c") != 0 ? "String Exist" : "String Not Exist");
	printf("%s : be\n", root->stringExist("be") != 0 ? "String Exist" : "String Not Exist");
	printf("%s : bee\n", root->stringExist("bee") != 0 ? "String Exist" : "String Not Exist");
	printf("%s : candy\n", root->stringExist("candy") != 0 ? "String Exist" : "String Not Exist");
	printf("%s : cd\n", root->stringExist("cd") != 0 ? "String Exist" : "String Not Exist");
	
	delete root;
}