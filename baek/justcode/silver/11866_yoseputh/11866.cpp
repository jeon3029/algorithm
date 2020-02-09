#include<bits/stdc++.h>
using namespace std;
int main(int argc, char** argv)
{
    int n,x;
    cin>>n>>x;
    vector<int> data(n,0);
    for(int i=0;i<n;i++){
        data[i] = i+1;
    }
    int pos = 0;x--;
    vector<int> answer;
    for(int i=0;i<n;i++){
        pos = (pos+x)%data.size();
        answer.push_back(data[pos]);
        data.erase(data.begin()+pos,data.begin()+pos+1);
        
    }
    cout<<"<";
    for(int i=0;i<answer.size();i++){
        if(i<answer.size()-1)cout<<answer[i]<<", ";
        else cout<<answer[i]<<">";
    }
}