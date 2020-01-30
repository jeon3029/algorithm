#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	T=10;
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        cin>>N;
        vector<int> building;
        for(int i=0;i<N;i++){
            int temp;cin>>temp;
            building.push_back(temp);
        }
        int answer = 0;
        for(int i=2;i<N-2;i++){
            int right_max = max(building[i+1],building[i+2]);
            int left_max = max(building[i-1],building[i-2]);
            if(right_max>=building[i] || left_max>=building[i])continue;
            else{
                answer += building[i]-max(left_max,right_max);
            }
        }
        cout<<"#"<<test_case<<" "<<answer<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}