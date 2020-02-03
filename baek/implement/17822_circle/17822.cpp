#include <iostream>
#include <vector>
#include <queue>
#define SIZE 10
using namespace std;
int main(int argc, char **argv){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M,T;
    cin>>N>>M>>T;
    //cout<<N<<M<<T<<endl;
    vector<vector<int> > circle;
    vector<int> rotate(N,0);
    for(int i=0;i<N;i++){
        vector<int> temp;
        for(int j=0;j<M;j++){
            int t;cin >> t;
            temp.push_back(t);
        }
        circle.push_back(temp);
    }
    for(int t=0;t<T;t++){
        int which,dir,rot_val;
        cin>>which>>dir>>rot_val;
        //rotate
        for(int n=which;n<=N;n+=which){
            if(dir==1){//clock wise
                rotate[n-1] += rot_val;
            }
            else{//counter clock wise
                rotate[n-1] += 4-rot_val;
            }
            rotate[n-1]%=4;
        }
        // for(int i=0;i<N;i++){
        //     cout<<rotate[i]<<" ";
        // }cout<<endl<<endl;

        //find same value adjacent circle
        queue<pair<int,int>> deleted_q; //원판, 위치
        //case 1: same circle
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(circle[i][j]==0)continue;
                if(circle[i][j] == circle[i][(j+1)%M]){
                    deleted_q.push(make_pair(i,j));
                    deleted_q.push(make_pair(i, (j+1)%M));
                }
            }
        }
        //case 2: other circle
        for(int i=0;i<N-1;i++){
            for(int j=0;j<M;j++){
                if(circle[i][(rotate[i]+j)%M]==0)continue;
                if(circle[i][(rotate[i]+j)%M] == circle[i+1][(rotate[i+1]+j)%M]){
                    deleted_q.push(make_pair(i, (rotate[i] + j) % M));
                    deleted_q.push(make_pair(i+1, (rotate[i+1]+j)%M));
                }
            }
        }
        //case 3 : if no adjacent circle
        if(deleted_q.empty()){
            int sum = 0;int cnt=0;
            for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                    if(circle[i][j]!=0){
                        sum+=circle[i][j];
                        cnt++;
                    }
                }
            }
            float avg = float(sum)/cnt;
            for (int i = 0; i < N; i++){
                for (int j = 0; j < M; j++){
                    if(circle[i][j]!=0){
                        if(circle[i][j]>avg){
                            circle[i][j]--;
                        }
                        else if(circle[i][j]<avg){
                            circle[i][j]++;
                        }
                    }
                }
            }
        }
        while(!deleted_q.empty()){
            int a = deleted_q.front().first;
            int b = deleted_q.front().second;
            circle[a][b] = 0;
            deleted_q.pop();
        }
    }
    int answer = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            //cout<<circle[i][j]<<" ";
            answer+=circle[i][j];
        }//cout<<endl;
    }
    cout << answer << endl;
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}