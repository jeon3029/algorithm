#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
string target;
int n;
vector<int> nums(10,0);
int cnt = 0;
int answer = 987654321;
void input(){
    cin>>target>>n;
    rep(i,0,n){
        int temp;cin>>temp;
        nums[temp]=1;
    }
}
bool possible(int now){
    if(now==0){
        return nums[0]==0;
    }
    while(now!=0){
        int t = now % 10;
        now /= 10;
        if(nums[t] == 1)return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    if(abs(atoi(target.c_str()) - 100) < answer){
        answer = abs(atoi(target.c_str()) - 100);
    }
    int t = atoi(target.c_str());
    for(int i = 0;i<=1000000;i++){
        if(possible(i)){
            int temp = i;
            int len = 0;
            if(temp == 0)len=1;
            while(temp!=0){
                len++;temp/=10;
            }
            if(len + abs(t-i) <answer){
                answer = len + abs(t-i);
            }
        }
    }
    cout<<answer<<"\n";
}