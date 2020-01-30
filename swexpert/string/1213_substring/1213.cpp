#include<iostream>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	T=10;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int t;cin>>t;
        string find;
        string s;
        cin>>find>>s;
        int answer = 0;
        for(int i=0;i<s.length()-find.length()+1;i++){
            int j;
            for(j=0;j<find.length();j++){
                if(s[i+j] != find[j])break;
            }
            if(j==find.length())answer++;
        }
        cout<<"#"<<test_case<<" "<<answer<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}