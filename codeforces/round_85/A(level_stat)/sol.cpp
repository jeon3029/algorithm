#include<bits/stdc++.h>
using namespace std;
int N;
int Data[100][2];//pi ci
void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>Data[i][0]>>Data[i][1];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        string answer = "YES";
        for(int i=0;i<N;i++){
            if(Data[i][1]>Data[i][0]){
                answer = "NO";
                break;
            }
            if(i!=0){
                if(Data[i][1]<Data[i-1][1] || Data[i][0]<Data[i-1][0]){
                    answer="NO";
                    break;
                }
                if((Data[i][1]-Data[i-1][1])>(Data[i][0]-Data[i-1][0])){
                    answer="NO";
                    break;
                }
            }
        }
        cout<<answer<<"\n";
    }
}