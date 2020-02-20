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
        if(s[i]>='A' && s[i]<='Z'){//숫자인 경우
            post+=s[i];
        }
        else if(st.empty()){//비어있는 경우
            st.push(s[i]);
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
    return post;
}
int main(int argc, char** argv){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;cin>>s;
    string post = toPost(s);
    cout<<post<<endl;
	return 0;
}