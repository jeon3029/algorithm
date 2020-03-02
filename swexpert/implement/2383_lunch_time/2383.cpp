#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int N;
int D[10][10];
class People{
public:
    int x;
    int y;
    bool isLadder;
    bool isOut;
    int dist;
    int riding_time;
    int lad=0;
    People(int a,int b){
        x=a;y=b;
        isLadder=false;
        isOut=false;
        dist=0;
        riding_time=0;
    }
};
class Ladder{
public:
    int count_P;
    int x;int y;
    int length;
    Ladder(int a,int b,int l){
        length=l;
        count_P=0;
        x=a,y=b;
    }
};
vector<People> P;
vector<Ladder> L;
void input(){
    cin>>N; 
    P.clear();
    L.clear();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>D[i][j];
            if(D[i][j]==1){
                P.push_back(People(i,j));
            }
            else if(D[i][j]>1){
                L.push_back(Ladder(i,j,D[i][j]));
            }
        }
    }

}
int calc(int order){
    vector<People> curP=P;
    vector<Ladder> curL=L;
    //init dist
    for(int i=0;i<curP.size();i++){
        if(order&(0x1<<i)){
            curP[i].lad=0;
            curP[i].dist = abs(curP[i].x-curL[0].x)+abs(curP[i].y-curL[0].y);
        }
        else{
            curP[i].lad=1;
            curP[i].dist = abs(curP[i].x-curL[1].x)+abs(curP[i].y-curL[1].y);
        }
    }
    int time = 0;
    while(1){
        int f=0;//check all out
        int out_cnt_1=0;
        int out_cnt_0=0;
        for(int i=0;i<curP.size();i++){    
            if(curP[i].isOut){
                continue;
            }
            //이동중인경우
            if(!curP[i].isLadder){
                f=1;
                
                if(time>=curP[i].dist) {
                    curP[i].isLadder=1;
                }
            }
            else if(!curP[i].isOut){
                f=1;
                if(curP[i].riding_time==0){//아직 사다리 안타고있는 경우
                    if(curL[curP[i].lad].count_P==3){
                        //wait for ride;
                    }
                    else{
                        curL[curP[i].lad].count_P++;
                        curP[i].riding_time++;
                    }
                }
                else{//사다리 타고 있는 경우
                    if(curP[i].riding_time>=curL[curP[i].lad].length){
                        curP[i].isOut=1;
                        if(curP[i].lad==0){
                            out_cnt_0++;
                        }
                        else{
                            out_cnt_1++;
                        }
                    }
                    else{//사다리 타기
                        curP[i].riding_time++;
                        if(curP[i].riding_time>=curL[curP[i].lad].length){
                            curP[i].isOut=1;
                            // cout<<i<<" : outted\n";
                            if(curP[i].lad==0){
                                out_cnt_0++;
                            }
                            else{
                                out_cnt_1++;
                            }
                        }
                    }
                }
            }
        }
        curL[0].count_P-=out_cnt_0;
        curL[1].count_P-=out_cnt_1;
        if(f==0)break;
        time++;
    }
    return time;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        int len = P.size();
        int answer = INF;
        for(int i=0;i<(0x1<<len);i++){
            answer = min(answer,calc(i));
        }
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
}
