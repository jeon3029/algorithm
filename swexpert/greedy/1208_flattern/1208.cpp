#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void swap(int &a,int &b){
    int temp = a;
    a=b;
    b=temp;
}
void move_box(vector<int> &box){
    box[0]++;
    box[box.size()-1]--;
    for(int i=0;i<box.size()-1;i++){
        if(box[i] > box[i+1]){
            swap(box[i],box[i+1]);
        }
        else break;
    }
    for(int i=box.size()-1;i>=1;i--){
        if(box[i] < box[i-1]){
            swap(box[i],box[i-1]);
        }
        else break;
    }
    return;
}
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
        int possible;
        cin>>possible;
        vector<int> box;
        for(int i=0;i<100;i++){
            int temp;cin>>temp;
            box.push_back(temp);
        }
        sort(box.begin(),box.end());
        for(int i=0;i<possible;i++){
            move_box(box);
        }
        cout<<"#"<<test_case<<" "<<box[box.size()-1]-box[0]<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}