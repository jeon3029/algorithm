#include<bits/stdc++.h>
using namespace std;
int N;
int Data[100][100];
int k,r,c;
void input(){
    cin>>N;
    k=r=c=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>Data[i][j];
            if(i==j)k+=Data[i][j];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        int checkVisited[N+1];
        
        //check row
        for(int i=0;i<N;i++){
            memset(checkVisited,0,sizeof(checkVisited));
            for(int j=0;j<N;j++){
                if(!checkVisited[Data[i][j]])checkVisited[Data[i][j]]=1;
                else{
                    r++;
                    break;
                }
            }    
        }
        //check col
        for(int i=0;i<N;i++){
            memset(checkVisited,0,sizeof(checkVisited));
            for(int j=0;j<N;j++){
                if(!checkVisited[Data[j][i]])checkVisited[Data[j][i]]=1;
                else{
                    c++;
                    break;
                }
            }    
        }
        cout<<"Case #"<<tc<<": "<<k<<" "<<r<<" "<<c<<"\n";
    }
}