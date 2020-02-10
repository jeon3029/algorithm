#include<bits/stdc++.h>
using namespace std;
int N;
vector<int> point(100,0);
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
        for(int i=0;i<N;i++){
            cin>>point[i];
            vector<int> temp;
            for(int j=0;j<answer.size();j++){
                int number = answer[j] + point[i];
                if(!check[number]){
                    check[number]=1;
                    temp.push_back(number);
                }
            }
            answer.insert(answer.end(),temp.begin(),temp.end());
        }  
        // for(int i=0;i<1000;i++){
        //     if(check[i])cout<<i<<" ";
        // }cout<<"\n";
        cout<<"#"<<t_case<<" "<<answer.size()<<"\n";
    }
}