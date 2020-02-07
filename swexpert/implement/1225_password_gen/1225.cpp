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
	for(test_case = 1; test_case <= T; ++test_case){
        int t;cin>>t;
        vector<int> data(8,0);
        for(int i=0;i<8;i++){
            cin>>data[i];
        }   
        int current_minus = 0;
        int pos = 0;
        while(1){
            if(data[pos%8]-((current_minus%5)+1)<=0){
                data[pos%8] = 0;
                pos++;
                break;
            }
            else {
                data[pos%8]-=(current_minus%5)+1;
                pos++;current_minus++;
            }
        }
        cout<<"#"<<t<<" ";
        for(int i=0;i<8;i++){
            cout<<data[pos%8]<<" ";
            pos++;
        }cout<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}