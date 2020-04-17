#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
//predefined

int N,K;
vector<string> Word;
int answer;
int visited[26];
void input(){
    cin>>N>>K;
    rep(i,0,N){
        string s;cin>>s;
        Word.pb(s);
    }
}
void dfs(int pos,int cnt){
    if(cnt == K){
        int cur_ans = 0;
        rep(i,0,N){
            int flag=0;
            rep(j,0,Word[i].length()){
                if(visited[Word[i][j]-'a'])continue;
                else{
                    flag=1;
                    break;
                }
            }
            if(!flag)cur_ans++;
        }
        answer = max(answer,cur_ans);
    }
    else{
        rep(i,pos,26){
            if(!visited[i]){
                visited[i]=1;
                dfs(i+1,cnt+1);
                visited[i]=0;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    answer = 0;
    input();
    if(K<5) {
        answer = 0;
    }
    else{
        //known : a n t i c
        rep(i,0,N){
            Word[i] = Word[i].substr(4,Word[i].length()-8);
            sort(all(Word[i]));
            string temp;
            rep(j,0,Word[i].length()){
                if(Word[i][j]=='a' || Word[i][j]=='n' ||Word[i][j]=='t' ||Word[i][j]=='i' ||Word[i][j]=='c' )continue;
                else temp.append(1,Word[i][j]);
            }
            Word[i] = temp;
        }
        memset(visited,0,sizeof visited);
        visited['a'-'a']=1;
        visited['n'-'a']=1;
        visited['t'-'a']=1;
        visited['i'-'a']=1;
        visited['c'-'a']=1;
        K-=5;
        dfs(0,0);
    }
    cout<<answer<<"\n";
}