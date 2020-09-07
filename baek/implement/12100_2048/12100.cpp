#include<bits/stdc++.h>
using namespace std;
int N;
int Data[20][20];
int Data_t[20][20];
int answer = 0;
void input(){
    cin>>N;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)cin>>Data[i][j];
}
void move(int dir){
    vector<vector<int>> number(N,vector<int>());
    if(dir==0){//left
        // cout<<"left"<<endl;
        for(int i=0;i<N;i++)for(int j=0;j<N;j++){
            if(Data_t[i][j]!=0){
                number[i].push_back(Data_t[i][j]);
            }
        }
        for(int i=0;i<N;i++){
            if(number[i].size()==0)continue;
            for(int j=0;j<number[i].size()-1;j++){
                if(number[i][j] == number[i][j+1]){
                    number[i][j] = number[i][j]*2;
                    number[i][j+1]=-1;
                    j++;
                }
            }
        }
        for(int i=0;i<N;i++)for(int j=0;j<N;j++)Data_t[i][j] = 0;
        for(int i=0;i<N;i++){
            int pos = 0;
            for(int j=0;j<number[i].size();j++){
                if(number[i][j] == -1){
                    continue;
                }
                else{
                    Data_t[i][pos] = number[i][j];
                    pos++;
                }
            }
        }
    }
    else if(dir==1){//right
        // cout<<"right"<<endl;
        for(int i=0;i<N;i++)for(int j=N-1;j>=0;j--){
            if(Data_t[i][j]!=0){
                number[i].push_back(Data_t[i][j]);
            }
        }
        for(int i=0;i<N;i++){
            if(number[i].size()==0)continue;
            for(int j=0;j<number[i].size()-1;j++){
                if(number[i][j] == number[i][j+1]){
                    number[i][j] = number[i][j]*2;
                    number[i][j+1]=-1;
                    j++;
                }
            }
        }
        for(int i=0;i<N;i++)for(int j=0;j<N;j++)Data_t[i][j] = 0;
        for(int i=0;i<N;i++){
            int pos = N-1;
            for(int j=0;j<number[i].size();j++){
                if(number[i][j] == -1){
                    continue;
                }
                else{
                    Data_t[i][pos] = number[i][j];
                    pos--;
                }
            }
        }

    }
    else if(dir == 2){//down
        // cout<<"down"<<endl;
        for(int i=N-1;i>=0;i--)for(int j=0;j<N;j++){
            if(Data_t[i][j]!=0){
                number[j].push_back(Data_t[i][j]);
            }
        }
        for(int i=0;i<N;i++){
            if(number[i].size()==0)continue;
            for(int j=0;j<number[i].size()-1;j++){
                if(number[i][j] == number[i][j+1]){
                    number[i][j] = number[i][j]*2;
                    number[i][j+1]=-1;
                    j++;
                }
            }
        }
        for(int i=0;i<N;i++)for(int j=0;j<N;j++)Data_t[i][j] = 0;
        for(int i=0;i<N;i++){
            int pos = N-1;
            for(int j=0;j<number[i].size();j++){
                if(number[i][j] == -1){
                    continue;
                }
                else{
                    Data_t[pos][i] = number[i][j];
                    pos--;
                }
            }
        }
    }
    else{//up
        // cout<<"up"<<endl;
        for(int i=0;i<N;i++)for(int j=0;j<N;j++){
            if(Data_t[i][j]!=0){
                number[j].push_back(Data_t[i][j]);
            }
        }
        for(int i=0;i<N;i++){
            if(number[i].size()==0)continue;
            for(int j=0;j<number[i].size()-1;j++){
                if(number[i][j] == number[i][j+1]){
                    number[i][j] = number[i][j]*2;
                    number[i][j+1]=-1;
                    j++;
                }
            }
        }
        for(int i=0;i<N;i++)for(int j=0;j<N;j++)Data_t[i][j] = 0;
        for(int i=0;i<N;i++){
            int pos = 0;
            for(int j=0;j<number[i].size();j++){
                if(number[i][j] == -1){
                    continue;
                }
                else{
                    Data_t[pos][i] = number[i][j];
                    pos++;
                }
            }
        }
    }
}
void check(int pos){
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)Data_t[i][j] = Data[i][j];
    // cout<<"pos : "<<pos<<"\n";
    for(int i=0;i<5;i++){
        int dir = pos % 4;//0 = left, 1=right, 2=down, 3=up
        pos /= 4;
        // cout<<"123"<<endl;
        move(dir);
        // for(int i=0;i<N;i++){
        //     for(int j=0;j<N;j++){
        //         cout<<Data_t[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
    }
    // cout<<"\n";
    for(int i=0;i<N;i++)for(int j=0;j<N;j++){
        if(answer<Data_t[i][j]){
            answer = Data_t[i][j];
            // if(answer==32)exit(0);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    int len = pow(4,5);
    for(int i=0;i<len;i++){
        check(i);
    }
    // check(1023);
    cout<<answer<<"\n";
}