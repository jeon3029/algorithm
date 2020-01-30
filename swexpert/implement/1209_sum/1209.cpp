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
	//freopen("input.txt", "r", stdin);
	T=10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int t;cin>>t;
        vector<vector<int>> matrix;
        for(int i=0;i<100;i++){
            vector<int> row;
            for(int j=0;j<100;j++){
                int temp;cin>>temp;
                row.push_back(temp);
            }
            matrix.push_back(row);
        }
        //행,열, 대각선 계산
        vector<int> sum_row(100,0);
        vector<int> sum_col(100,0);
        vector<int> sum_diagonal(2,0);
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                sum_row[i]+=matrix[i][j];
                sum_col[j]+=matrix[i][j];
            }
            sum_diagonal[0]+=matrix[i][i];
            sum_diagonal[1]+=matrix[99-i][i];
        }
        int max = 0;
        for (int i=0;i<100;i++){
            if(i<3){
                if(max<sum_diagonal[i])max = sum_diagonal[i];
            }
            if(max<sum_row[i])max = sum_row[i];
            if(max<sum_col[i])max = sum_col[i];
        }
        cout<<"#"<<t<<" "<<max<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}