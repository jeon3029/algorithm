#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int N;cin>>N;
    for(int t=0;t<N;t++){
        string s;cin>>s;
        int answer = 0;
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='X'){
                cnt=0;
            }
            else{
                cnt++;
                answer+=cnt;
            }
        }
        cout<<answer<<endl;
    }
    return 0;
}