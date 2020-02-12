#include<bits/stdc++.h>
using namespace std;
int N;
char expression[30];
int eval(int check){
    vector<string> s;
    for(int i=0;i<N;i++){
        if(i%2==0 && check & (1<<(i/2))){
            char op = expression[i+1];
            int a = expression[i]-'0';
            int b = expression[i+2]-'0';
            switch(op){
                case '+':
                    s.push_back(to_string(a+b));
                    break;
                case '-':
                    s.push_back(to_string(a-b));
                    break;
                case '*':
                    s.push_back(to_string(a*b));
                    break;
            }
            i+=2;
        }
        else{
            string temp;
            temp.append(1,expression[i]);
            s.push_back(temp);
        }        
    }
    stack<int> st;
    string op;
    for(auto it:s){
        if(it=="+" || it=="-"||it=="*"){
            op = it;
        }
        else{
            if(st.empty()){
                st.push(atoi(it.c_str()));
            }
            else{
                if(op=="+"){
                    int a = st.top();
                    st.pop();
                    st.push(a+atoi(it.c_str()));
                }
                else if(op=="-"){
                    int a = st.top();
                    st.pop();
                    st.push(a-atoi(it.c_str()));
                }
                else if(op=="*"){
                    int a = st.top();
                    st.pop();
                    st.push(a*atoi(it.c_str()));
                }
            }
        }
    }
    return st.top();
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    cin>>expression;
    int check_size = N/2;
    int Max = eval(0);
    for(int check=1;check<(1<<check_size);check++){
        int t = check & 0x1;
        int f=0;
        for(int i=1;i<check_size;i++){
            if(t && (t == (check<<i))){
                f=1;break;
            }
            t=(check<<i);
        }
        if(f)break;
        int result = eval(check);
        Max = max(Max,result);
    }
    cout<<Max<<"\n";
}