#include<iostream>
#include<cstring>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int case_no;
        cin>>case_no;
        int data[101];
        memset(data,0,sizeof(data));
        for(int i=0;i<1000;i++){
            int temp;
            cin>>temp;
            data[temp]++;
        }
        int max = -1;
        int answer = -1;
        for(int i=0;i<=100;i++){
            if(max<=data[i]){max = data[i];answer = i;}
        }
        cout<<"#"<<case_no<<" "<<answer<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}