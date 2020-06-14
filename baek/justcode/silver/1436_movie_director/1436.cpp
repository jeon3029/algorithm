#include<bits/stdc++.h>
using namespace std;
int N;
void input(){
    cin>>N;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    int cnt = 0;
    for(long long i=666;;i++){
        int num = i;
        int count6 = 0;
        while(num != 0){
            int now = num % 10;
            if(now == 6)count6++;
            else count6 = 0;
            if(count6 == 3)break;
            num/=10;
        }
        if(count6 == 3)cnt++;
        if(cnt == N){
            cout<< i <<"\n";
            break;
        }
    }
}