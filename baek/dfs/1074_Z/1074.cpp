#include<bits/stdc++.h>
using namespace std;
int Cnt=0;
int N,R,C;
int dfs(int x,int y,int len){
    if(len==1){
        if(x==R && y==C)return Cnt;
    }
    else{
        if(C<(y+len/2) && R<(x+len/2)) return dfs(x,y,len/2);
        else Cnt+= (len/2) * (len/2);
        
        if(C>=(y+len/2) && R<(x+len/2)) return dfs(x,y+len/2,len/2);
        else Cnt+= (len/2) * (len/2);

        if(R>=(x+len/2) && C<(y+len/2)) return dfs(x+len/2,y,len/2);
        else Cnt+= (len/2) * (len/2);

        return dfs(x+len/2,y+len/2,len/2);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>R>>C;
    int t=(0x1<<N);
    N=t;
    cout<<dfs(0,0,N)<<"\n";
}