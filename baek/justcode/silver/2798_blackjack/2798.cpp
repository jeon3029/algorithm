#include<bits/stdc++.h>
using namespace std;
int main(int argc, char** argv)
{
    int N,M;
    cin>>N>>M;
    vector<int> deck(N,0);
    for(int i=0;i<N;i++){
        cin>>deck[i];
    }
    vector<int> combi(3,1);
    vector<int> comb_add(N-3,0);
    combi.insert(combi.begin(),comb_add.begin(),comb_add.end());
    int sum = 0;
    do{
        int current = 0;
        for(int i=0;i<N;i++){
            if(combi[i]==1) current+=deck[i];
        }
        if(current<=M && sum<current)sum=current;
    }while(next_permutation(combi.begin(),combi.end()));
    cout<<sum;
}