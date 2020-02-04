#include <iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
void in_order(vector<char> tree,string &answer,int current){
    //left child
    if((current*2+1)<tree.size()){
        in_order(tree,answer,current*2+1);
    }
    answer.append(1,tree[current]);
    if((current*2+2)<tree.size()){
        in_order(tree,answer,current*2+2);
    }
}
int main(int argc, char **argv)
{
    int test_case;
    int T;
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    T = 10;
    for (test_case = 1; test_case <= T; ++test_case){
        string answer;
        int N;cin>>N;
        vector<char> tree(N,'0');
        string input;
        for(int i=0;i<N;i++){
            getline(cin,input);
            istringstream ss(input);
            string str;
            getline(ss,str,' ');
            int index = atoi(str.c_str());
            getline(ss, str, ' ');
            char character = str[0];
            tree[index-1] = character;
        }
        in_order(tree,answer,0);
        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;
}