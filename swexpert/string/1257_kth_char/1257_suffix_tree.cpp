#include<bits/stdc++.h>
using namespace std;
class SuffixNode{
	public:
	string s;
	int pos;
	SuffixNode(string _s,int i){
		s=_s;pos=i;
	}
	SuffixNode(){}
};
bool cmp(SuffixNode a,SuffixNode b){
	return a.s<b.s;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;cin>>T;
	for(int tc=1;tc<=T;tc++){
		int k;string s;
		string answer;
		vector<SuffixNode> suffixArray;
		vector<int> lcp;
		cin>>k>>s;
		for(int i=0;i<s.length();i++){
			string temp = s.substr(i,s.length()-i);
			suffixArray.push_back(SuffixNode(temp,i));
		}
		sort(suffixArray.begin(),suffixArray.end(),cmp);
		
		lcp.push_back(0);
		for(int i=1;i<suffixArray.size();i++){
			int len = min(suffixArray[i-1].s.length(),suffixArray[i].s.length());
			int j;
			for(j=0;j<len;j++){
				if(suffixArray[i-1].s[j]!=suffixArray[i].s[j])break;
			}
			lcp.push_back(j);
		}
		//note that all prefix of suffix = all substring of input
		//find k th string
		int pos = 0;
		int flag = 0;
		for(int i=0;i<suffixArray.size();i++){
			pos -=lcp[i];
			if(pos + suffixArray[i].s.length()>=k ){
				int start = suffixArray[i].pos;
				int count = k-pos;
				answer = s.substr(start,count);
				flag = 1;
				break;
			}
			pos+=suffixArray[i].s.length();
		}
		if(!flag)answer = "none";
		cout<<"#"<<tc<<" "<<answer<<"\n";
	}
}