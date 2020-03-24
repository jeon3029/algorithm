#include<bits/stdc++.h>
using namespace std;
bool cmp(vector<int> a,vector<int> b){
    return a[0]<b[0];
}
bool Dp[500001];
int main(){
    int n;
    cin>>n;
    vector<vector<int>> money(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        money[i].push_back(a);
        money[i].push_back(b);
        sum+=a*b;
    }
    memset(Dp,0,sizeof(Dp));
    for(int i=1;i<=money[0][1];i++){
        Dp[i*money[0][0]]=1;
    }
    int answer = 0;
    for(int i=1;i<n;i++){
        for(int j=sum/2;j>=1;j--){
            if(Dp[j]){
                for(int k=1;k<=money[i][1];k++){
                    Dp[j+k*money[i][0]]=1;
                }
            }
        }
    }
    for(int i=0;i<=sum/2;i++){
        if(Dp[i])answer = i;
    }
    answer = sum-(answer*2);
    cout<<answer<<"\n";
}