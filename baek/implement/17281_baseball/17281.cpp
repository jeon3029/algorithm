#include<bits/stdc++.h>
using namespace std;
int N;
int Data[51][9];
void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<9;j++){
            cin>>Data[i][j];
        }
    }
}
int calc(vector<int> o){
    vector<int> order(9,0);
    int j=0;
    for(int i=0;i<9;i++){
        if(i==3)continue;
        else order[i]=o[j++];
    }
    int out=0;
    int answer=0;
    int pos=0;
    for(int in=0;in<N;in++){
        out=0;
        vector<int> road(4,0);//홈,1루,2루,3루    
        while(out!=3){
            int people = order[pos%9];
            pos++;
            int current = Data[in][people];
            int temp[8]={0,};
            if(current==0){
                out++;
            }
            else {//안타~홈런
                road[0]=1;
                for(int i=current,j=0;i<=current+3;i++,j++){
                    temp[i]=road[j];
                }
                for(int i=4;i<=7;i++){
                    answer+=temp[i];
                }
                for(int i=0;i<=3;i++){
                    road[i]=temp[i];
                }
            }
        }
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    vector<int> combi;
    for(int i=1;i<=8;i++){
        combi.push_back(i);
    }
    int answer=0;
    sort(combi.begin(),combi.end());
    do{
        int cur = calc(combi);
        answer=max(answer,cur);
    }while(next_permutation(combi.begin(),combi.end()));
    cout<<answer<<"\n";
}