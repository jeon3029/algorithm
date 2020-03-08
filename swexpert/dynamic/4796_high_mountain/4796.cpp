#include<bits/stdc++.h>
using namespace std;
int Data[50000];
int N;
void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>Data[i];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        int answer = 0;
        int start = -1;
        int middle = -1;
        int flag = 1;//1 : 오르막, -1 : 내리막
        for(int i=0;i<N;i++){
            if(Data[i]<Data[i+1]){
                start = i;break;
            }
        }
        if(start!=-1)
        for(int i=start+1;i<N;i++){
            if(flag==1){
                if(Data[i]>Data[i-1]){
                    continue;
                }
                else{
                    flag = -1;
                    middle = i-1;
                }
            }
            if(flag==-1){
                if(Data[i]<Data[i-1]){
                    if(i==N-1){
                        if(i>=start+2) answer+=(middle-start)*(i-middle);
                    }
                }
                else{
                    if(i>start+2) answer+=(middle-start)*(i-1-middle);
                    flag = 1;
                    start = i-1;
                    middle = i-1;
                }
            }
        }
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
}