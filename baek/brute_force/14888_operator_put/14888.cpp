#include<bits/stdc++.h>
using namespace std;
int N;
int Numbers[100];
int Minus,Plus,Mul,Div;
void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>Numbers[i];
    }
    cin>>Plus>>Minus>>Mul>>Div;
}
int calc(vector<int> oper){
    int answer=Numbers[0];
    for(int i=1;i<N;i++){
        if(oper[i-1]==1){//plus
            answer = answer+Numbers[i];
        }
        else if(oper[i-1]==2){
            answer = answer-Numbers[i];
        }
        else if(oper[i-1]==3){
            answer = answer*Numbers[i];
        }
        else if(oper[i-1]==4){
            answer = answer/Numbers[i];
        }
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    vector<int> op;
    vector<int> p(Plus,1);
    vector<int> m(Minus,2);
    vector<int> mu(Mul,3);
    vector<int> d(Div,4);
    op.insert(op.end(),p.begin(),p.end());
    op.insert(op.end(),m.begin(),m.end());
    op.insert(op.end(),mu.begin(),mu.end());
    op.insert(op.end(),d.begin(),d.end());
    sort(op.begin(),op.end());
    int min =1100000000;
    int max = -1100000000;
    do{
        int output = calc(op);
        if(output<min)min = output;
        if(output>max)max = output;

    }while(next_permutation(op.begin(),op.end()));
    cout<<max<<endl<<min<<endl;
}