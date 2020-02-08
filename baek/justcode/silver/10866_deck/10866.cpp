#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int N;cin>>N;
    deque<int> A;
    for(int t=0;t<N;t++){
        char s[30];cin>>s;
        if(strcmp(s,"push_front")==0){
            int num;cin>>num;
            A.push_front(num);
        }
        else if(strcmp(s,"push_back")==0){
            int num;cin>>num;
            A.push_back(num);
        }
        else if(strcmp(s,"pop_front")==0){
            if(A.empty())cout<<"-1"<<endl;
            else{
                cout<<A.front()<<'\n';
                A.pop_front();
            }
        }
        else if(strcmp(s,"pop_back")==0){
            if(A.empty())cout<<"-1"<<'\n';
            else{
                cout<<A.back()<<'\n';
                A.pop_back();
            }
        }
        else if(strcmp(s,"size")==0){
            cout<<A.size()<<'\n';
        }
        else if(strcmp(s,"empty")==0){
            cout<<A.empty()<<'\n';
        }
        else if(strcmp(s,"front")==0){
            if(A.empty())cout<<"-1"<<'\n';
            else{
                cout<<A.front()<<'\n';
            }
        }
        else if(strcmp(s,"back")==0){
            if(A.empty())cout<<"-1"<<'\n';
            else{
                cout<<A.back()<<'\n';
            }
        }
    }
}
//endl 은 웬만하면 사용을 하지 말자