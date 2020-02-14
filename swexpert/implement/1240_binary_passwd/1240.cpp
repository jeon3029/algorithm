#include<bits/stdc++.h>
using namespace std;
int Map[50][100];
vector<vector<int>> pat;
int N,M;
void init(){
    pat.emplace_back((0,0,0,1,1,0,1));//0
    pat.emplace_back((0,0,1,1,0,0,1));//1
    pat.emplace_back((0,0,1,0,0,1,1));//2
    pat.emplace_back((0,1,1,1,1,0,1));//3
    pat.emplace_back((0,1,0,0,0,1,1));//4
    pat.emplace_back((0,1,1,0,0,0,1));//5
    pat.emplace_back((0,1,0,1,1,1,1));//6
    pat.emplace_back((0,1,1,1,0,1,1));//7
    pat.emplace_back((0,1,1,0,1,1,1));//8
    pat.emplace_back((0,0,0,1,0,1,1));//9
}
void input(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        for(int j=0;j<M;j++){
            Map[i][j]=s[j]-'0';
        }
    }
}
int calc(const int x,const int y){
    if(Map[x][y]==1)return -1;
    vector<int> match(10,1);
    int cnt_match=10;
    for(int i=y,t=0;i<y+7;i++,t++){
        for(int j=0;j<10;j++){
            assert(i<M);
            if(cnt_match==0)break;
            if(match[j]){
                if(Map[x][i]==pat[j][t]){
                    continue;
                }
                else{
                    match[j]=0;
                    cnt_match--;
                }
            }
        }
    }
    int answer= -1;
    if(cnt_match==0)return answer;
    for(int i=0;i<match.size();i++){
        if(match[i])
            answer = i;
    }   
    return answer;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        int answer = 0;
        int f=0;
        for(int i=0;i<N-5;i++){
            for(int j=0;j<M-(7*8+1);j++){
                int val = calc(i,j);
                if(val!=-1){
                    vector<int> pass(1,val);
                    for(int k=0;k<7;k++){
                        int temp = calc(i,(j+k*7)+7);
                        if(temp == -1)break;
                        else{
                            pass.push_back(temp);
                        }
                    }
                    if(pass.size()==8){
                        int sum = 0;
                        int sum_1=0;
                        int sum_2=0;
                        for(int k=0;k<pass.size();k++){
                            sum+=pass[k];
                            if(k==7)continue;
                            if(k%2==0)sum_1+=pass[k];
                            else sum_2+=pass[k];
                        }
                        if((sum_1*3+sum_2+pass[7])%10==0){
                            answer = sum;
                            f=1;break;
                        }
                    }
                }
            }
            if(f==1)break;
        }
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
    return 0;
}