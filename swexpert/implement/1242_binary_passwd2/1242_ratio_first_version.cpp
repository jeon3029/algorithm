#include<bits/stdc++.h>
using namespace std;
typedef pair<bool, int> pi;
bool Map[2000][2000];
vector<vector<int>> rat;//ratio
vector<vector<pi>> count_num;
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
    count_num.clear();
    for(int i=0;i<N;i++){
        vector<pi> temp;
        temp.clear();
        bool t = Map[i][0];
        int cnt = 0;
        for(int j=0;j<M*4;j++){
            if(Map[i][j]==t){
                cnt++;
            }
            else{
                temp.push_back({t,cnt});
                cnt = 1;
                t= Map[i][j];
            }
        }
        temp.push_back({t, cnt});
        count_num.push_back(temp);
    }
}
int check(int x,int y,int mul){
    if(count_num[x].size()<y+3){
        return -1;
    }
    if (count_num[x][y].first == count_num[x][y + 1].first || count_num[x][y+1].first == count_num[x][y + 2].first){
        return -1;
    }
    vector<int> c;
    c.push_back(0);
    c.push_back(count_num[x][y].second/mul);
    c.push_back(count_num[x][y+1].second/mul);
    c.push_back(count_num[x][y+2].second/mul);
    for(int i=1;i<4;i++){
        if(c[i]==0)return -1;
    }
    for(int i=0;i<10;i++){
        int f=0;
        for(int j=1;j<4;j++){
            if(rat[i][j] !=c[j]){
                f=1;break;
            }
        }
        if(f==0){
            if(count_num[x][y-1].first==0){
                int temp = 0;
                if(i>=3 && i<=8)temp=1;
                else if(i==0||i==9)temp=3;
                else temp=2;
                if(count_num[x][y-1].second>=temp)
                    return i;
            }
            return -1;
        }
    }
    return -1;
}
int check2(int x,int y,int mul){
    if(count_num[x].size()<y+4){
        return -1;
    }
    if (count_num[x][y].first == count_num[x][y + 1].first || count_num[x][y+1].first == count_num[x][y + 2].first||count_num[x][y+2].first==count_num[x][y+3].first){
        return -1;
    }
    vector<int> c;
    c.push_back(count_num[x][y].second/mul);
    c.push_back(count_num[x][y+1].second/mul);
    c.push_back(count_num[x][y+2].second/mul);
    c.push_back(count_num[x][y+3].second/mul);
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
            if(count_num[i].size()<32)continue;
            for(int j=1;j<=count_num[i].size()-32;j++){
                for(int multi = 1;multi<5;multi++){
                    if((j+32*multi)>count_num[i].size()){
                        break;
                    }
                    int val;
                    if(count_num[i][j].first==1){
                        val = check(i,j,multi);
                    }
                    else continue;
                    if(val==-1)continue;
                    vector<int> pass(1,val);
                    j--;
                    for(int k=0;k<7;k++){
                        int temp = check2(i,j+(k+1)*4,multi);
                        if(temp==-1)break;
                        else pass.emplace_back(temp);
                    }
                    j++;
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
                            f=1;
                            break;
                        }
                    }
                }
                if(f==1)break;
            }if(f==1)break;
        }
        cout<<"#"<<tc<<" "<<answer<<endl;
    }
}