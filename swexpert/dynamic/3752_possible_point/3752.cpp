#include<bits/stdc++.h>
using namespace std;
int N;
bool check[100*100+1];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    for(int t_case=1; t_case<=t;t_case++){
        cin>>N;
        vector<int> answer;
        answer.clear();
        memset(check,0,sizeof(check));
        answer.push_back(0);
        int point;
        for(int i=0;i<N;i++){
            cin>>point;
            int len = answer.size();
            for(int j=0;j<len;j++){
                int number = answer[j] + point;
                if(!check[number]){
                    check[number]=1;
                    answer.push_back(number);
                }
            }
        }
        cout<<"#"<<t_case<<" "<<answer.size()<<"\n";
    }
}