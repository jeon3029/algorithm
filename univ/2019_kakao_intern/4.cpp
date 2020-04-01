#include <string>
#include <vector>
#include<iostream>
#include <unordered_map>
using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    unordered_map <long long,long long*> m;
    int cnt = 0;
    for(int i=0;i<room_number.size();i++){
        long long cur = room_number[i];
        long long* inserted;
        if(m.find(cur)!=m.end()){
            inserted = m[cur];
        }
        else{
            inserted = new long long;
        }
        while(1){
            if(m.find(cur)!=m.end()){
                cur= *m[cur]+1;
            }
            else{
                *inserted = cur;
                m.insert({cur,inserted});
                break;
            }
        }
        answer.push_back(cur);
    }
    return answer;
}
int main(){
    long long k, n;
    cin>>k>>n;
    vector<long long> room(n);
    for(int i=0;i<n;i++){
        cin>>room[i];
    }
    vector<long long> ans = solution(k,room);
    for(auto it:ans){
        cout<<it<<" ";
    }cout<<"\n";
}