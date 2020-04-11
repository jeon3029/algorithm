#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pi;
//predefined

int N;
vector<string> S;
void input(){
    cin>>N;
    S.clear();
    S = vector<string>(N);
    rep(i,0,N) cin>> S[i];
}
bool addhead(string &head, string s){//if impossible return 0;
    // cout<<"addhead : "<<head<<" "<<s<<"\n";
    if(head==""){
        head=s;return true;
    }
    else if(head.length()>=s.length()){
        rep(i,0,s.length()){
            if(head[i]!=s[i]){
                return false;
            }
        }
        return true;
    }
    else{
        rep(i,0,head.length()){
            if(head[i]!=s[i]){
                return false;
            }
        }
        rep(i,head.length(),s.length()){
            head.append(1,s[i]);
        }
        return true;
    }
}
bool addtail(string &tail, string s){//if impossible return 0;
    // cout<<"addtail : "<<tail<<" "<<s<<"\n";
    if(tail==""){
        tail=s;return true;
    }
    else if(tail.length()>=s.length()){
        reverse(all(tail));
        reverse(all(s));
        rep(i,0,s.length()){
            if(tail[i]!=s[i]){
                reverse(all(tail));
                return false;
            }
        }
        reverse(all(tail));
        return true;
    }
    else{
        reverse(all(tail));
        reverse(all(s));
        rep(i,0,tail.length()){
            if(tail[i]!=s[i]){
                reverse(all(tail));
                return false;
            }
        }
        rep(i,tail.length(),s.length()){
            tail.append(1,s[i]);
        }
        reverse(all(tail));
        return true;
    }
}
void addmid(string &mid,string temp){
    // cout<<"addmid : "<<mid<<" "<<temp<<"\n";
    mid.append(temp);
    return;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        string header="";
        string tail="";
        string mid="";
        string answer="";
        int flag = 0;
        rep(i,0,N){
            int len = S[i].length();
            //check head
            if(S[i][0]!='*'){
                string temp;
                int j=0;
                for(;j<len;j++){
                    if(S[i][j]=='*')break;
                }
                if(j==len){
                    if(answer!=""&&answer!=S[i]){
                        answer="*";
                        flag=1;break;
                    }
                    else{
                        answer = S[i];
                    }
                }
                temp = S[i].substr(0,j);
                if(!addhead(header,temp)){
                    answer = "*";
                    // cout<<"false"<<header<<" "<<temp<<"\n";
                    flag=1;break;
                }
            }
            if(flag)break;
            //check mid
            int l = len;
            int r = -1;
            rep(j,0,len){
                if(S[i][j]=='*'){
                    l=j;break;
                }
            }
            per(j,0,len){
                if(S[i][j]=='*'){
                    r=j;break;
                }
            }
            if(l<r){
                string temp;
                // cout<<l<<","<<r<<"\n";
                rep(j,l+1,r){
                    if(S[i][j]!='*')temp.append(1,S[i][j]);
                }
                addmid(mid,temp);
            }
            //check tail
            if(S[i][len-1]!='*'){
                string temp="";
                int j=0;
                // cout<<i<<","<<S[i]<<"\n";
                // reverse(S[i].begin(),S[i].end());
                reverse(all(S[i]));
                for(;j<len;j++){
                    if(S[i][j]=='*')break;
                }
                if(j==len){
                    if(answer!=""&&answer!=S[i]){
                        answer="*";
                        flag=1;break;
                    }
                    else{
                        answer = S[i];
                    }
                }
                else{
                    temp = S[i].substr(0,j);
                    // cout<<S[i]<<" "<<temp<<" "<<j<<"\n";
                    // cout<<", temp : "<<temp<<"\n";
                    reverse(all(temp));
                    if(!addtail(tail,temp)){
                        answer = "*";
                        flag=1;break;
                    }
                }
                reverse(all(S[i]));
            }
            if(flag)break;
        }
        if(answer==""){
            answer.append(header);
            answer.append(mid);
            answer.append(tail);
        }
        cout<<"Case #"<<tc<<": "<<answer<<"\n";
    }
}