#include<bits/stdc++.h>
using namespace std;
vector<int> nums(10);
int S;
int D[1001];
int X;
int answer;
void input(){
    for(int i=0;i<10;i++){
        cin>>nums[i];
    }
    cin>>X;
}
int isMake(int temp){
    int cnt=0;
    while(1){
        int num = temp%10;
        if(nums[num])cnt++;
        else return -2;
        temp/=10;    
        if(temp==0)break;
    }
    return cnt;
}
int dfs(int x){
    if(x<=S &&D[x]!=0)return D[x];
    int cnt=-2;
    cnt = isMake(x);
    if(cnt!=-2){
        if(x<=S)D[x] = cnt;
        return cnt;
    }
    else{
        int len = sqrt(x);
        for(int i=2;i<=len;i++){
            if(x%i==0){
                int len1 = dfs(i);
                if(len1!=-2){
                    int len2 = dfs(x/i);
                    if(len2!=-2){
                        if(cnt==-2){
                            cnt = len1+len2+1;
                        }
                        else{
                            cnt = min(cnt,len1+len2+1);   
                        }
                    }
                }
                
            }
        }
    }
    if(cnt!=-2 && x<=S)D[x] = cnt;
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        memset(D,0,sizeof(D));
        S=sqrt(X);
        answer=dfs(X);
        cout<<"#"<<tc<<" "<<answer+1<<"\n";
    }
}