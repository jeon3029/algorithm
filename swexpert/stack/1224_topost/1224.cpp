#include<iostream>
#include<string>
#include<stack>
using namespace std;
int op(char c){
    switch(c){
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return -1;
    }
}
string toPost(string s){
    stack<char> st;
    string post;
    for(int i=0;i<s.size();i++){
        if(st.empty()){//비어있는 경우
            st.push(s[i]);
        }
        else if(s[i]>='0' && s[i]<='9'){//숫자인 경우
            post+=s[i];
        }
        //문자인 경우
        else if(s[i]=='(')st.push(s[i]);
        else if(s[i]==')'){//열린것을 찾을때 까지 pop
            while(!st.empty() && st.top()!='('){
                post+=st.top();
                st.pop();
            }
            st.pop();//pop '('
        }
        else{
            //연산자 낮은 것을 만날때까지 계속 빼준다
            while(!st.empty() && op(st.top())>=op(s[i])){
                post+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        post+=st.top();
        st.pop();
    }
    //cout<<post<<endl;
    return post;
}
int eval(string s){
    stack<int> number;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            number.push(s[i]-'0');
        }
        else{
            int a = number.top();number.pop();
            int b = number.top();number.pop();
            switch(s[i]){
                case '+':
                    number.push(a+b);
                    break;
                case '-':
                    number.push(b-a);
                    break;
                case '*':
                    number.push(a*b);
                    break;
                case '/':
                    number.push(b/a);
                    break;
            }
        }
    }
    return number.top();
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
        string s;cin>>s;
        string post = toPost(s);
        int answer = eval(post);
        cout<<"#"<<test_case<<" " <<answer<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}