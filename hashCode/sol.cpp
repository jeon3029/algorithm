#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int B,L,D;
vector<pi> score;//index,score

class Library{
public:
    vector<pi> books;//index,score
    int index;
    int signup;
    int ship;
    int sum;
    Library(){
        index=0;
        signup=0;
        ship=0;
        sum=0;
    }
};
vector<Library> Lib;
void input(){
    cin>>B>>L>>D;
    for(int i=0;i<B;i++){
        int b;cin>>b;
        score.emplace_back(i,b);
    }
    for(int i=0;i<L;i++){
        Library l;
        int b,si,sh;
        cin>>b>>si>>sh;
        l.signup=si;l.ship=sh;
        l.index=i;
        for(int j=0;j<b;j++){
            int bb;cin>>bb;
            l.sum+=score[bb].second;
            l.books.emplace_back(bb,score[bb].second);
        }
        Lib.push_back(l);
    }
}
//처음기준 signup작은 것
//두번째 기준 가지고 있는 책의 수 많은 것
//세번째 기준 signup이 큰 순서
bool cmpL(Library a, Library b){
    // if(a.signup==b.signup){
    //     if(a.books.size()==b.books.size()){
    //         return a.ship>b.ship;
    //     }
    //     else return a.books.size()>b.books.size();
    // }
    return a.signup<b.signup;
}
//처음기준 score높은 것
//TODO 중복을 최대한 줄이는 것 생각
bool cmpB(pi a,pi b){
    return a.second>b.second;
}
bool usedBooks[100001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    sort(Lib.begin(),Lib.end(),cmpL);
    set<int> sended_books;
    int curT = 0;
    int f=0;
    vector<int> outLib;
    vector<vector<int>> outBooks;
    
    for(int i=0;i<Lib.size();i++){
        Library curL = Lib[i];
        curT += curL.signup;
        if(curT>D)break;
        outLib.push_back(curL.index);
        
        int len = (curL.books.size()+curL.ship-1)/curL.ship;
        sort(curL.books.begin(),curL.books.end(),cmpB);
        
        int cnt=0;
        vector<int> ob;

        for(int t=curT;t<curT+len;t++){
            if(t>D){
                f=1;
                break;
            }
            vector<int> already;
            for(int k=0;(k<curL.ship && cnt<curL.books.size());k++){
                int temp = curL.books[cnt++].first;
                if(usedBooks[temp]==0){
                    usedBooks[temp]=1;
                    sended_books.insert(temp); 
                    ob.push_back(temp);
                }
                else{
                    already.push_back(temp);
                }
            }
            for(int k=0;k<already.size();k++){
                ob.push_back(already[k]);
            }
        }
        outBooks.push_back(ob);
        if(f==1)break;
    }
    cout<<outLib.size()<<"\n";
    for(int i=0;i<outLib.size();i++){
        cout<<outLib[i]<<" "<<outBooks[i].size()<<"\n";
        for(int j=0;j<outBooks[i].size();j++){
            cout<<outBooks[i][j]<<" ";
        }
        cout<<"\n";
    }

}