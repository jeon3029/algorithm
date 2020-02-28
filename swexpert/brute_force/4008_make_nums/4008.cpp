#include<bits/stdc++.h>
using namespace std;
int N;
vector<int> D(12);
vector<int> O(4);
const int INF = 1100000000;
int answer_max;
int answer_min;
int calc(vector<int> op){
    int answer = D[0];
    int pos=1;
    for(auto it:op){
        if(it==0){
            answer+=D[pos++];
        }
        else if(it==1){
            answer-=D[pos++];
        }
        else if(it==2){
            answer*=D[pos++];
        }
        else{
            answer/=D[pos++];
        }
    }
    return answer;  
}
void dfs(vector<int> op,int len){
    if(len==N-1){
        int temp = calc(op);
        answer_max=max(answer_max,temp);
        answer_min=min(answer_min,temp);
    }
    else{
        for(int i=0;i<4;i++){
            if(O[i]){
                O[i]--;
                op.push_back(i);
                dfs(op,len+1);
                op.pop_back();
                O[i]++;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        cin>>N;
        for(int i=0;i<4;i++){
            cin>>O[i];
        }
        for(int i=0;i<N;i++){
            cin>>D[i];
        }
        answer_max = -INF;answer_min=INF;
        dfs(vector<int>(),0);
        cout<<"#"<<tc<<" "<<answer_max-answer_min<<"\n";
    }
}