#include<iostream>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,x;
        cin>>n>>x;
        int max=0,max_d=-987654321;
        int res=0;
        while(n--){
            int t1,t2;cin>>t1>>t2;
            if(t1>max)max=t1;
            if(t1-t2>max_d){
                max_d = t1-t2;
            }
        }
        x-=max;//막타
        if(x<=0)res = 1;
        else{
          if(max_d<=0)res = -1;
          else{
            res = x/max_d + 1;
            int t = x%max_d;
            if(t!=0)res++;
            //res = (x+max_d-1)/max_d + 1; --> 올림해주는 효과 !!
          }
        }
        cout<<res<<endl;
    }
    return 0;
}
