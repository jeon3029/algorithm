/**
 * @author [jeon3029]
 * @email [jeon3029@naver.com]
 * @create date 2020-04-08 10:55:04
 * @modify date 2020-04-08 11:21:36
 * @desc [implement]
 */
#include<bits/stdc++.h>
using namespace std;
int N,M;
int Data[1001][1001];
int answer = 0;
void input(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        for(int j=0;j<M;j++){
            Data[i][j]=s[j]-'0';
        }
    }
}
bool check(int x,int y,int len){//x,y부터 len거리의 layer가 모두 참인지 확인
    if(x+len>N)return false;
    if(y+len>M)return false;
    for(int i=x;i<x+len;i++){
        if(Data[i][y+len-1]==0)return false;
    }
    for(int j=y;j<y+len;j++){
        if(Data[x+len-1][j]==0)return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    for(int i=0;i<N;i++){
        if(N-i < answer)break;
        for(int j=0;j<M;j++){
            if(M-j < answer)break;
            for(int len=1;len<=N;len++){
                if(check(i,j,len)){
                    answer = max(answer,len);
                }
                else break;
            }
        }
    }
    cout<<answer*answer<<"\n";
}