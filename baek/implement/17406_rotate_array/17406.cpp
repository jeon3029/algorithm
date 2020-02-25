#include<bits/stdc++.h>
using namespace std;
int N,M,K;
int Data[50][50];
int Rot[6][3];
void input(){
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>Data[i][j];
        }
    }
    for(int i=0;i<K;i++){
        cin>>Rot[i][0]>>Rot[i][1]>>Rot[i][2];
    }
}
void rotate(int pos,vector<vector<int>> &mat){
    int x=Rot[pos][0]-1;
    int y=Rot[pos][1]-1;
    vector<vector<int>> temp=mat;
    for(int outer=1;outer<=Rot[pos][2];outer++){
        //위
        for(int j=y-outer+1;j<=y+outer;j++){
            temp[x-outer][j]=mat[x-outer][j-1];
        }
        //오른
        for(int i=x-outer+1;i<=x+outer;i++){
            temp[i][y+outer]=mat[i-1][y+outer];
        }
        //아래
        for(int j=y+outer-1;j>=y-outer;j--){
            temp[x+outer][j]=mat[x+outer][j+1];
        }
        //왼
        for(int i=x+outer-1;i>=x-outer;i--){
            temp[i][y-outer]=mat[i+1][y-outer];
        }
    }
    mat=temp;
}
int calc(vector<int> order){
    vector<vector<int>> temp(N,vector<int>(M,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            temp[i][j]=Data[i][j];
        }
    }
    for(int i=0;i<K;i++){
        rotate(order[i],temp);
    }
    int answer=987654321;
    for(int i=0;i<N;i++){
        int cur=0;
        for(int j=0;j<M;j++){
            cur+=temp[i][j];
        }
        answer=min(cur,answer);
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    vector<int> combi;
    int answer = 987654321;
    for(int i=0;i<K;i++)combi.push_back(i);
    do{
        answer = min(answer,calc(combi));
    }while(next_permutation(combi.begin(),combi.end()));
    cout<<answer<<"\n";
}