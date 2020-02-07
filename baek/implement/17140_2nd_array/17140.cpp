#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> >array;
int r,c,k;
int sizeRow =3,sizeCol = 3;
void input(){
    cin>>r>>c>>k;
    for(int i=0;i<100;i++){
        vector<int> temp(100,0);
        array.push_back(temp);
    }
    for(int i=0;i<sizeRow;i++){
        for(int j=0;j<sizeCol;j++){
            cin>>array[i][j];
        }
    }
}
bool my_cmp(pair<int,int> a,pair<int,int>b){//first = count, secont = number
    if(a.first==b.first)return a.second<b.second;
    else return a.first<b.first;
}
void calcC(){
    int sizeMax = 0;
    for(int i=0;i<sizeCol;i++){
        vector<int> count(100, 0);
        for(int j=0;j<sizeRow;j++){
            if(array[j][i]==0)continue;
            else count[array[j][i]-1]++;
        }
        vector<pair<int,int> >sorted;
        for(int j=0;j<100;j++){
            if(count[j]!=0)sorted.push_back(make_pair(count[j],j+1));
        }
        sort(sorted.begin(),sorted.end(),my_cmp);
        for(int j=0;j<sizeRow;j++){
            array[j][i] = 0;
        }
        for(int j=0;j<sorted.size();j++){
            array[j*2][i] = sorted[j].second;
            array[j*2+1][i] = sorted[j].first;
        }
        if(sizeMax<sorted.size()*2)sizeMax = sorted.size()*2;
    }
    sizeRow = sizeMax;
}

void calcR(){
    int sizeMax = 0;
    for(int i=0;i<sizeRow;i++){
        vector<int> count(100,0);
        //count all members
        for(int j=0;j<sizeCol;j++){
            if(array[i][j]==0)continue;
            else count[array[i][j]-1]++;
        }
        //sort count 
        vector<pair<int,int> > sorted;
        for(int j=0;j<100;j++){
            if(count[j]!=0)
                sorted.push_back(make_pair(count[j],j+1));
        }
        sort(sorted.begin(),sorted.end(),my_cmp);
        for(int j=0;j<sizeCol;j++){
            array[i][j] = 0;
        }
        for(int j=0;j<sorted.size();j++){
            array[i][j*2]=sorted[j].second;
            array[i][j*2+1]=sorted[j].first;
        }
        if(sizeMax<sorted.size()*2)sizeMax = sorted.size()*2;
    }
    sizeCol = sizeMax;
}
int main(int argc, char **argv){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    int turn;
    for(turn = 0;turn<=100;turn++){
        if(array[r-1][c-1]==k)break;
        if(sizeRow<sizeCol){// 행 < 열
            calcC();
        }
        else{//행 >= 열
            calcR();
        }
    }
    if(turn==101)cout<<"-1"<<endl;
    else cout << turn << endl;
    return 0;
}