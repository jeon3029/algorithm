#include<bits/stdc++.h>
using namespace std;
bool mycmp(pair<pair<int,string>,int> a,pair<pair<int,string>,int> b){
    if(a.first.first==b.first.first){
        return a.second<b.second;
    }
    else return a.first.first<b.first.first;
}
int main(int argc, char** argv){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<pair<pair<int,string>,int> > data;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int age;
        string name;
        cin>>age>>name;
        data.push_back(make_pair(make_pair(age,name),i));
    }
    sort(data.begin(),data.end(),mycmp);
    for(int i=0;i<N;i++){
        cout<<data[i].first.first<<" "<<data[i].first.second<<"\n";
    }
}