#include<bits/stdc++.h>
using namespace std;
char swit(char c){
    return c=='W'?'B':'W';
}
int main(void)
{
    int N,M;cin>>N>>M;
    vector<string> a;
    for(int i=0;i<N;i++){
        string s;cin>>s;
        a.push_back(s);
    }
    int min = 987654321;
    for(int i=0;i<=N-8;i++){
        for(int j=0;j<=M-8;j++){
            //coloring
            char check = 'W';
            int cnt=0;
            for(int x=i;x<i+8;x++){
                for(int y=j;y<j+8;y++){
                    if(a[x][y]!=check){
                        cnt++;
                    }
                    check=swit(check);
                }check=swit(check);
            }
            if(min>cnt)min=cnt;
            check = 'B';
            cnt=0;
            for(int x=i;x<i+8;x++){
                for(int y=j;y<j+8;y++){
                    if(a[x][y]!=check){
                        cnt++;
                    }
                    check=swit(check);
                }check=swit(check);
            }
            if(min>cnt)min=cnt;
        }
    }
    cout<<min;
    return 0;
}