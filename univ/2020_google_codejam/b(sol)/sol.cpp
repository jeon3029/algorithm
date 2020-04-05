#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
string S;
void input(){
    cin>>S;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        string answer;
        input();
        stack<int> s;//number,depth
        for(int i=0;i<S.size();i++){
            int val = S[i]-'0';
            if(s.empty()){
                int depth = 0;
                while(depth!=val){
                    depth++;
                    answer.append("(");
                    s.push(depth);
                }
                answer.append(to_string(val));
            }
            else{
                int depth = s.top();
                if(depth>val){
                    while(depth!=val){
                        depth--;
                        answer.append(")");
                        s.pop();
                    }
                    answer.append(to_string(val));
                }
                else if(depth==val){
                    answer.append(to_string(val));
                }
                else{//depth<val
                    while(depth!=val){
                        depth++;
                        answer.append("(");
                        s.push(depth);
                    }
                    answer.append(to_string(val));
                }
            }

        }
        while(!s.empty()){
            answer.append(")");
            s.pop();
        }
        cout<<"Case #"<<tc<<": "<<answer<<"\n";
    }
}