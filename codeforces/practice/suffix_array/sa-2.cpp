#include<bits/stdc++.h>
using namespace std;
//predefined
string s;
void input(){
    cin>>s;
}
//O n * (logn)^2
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    s += "$";
    int n = s.size();
    vector<int> p(n),c(n);
    {
        //base case k=0    
        vector<pair<char,int>> a(n);
        for(int i=0;i<n;i++)a[i] = {s[i],i};
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i=1;i<n;i++){
            if(a[i].first == a[i-1].first)c[p[i]] = c[p[i-1]];
            else c[p[i]] = c[p[i-1]]+1;
        }
    }
    //transition
    int k = 0;
    while((1<<k)<n){
        vector<pair<pair<int,int>,int>> a(n);
        for(int i=0;i<n;i++){
            a[i] = {{c[i],c[(i+(1<<k))%n]},i};
        }
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i=1;i<n;i++){
            if(a[i].first == a[i-1].first)c[p[i]] = c[p[i-1]];
            else c[p[i]] = c[p[i-1]]+1;
        }
        k++;
    }
    for(int i=0;i<n;i++){
        cout<<p[i]<<" ";
    }cout<<"\n";
    // for(int i=0;i<n;i++){
    //     cout<<c[i]<<" ";
    // }cout<<"\n";
    
    vector<int> lcp(n);
    int len = 0;
    for(int i=0;i<n-1;i++){
        int pos = c[i];
        int j = p[pos-1];
        while( s[i+len] ==  s[j+len])
            len++;
        lcp[pos] = len;
        //cout <<pos<<" : "<<len<<"\n";
        len = max(len-1,0);
    }
    // for(int i=0;i<n;i++){
    //     if (i) cout<< lcp[i]<<" ";
    //     else cout<< "x" <<" ";
    // }cout<<"\n";
}