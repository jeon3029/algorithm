#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool isPair(char a,char b){
    if(a=='<'&&b=='>')return true;
    if(a=='['&&b==']')return true;
    if(a=='{'&&b=='}')return true;
    if(a=='('&&b==')')return true;
    return false;
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
        int t;cin>>t;
        string s;
        cin>>s;
        stack<char> st;
        for(int i=0;i<s.length();i++){
            char current = s[i];
            if(st.empty()){
                st.push(current);
            }
            else{
                if(isPair(st.top(),current))st.pop();
                else st.push(current);
            }
        }
        int answer;
        st.empty()?answer=1:answer=0;
        cout<<"#"<<test_case<<" " <<answer<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}