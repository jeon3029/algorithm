#include<vector>
#include<string>
#include<iostream>
using namespace std;
bool isPalindrome(string s){
    for(int i=0;i<s.length()/2;i++){
        if(s[i] == s[s.length()-1-i])continue;
        else return false;
    }
    return true;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    T=10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        vector<string> map;
        int len;cin>>len;
        for(int i=0;i<8;i++){
            string s;
            cin>>s;
            map.push_back(s);
        }
        int answer = 0;
        //행 체크
        for(int i=0;i<map.size();i++){
            for(int j=0;j<map.size()-len+1;j++){
                string temp = map[i].substr(j,len);
                if(isPalindrome(temp)){
                    answer++;
                }
            }
        }
        for(int j=0;j<map.size();j++){
            for(int i=0;i<map.size()-len+1;i++){
                string temp;
                for(int k=0;k<len;k++){
                    temp.push_back(map[i+k][j]);
                }
                if(isPalindrome(temp)){
                    answer++;
                }
            }
        }
        cout<<"#"<<test_case<<" "<<answer<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
