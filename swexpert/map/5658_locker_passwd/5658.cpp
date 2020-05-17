#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
int N,T;
string s;
void input(){
    cin>>N>>T;
    cin>>s;
}
bool cmp(string s1,string s2){
    return s1>s2;
}
string calc(){
    map<string,int,greater<string>> passwd;
    int idx = 0;
    rep(i,0,N/4){
        string cur_s;
        cur_s.append(s.substr(N-i,i));
        cur_s.append(s.substr(0,N-i));
        rep(j,0,4){
            string gen = cur_s.substr(j*N/4,N/4);
            if(passwd.find(gen)==passwd.end()){
                passwd.insert({gen,idx++});
            }
        }
    }
    int cnt=1;
    for(auto i:passwd){
        if(cnt == T){
            return i.first;
        }
        cnt++;
    }
    return "can't find";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        string pass = calc();
        long long answer = 0;
        long long mul = 1;
        per(i,0,pass.length()){
            if(pass[i]>='A' && pass[i]<='F'){
                answer+= (pass[i]-'A'+10)*mul;
            }
            else answer += (pass[i]-'0') *mul;
            mul<<=4;
        }
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
}