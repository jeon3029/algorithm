#include<bits/stdc++.h>
using namespace std;
int N;
int Map[20][20];
void mergeLR(int d){
    for(int i=0;i<N;i++){
        int flag = 0;
        int current;
        if(d==1){
            for(int j=0;j<N;j++){
                if(flag==0 && Map[i][j]){
                    current = Map[i][j];
                    flag=1;
                }
                else if(flag==1 && current == Map[i][j]){
                    Map[i][j-1]=0;
                    Map[i][j] = current*2;
                    flag=0;
                }
                else if(flag==1 && !Map[i][j]){
                    Map[i][j] = current;
                    Map[i][j-1]=0;
                }
                else if(flag==1 && current != Map[i][j]){
                    current = Map[i][j];
                }
            }
        }
        else{
            for(int j=N-1;j>=0;j--){
                if(flag==0 && Map[i][j]){
                    current = Map[i][j];
                    flag=1;
                }
                else if(flag==1 && current == Map[i][j]){
                    Map[i][j+1]=0;
                    Map[i][j] = current*2;
                    flag=0;
                }
                else if(flag==1 && !Map[i][j]){
                    Map[i][j] = current;
                    Map[i][j+1]=0;
                }
                else if(flag==1 && current != Map[i][j]){
                    current = Map[i][j];
                }
            }
        }
    }
}
void mergeUD(int d){
    for(int j=0;j<N;j++){
        int flag = 0;
        int current;
        if(d==3){
            for(int i=0;i<N;i++){
                if(flag==0 && Map[i][j]){
                    current = Map[i][j];
                    flag=1;
                }
                else if(flag==1 && current == Map[i][j]){
                    Map[i-1][j]=0;
                    Map[i][j] = current*2;
                    flag=0;
                }
                else if(flag==1 && !Map[i][j]){
                    Map[i][j] = current;
                    Map[i-1][j]=0;
                }
                else if(flag==1 && current != Map[i][j]){
                    current = Map[i][j];
                }
                
            }
        }
        else{
            for(int i=N-1;i>=0;i--){
                if(flag==0 && Map[i][j]){
                    current = Map[i][j];
                    flag=1;
                }
                else if(flag==1 && current == Map[i][j]){
                    Map[i+1][j]=0;
                    Map[i][j] = current*2;
                    flag=0;
                }
                else if(flag==1 && !Map[i][j]){
                    Map[i][j] = current;
                    Map[i+1][j]=0;
                }
                else if(flag==1 && current != Map[i][j]){
                    current = Map[i][j];
                }
                
            }
        }
    }
}
void move_2048(string s){
    int d = 0;//right,left,down,up
    if(s == "up")d=3;
    else if(s=="down")d=2;
    else if(s=="right")d=0;
    else if(s=="left")d=1;

    if(d==0){//right left
        mergeLR(d);
        vector<vector<int> >numbers;
        for(int i=0;i<N;i++){
            vector<int> temp;
            for(int j=0;j<N;j++){
                if(Map[i][j])temp.push_back(Map[i][j]);
            }
            numbers.push_back(temp);
        }
        memset(Map,0,sizeof(Map));
        for(int i=0;i<N;i++){
            int t=0;
            for(int j=N-numbers[i].size();j<N;j++){
                Map[i][j] = numbers[i][t++];
            }
        }
    }
    else if(d==1){
        mergeLR(d);
        vector<vector<int> >numbers;
        for(int i=0;i<N;i++){
            vector<int> temp;
            for(int j=0;j<N;j++){
                if(Map[i][j])temp.push_back(Map[i][j]);
            }
            numbers.push_back(temp);
        }
        memset(Map,0,sizeof(Map));
        for(int i=0;i<N;i++){
            for(int j=0;j<numbers[i].size();j++){
                Map[i][j] = numbers[i][j];
            }
        }
    }
    else if(d==2){
        mergeUD(d);
        vector<vector<int> >numbers;
        for(int i=0;i<N;i++){
            vector<int> temp;
            for(int j=0;j<N;j++){
                if(Map[j][i])temp.push_back(Map[j][i]);
            }
            numbers.push_back(temp);
        }
        memset(Map,0,sizeof(Map));
        for(int i=0;i<N;i++){
            int t=0;
            for(int j=N-numbers[i].size();j<N;j++){
                Map[j][i] = numbers[i][t++];
            }
        }
    }
    else if(d==3){
        mergeUD(d);
        vector<vector<int> >numbers;
        for(int i=0;i<N;i++){
            vector<int> temp;
            for(int j=0;j<N;j++){
                if(Map[j][i])temp.push_back(Map[j][i]);
            }
            numbers.push_back(temp);
        }
        memset(Map,0,sizeof(Map));
        for(int i=0;i<N;i++){
            for(int j=0;j<numbers[i].size();j++){
                Map[j][i] = numbers[i][j];
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int t=1;t<=T;t++){
        cin>>N;
        string s;cin>>s;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>Map[i][j];
            }
        }
        move_2048(s);
        cout<<"#"<<t<<"\n";
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<Map[i][j]<<" ";
            }cout<<"\n";
        }
    }
}