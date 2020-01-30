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
        int N;cin>>N;
        vector<vector<int>> matrix;
        int answer = 0;
        for(int i=0;i<N;i++){
            vector<int> row;
            for(int j=0;j<N;j++){
                int temp; cin>>temp;
                row.push_back(temp);
            }
            matrix.push_back(row);
        }//1 = n, 2= s 0 = empty
        for(int i=0;i<N;i++){
            //check by col
            //첫번째 N을 만나면 s를 모두 만날때까지 한개의 교착상태이다 다시 N부터 시작
            bool meetN = false;
            bool meetS = false;
            for(int j=0;j<N;j++){
                if(!meetN){
                    if(matrix[j][i] == 1){
                        meetN = true;
                    }
                }
                else{ // meetN = true   
                    if(!meetS){
                        if(matrix[j][i]==2){
                            meetS=true;
                            answer++;
                        }
                    }
                    else{//이미 s를 만난경우 새로운 n을 만날때까지
                        if(matrix[j][i]==1){
                            meetN = true;
                            meetS = false;
                        }
                    }
                }
            }
        }
        cout<<"#"<<test_case<<" "<<answer<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}