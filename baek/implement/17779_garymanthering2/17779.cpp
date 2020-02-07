#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int N;
vector<vector<int> > map;
vector<vector<int> > region;
void input(){
    //initiate
    for(int i=0;i<N;i++){
        vector<int> temp(N,0);
        map.push_back(temp);
        region.push_back(temp);
    }
    //input
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
        }
    }
}
int divide(int x, int y, int d1, int d2){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            region[i][j] = 0;
        }
    }
    //region 1
    int cnt = 0;
    for(int i=0;i<x+d1;i++){
        if(i<x){
            for(int j=0;j<=y;j++){
                region[i][j] = 1;
            }
        }
        else{
            for(int j=0;j<=y-cnt-1;j++){
                region[i][j] = 1;
            }
            cnt++;
        }
        
    }
    //region 2
    cnt = 0;
    for(int i=0;i<=x+d2;i++){
        if(i<x){
            for(int j=y+1;j<N;j++){
                region[i][j] =2;
            }    
        }
        else{
            for(int j=y+1+cnt;j<N;j++){
                region[i][j] =2;
            }
            cnt++;
        }
    }
    //region 3
    cnt = 0;
    for(int i=x+d1;i<N;i++){
        for(int j=0;j<y-d1+cnt;j++){
            region[i][j] = 3;
        }
        if(i<x+d1+d2)cnt++;
    }
    //region 4
    cnt = 0;
    for(int i=x+d2+1;i<N;i++){
        for (int j=y+d2-cnt;j<N;j++){
            region[i][j] = 4;
        }
        if(i<=x+d1+d2)cnt++;
    }
    //region 5
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(region[i][j]==0)region[i][j] = 5;
        }
    }
    vector<int> sum(5,0);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            sum[region[i][j]-1]+=map[i][j];
        }
    }
    sort(sum.begin(),sum.end(),greater<int>());
    return sum[0]-sum[4];
}
int main(int argc, char **argv)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    input();
    int answer = 987654321;
    for(int i=0;i<N-2;i++){
        for(int j=0;j<N-2;j++){
            int d1_max = j; //d1 range
            int d2_max = N-1-j; //d2 range
            for(int d1 = 1;d1<=d1_max;d1++){
                for(int d2 = 1;d2<=d2_max;d2++){
                    if(i+d1+d2>=N)continue;
                    int temp = divide(i,j,d1,d2);
                    if(answer>temp)answer = temp;
                }
            }
        }
    }
    cout << answer << endl;
    return 0;
}