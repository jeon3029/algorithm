#include<bits/stdc++.h>
using namespace std;
bool Map[2000][2000];
vector<vector<bool>> pat;
int N,M;
bool Hex[16][4] = {
{0,0,0,0},
{0,0,0,1},
{0,0,1,0},
{0,0,1,1},
{0,1,0,0},
{0,1,0,1},
{0,1,1,0},
{0,1,1,1},
{1,0,0,0},
{1,0,0,1},
{1,0,1,0},
{1,0,1,1},
{1,1,0,0},
{1,1,0,1},
{1,1,1,0},
{1,1,1,1}
};
void init(){
    pat.emplace_back(vector<bool>{0,0,0,1,1,0,1});//0
    pat.emplace_back(vector<bool>{0,0,1,1,0,0,1});//1
    pat.emplace_back(vector<bool>{0,0,1,0,0,1,1});//2
    pat.emplace_back(vector<bool>{0,1,1,1,1,0,1});//3
    pat.emplace_back(vector<bool>{0,1,0,0,0,1,1});//4
    pat.emplace_back(vector<bool>{0,1,1,0,0,0,1});//5
    pat.emplace_back(vector<bool>{0,1,0,1,1,1,1});//6
    pat.emplace_back(vector<bool>{0,1,1,1,0,1,1});//7
    pat.emplace_back(vector<bool>{0,1,1,0,1,1,1});//8
    pat.emplace_back(vector<bool>{0,0,0,1,0,1,1});//9
}
void input(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string s;cin>>s;
        int pos;
        for(int j=0;j<M;j++){
            if(s[j]>='0' && s[j]<='9')pos = s[j]-'0';
            else pos = s[j]-'A'+10;
            Map[i][j*4] = Hex[pos][0];
            Map[i][j*4+1] = Hex[pos][1];
            Map[i][j*4+2] = Hex[pos][2];
            Map[i][j*4+3] = Hex[pos][3];
        }
    }
}
int calc(const int x,const int y,const int multi){
    if(Map[x][y]==1)return -1;//패턴은 항상 0으로 시작
    vector<int> match(10,1);
    int cnt_match=10;
    for(int i=0;i<7;i++){
        for(int j=0;j<10;j++){
            if(cnt_match==0)break;
            if(match[j]){
                for(int k=0;k<multi;k++){
                    if(Map[x][y+i*multi +k] == pat[j][i]){
                        continue;
                    }
                    else {
                        cnt_match--;
                        match[j]=0;
                        break;
                    }
                }
            }
        }
    }
    if(cnt_match==0)return -1;
    for(int i=0;i<match.size();i++){
        if(match[i])return i;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    init();
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        int f=0;
        int answer=0;
        for(int i=0;i<N-5;i++){
            for(int j=0;j<M*4-(7*8);j++){
                for(int multi = 1;;multi++){
                    if((j+multi*56) >=(M*4)){
                        break;
                    }
                    int val = calc(i,j,multi);
                    if(val==-1)continue;
                    vector<int> pass(1,val);
                    for(int k=0;k<7;k++){
                        int temp = calc(i,(j+multi*(k+1)*7),multi);
                        if(temp==-1)break;
                        else pass.emplace_back(temp);
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
                            answer += sum;
                            for(int a=i;;a++){
                                int cnt = 0;
                                for(int b=j;b<j+multi*56;b++){
                                    if(Map[a][b]){
                                        Map[a][b]=0;cnt++;
                                    }
                                }
                                if(cnt==0)break;
                            }
                        }              
                    }
                }
            }
        }
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
}