#include<bits/stdc++.h>
using namespace std;
typedef pair<bool, int> pi;
bool Map[2000][2000];
vector<vector<int>> rat;//ratio
vector<vector<pi>> count_num;
int N,M;
int NN;
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
    rat.emplace_back(vector<int>{3,2,1,1});
    rat.emplace_back(vector<int>{2,2,2,1});
    rat.emplace_back(vector<int>{2,1,2,2});
    rat.emplace_back(vector<int>{1,4,1,1});
    rat.emplace_back(vector<int>{1,1,3,2});
    rat.emplace_back(vector<int>{1,2,3,1});
    rat.emplace_back(vector<int>{1,1,1,4});
    rat.emplace_back(vector<int>{1,3,1,2});
    rat.emplace_back(vector<int>{1,2,1,3});
    rat.emplace_back(vector<int>{3,1,1,2});
}
void input(){
    cin>>N>>M;
    int check=0;
    count_num.clear();
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
        vector<pi> tt(M*4,{0,0});
        count_num.push_back(tt);
    }
    for(int i=N-1;i>=0;i--){
        int t = Map[i][M*4-1];
        int cnt=0;
        for(int j=M*4-1;j>=0;j--){
            if(Map[i][j]==t){
                cnt++;
                count_num[i][j] = {t,cnt};
            }
            else{
                cnt=1;
                t=Map[i][j];
                count_num[i][j]={t,cnt};
            }
        }
    }
}
int check(int x,int y,int mul){
    int first_number = count_num[x][y].first;
    int first_count = count_num[x][y].second;
    y+= first_count;
    if(first_number==1)return -1;
    if(y>M*4)return -1;
    int second_number = count_num[x][y].first;
    int second_count = count_num[x][y].second;
    y+= second_count;
    if(y>M*4)return -1;
    int third_number = count_num[x][y].first;
    int third_count = count_num[x][y].second;
    y+= third_count;
    if(y>M*4)return -1;
    int fourth_number = count_num[x][y].first;
    int fourth_count = count_num[x][y].second;
    if(first_number==-1 || second_number== -1 ||third_number==-1||fourth_number==-1)return -1;
    vector<int> c;
    c.push_back(first_count/mul);
    c.push_back(second_count/mul);
    c.push_back(third_count/mul);
    c.push_back(fourth_count/mul);
    for(int i=0;i<4;i++){
        if(c[i]==0)return -1;
    }
    for(int i=0;i<10;i++){
        int f=0;
        for(int j=0;j<4;j++){
            if(rat[i][j] !=c[j]){
                f=1;break;
            }
        }
        if(f==0){
            return i;
        }
    }
    return -1;
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
            for(int j=0;j<M*4-56;j++){
                if(count_num[i][j].second==-1)continue;
                for(int multi = 1; multi<=4;multi++){
                    if((j+multi*56>(4*M))){
                        break;
                    }
                    //TODO : check for next start point
                    int val=check(i,j,multi);
                    if(val==-1)continue;
                    vector<int> pass(1,val);
                    int temp = j;
                    j+=count_num[i][j].second;
                    j+=count_num[i][j].second;
                    j+=count_num[i][j].second;
                    j+=count_num[i][j].second;
                    for(int k=0;k<7;k++){
                        int temp = check(i,j,multi);
                        if(temp==-1)break;
                        else pass.emplace_back(temp);
                        j+=count_num[i][j].second;
                        j+=count_num[i][j].second;
                        j+=count_num[i][j].second;
                        j+=count_num[i][j].second;
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
                            // cout<<i<<","<<temp<<" : "<<sum<<"\n";
                            for(int a=i;;a++){
                                int count_one=0;
                                for(int b=temp;b<temp+multi*56;b++){
                                    if(count_num[a][b].first == true)count_one++;
                                    count_num[a][b].first = 0;
                                    count_num[a][b].second = -1;
                                }
                                //cout<<"erase : "<<a<<"\n";
                                if(count_one==0)break;
                            }
                            break;
                        }
                    }
                    else{
                        j=temp;
                    }
                }
                if(f==1)break;
            }if(f==1)break;
        }
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
}