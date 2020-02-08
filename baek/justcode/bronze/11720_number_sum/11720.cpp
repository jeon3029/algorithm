#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int N;cin>>N;
    string s;cin>>s;
    int answer=0;
    for(int i=0;i<s.size();i++){
        answer +=s[i]-'0';
    }
    cout<<answer;
    return 0;
}