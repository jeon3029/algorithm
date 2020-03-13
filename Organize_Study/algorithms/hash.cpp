#include<bits/stdc++.h>
using namespace std;
const int MAX_TABLE = 1000;
char S[MAX_TABLE][2][100];
unsigned long my_hash(char *str){
    unsigned long hash = 5381;
    int c;
    while(c=*str++){
        hash = (((hash<<5)+hash)+c)%MAX_TABLE;
    }
    return hash%MAX_TABLE;
}
int main(){
    int T;cin>>T;
    
    for(int tc=1;tc<=T;tc++){
        cout<<"#"<<tc<<"\n";
        int n,m;
        cin>>n;
        for(int i=0;i<n;i++){
            char a[100],b[100];
            cin>>a>>b;
            unsigned long h = my_hash(a);
            strcpy(S[h][0],a);
            strcpy(S[h][1],b);
        }
        cin>>m;
        
        for(int i=0;i<m;i++){
            char a[100];
            cin>>a;
            unsigned long h = my_hash(a);
            if(strlen(S[h][0])!=0){
                cout<<S[h][1]<<"\n";
            }
            else cout<<"not find\n";
        }
    }

}
