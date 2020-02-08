#include<bits/stdc++.h>
using namespace std;
int N;
int M;
int Map[50][50];
vector<pair<int,int> > chicken;
vector<pair<int,int> > house;
void input(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>Map[i][j];
            if(Map[i][j]==2){
                chicken.push_back(make_pair(i,j));
            }
            else if(Map[i][j]==1){
                house.push_back(make_pair(i,j));
            }
        }
    }
}
int calc(vector<int> combi){
    int answer = 0;
    for(int i=0;i<house.size();i++){
        int min_dis = 987654321;
        for(int j=0;j<chicken.size();j++){
            if(combi[j]==1){//valid chicken house
                int dis = abs(chicken[j].first-house[i].first) + abs(chicken[j].second-house[i].second);
                if(dis<min_dis)min_dis = dis;
            }
        }
        answer +=min_dis;
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    vector<int> combination(M,1);
    vector<int> deleted_house(chicken.size()-M,0);
    combination.insert(combination.end(),deleted_house.begin(),deleted_house.end());
    sort(combination.begin(),combination.end());
    int min_distance = 987654321;
    do{
        int dis = calc(combination);
        if(min_distance>dis)min_distance = dis;
    }while(next_permutation(combination.begin(),combination.end()));
    cout<<min_distance<<endl;
}