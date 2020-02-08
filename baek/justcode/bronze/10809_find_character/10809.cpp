#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    string s;cin>>s;
    int answer[26];
    memset(answer,0,sizeof(answer));
    for(int i=0;i<s.size();i++){
        if(answer[s[i]-'a']==0){
            answer[s[i]-'a'] = i+1;
        }
    }
    for(int i=0;i<26;i++){
        cout<<answer[i]-1<<" ";
    }
    return 0;
}