#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	//freopen("input", "r", stdin);
	T=10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int t;cin>>t;
        vector<vector<int>> matrix;
        int cur_x=0,cur_y=0;
        for(int i=0;i<100;i++){
            vector<int> row;
            row.push_back(0);
            for(int j=0;j<100;j++){
                int temp; cin>>temp;
                row.push_back(temp);
                if(temp==2){
                    cur_x=j+1;
                    cur_y=i;
                }
            }
            row.push_back(0); //양끝에 범위초과를 위한 0 추가
            matrix.push_back(row);
        }
        int dir[3][2]={{0,1},{0,-1},{-1,0}};//동, 서, 북
        int cur_dir = 2; // 0=동, 1=서, 2=북
        //cout<< "x : "<<cur_x<<" y : "<<cur_y<<endl;
        while(cur_y>0){
            int next_y = cur_y +dir[cur_dir][0];
            int next_x = cur_x +dir[cur_dir][1];
            if(cur_dir==0 || cur_dir==1){ //동서로 가는 길...
                if(matrix[next_y][next_x]==0){//change direction
                    cur_dir=2;
                    cur_y--;
                    continue;
                }
                cur_x = next_x;
                cur_y = next_y;
            }
            else{//북으로 가는 길..
                if(matrix[cur_y][cur_x-1]==0 &&matrix[cur_y][cur_x+1]==0){//계속 북으로 가는 경우
                    cur_x = next_x;
                    cur_y = next_y;        
                }
                else{//꺽는 경로가 존재
                    if(matrix[cur_y][cur_x-1]==1){//서쪽으로
                        cur_dir = 1;
                        cur_x--;
                    }
                    else{//동쪽으로
                        cur_dir = 0;
                        cur_x++;
                    }
                }
            }
            //cout<< "x : "<<cur_x<<" y : "<<cur_y<<endl;
        }
        cout<<"#"<<t<<" "<<cur_x-1<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}