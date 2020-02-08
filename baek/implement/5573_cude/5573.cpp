#include<bits/stdc++.h>
using namespace std;
int N;
vector<string> rot;
vector<vector<char> > cube;
void input(){
    cin>>N;
    rot.clear();
    for(int i=0;i<N;i++){
        string t;
        cin>>t;
        rot.push_back(t);
    }
}
void initiate(){
    cube.clear();
    vector<char> U(9,'w');
    vector<char> D(9,'y');
    vector<char> F(9,'r');
    vector<char> B(9,'o');
    vector<char> L(9,'g');
    vector<char> R(9,'b');
    cube.push_back(U);
    cube.push_back(D);
    cube.push_back(F);
    cube.push_back(B);
    cube.push_back(L);
    cube.push_back(R);
}
vector<char> rot_clock(vector<char> matrix){
    vector<char> answer(9,' ');
    answer[0] = matrix[6];
    answer[1] = matrix[3];
    answer[2] = matrix[0];
    answer[3] = matrix[7];
    answer[4] = matrix[4];
    answer[5] = matrix[1];
    answer[6] = matrix[8];
    answer[7] = matrix[5];
    answer[8] = matrix[2];
    return answer;
}
vector<char> rot_counter_clock(vector<char> matrix){
    vector<char> answer(9,' ');
    answer[0] = matrix[2];
    answer[1] = matrix[5];
    answer[2] = matrix[8];
    answer[3] = matrix[1];
    answer[4] = matrix[4];
    answer[5] = matrix[7];
    answer[6] = matrix[0];
    answer[7] = matrix[3];
    answer[8] = matrix[6];
    return answer;
}
void calc(string s){
    //U D F B L R
    switch(s[0]){
        case 'U':
            if(s[1]=='-'){//counter clock wise
                vector<char> newU(9,' ');
                newU = rot_counter_clock(cube[0]);
                vector<char> temp;
                temp.insert(temp.begin(),cube[2].begin(),cube[2].begin()+3);
                cube[2].erase(cube[2].begin(),cube[2].begin()+3);
                cube[2].insert(cube[2].begin(),cube[4].begin(),cube[4].begin()+3);//front to left

                cube[4].erase(cube[4].begin(),cube[4].begin()+3);
                cube[4].insert(cube[4].begin(),cube[3].begin(),cube[3].begin()+3);//left to back

                cube[3].erase(cube[3].begin(),cube[3].begin()+3);
                cube[3].insert(cube[3].begin(),cube[5].begin(),cube[5].begin()+3);//back to right

                cube[5].erase(cube[5].begin(),cube[5].begin()+3);
                cube[5].insert(cube[5].begin(),temp.begin(),temp.begin()+3);//right to temp
                cube[0] = newU;
            }
            else{//clock wise
                vector<char> newU(9,' ');
                newU = rot_clock(cube[0]);
                vector<char> temp;
                temp.insert(temp.begin(),cube[2].begin(),cube[2].begin()+3);//temp = front
                cube[2].erase(cube[2].begin(),cube[2].begin()+3);
                cube[2].insert(cube[2].begin(),cube[5].begin(),cube[5].begin()+3);//front to right

                cube[5].erase(cube[5].begin(),cube[5].begin()+3);
                cube[5].insert(cube[5].begin(),cube[3].begin(),cube[3].begin()+3);//right to back

                cube[3].erase(cube[3].begin(),cube[3].begin()+3);
                cube[3].insert(cube[3].begin(),cube[4].begin(),cube[4].begin()+3);//back to left

                cube[4].erase(cube[4].begin(),cube[4].begin()+3);
                cube[4].insert(cube[4].begin(),temp.begin(),temp.begin()+3);//left to temp
                cube[0] = newU;
            }
            break;
        case 'D':
            if(s[1]=='-'){
                vector<char> newD(9,' ');
                newD = rot_counter_clock(cube[1]);
                vector<char> temp;
                temp.insert(temp.begin(),cube[2].begin()+6,cube[2].begin()+9);//temp = front
                cube[2].erase(cube[2].begin()+6,cube[2].begin()+9);
                cube[2].insert(cube[2].begin()+6,cube[5].begin()+6,cube[5].begin()+9);//front to right

                cube[5].erase(cube[5].begin()+6,cube[5].begin()+9);
                cube[5].insert(cube[5].begin()+6,cube[3].begin()+6,cube[3].begin()+9);//right to back

                cube[3].erase(cube[3].begin()+6,cube[3].begin()+9);
                cube[3].insert(cube[3].begin()+6,cube[4].begin()+6,cube[4].begin()+9);//back to left

                cube[4].erase(cube[4].begin()+6,cube[4].begin()+9);
                cube[4].insert(cube[4].begin()+6,temp.begin(),temp.begin()+3);//left to temp
                cube[1] = newD;
            }
            else{
                vector<char> newD(9,' ');
                newD = rot_clock(cube[1]);
                vector<char> temp;
                temp.insert(temp.begin(),cube[2].begin()+6,cube[2].begin()+9);
                cube[2].erase(cube[2].begin()+6,cube[2].begin()+9);
                cube[2].insert(cube[2].begin()+6,cube[4].begin()+6,cube[4].begin()+9);//front to left

                cube[4].erase(cube[4].begin()+6,cube[4].begin()+9);
                cube[4].insert(cube[4].begin()+6,cube[3].begin()+6,cube[3].begin()+9);//left to back

                cube[3].erase(cube[3].begin()+6,cube[3].begin()+9);
                cube[3].insert(cube[3].begin()+6,cube[5].begin()+6,cube[5].begin()+9);//back to right

                cube[5].erase(cube[5].begin()+6,cube[5].begin()+9);
                cube[5].insert(cube[5].begin()+6,temp.begin(),temp.begin()+3);//right to temp
                cube[1] = newD;
            }
            break;
        case 'F':
            if(s[1]=='-'){
                vector<char> newF(9,' ');
                newF = rot_counter_clock(cube[2]);
                vector<char> temp;
                temp.insert(temp.begin(),cube[0].begin()+6,cube[0].begin()+9);
                cube[0].erase(cube[0].begin()+6,cube[0].begin()+9);
                vector<char> t1;t1.push_back(cube[5][0]);t1.push_back(cube[5][3]);t1.push_back(cube[5][6]);
                cube[0].insert(cube[0].begin()+6,t1.begin(),t1.end());//upper to right

                cube[5][0] = cube[1][2];cube[5][3] = cube[1][1];cube[5][6] = cube[1][0];//right to bottom

                cube[1][0] = cube[4][2];cube[1][1] = cube[4][5];cube[1][2] = cube[4][8];//bottom to left

                cube[4][8] = temp[0];cube[4][5] = temp[1];cube[4][2] = temp[2];//left to upper
                cube[2] = newF;
            }
            else{
                vector<char> newF(9,' ');
                newF = rot_clock(cube[2]);
                vector <char> temp;
                temp.insert(temp.begin(),cube[0].begin()+6,cube[0].begin()+9); 
                
                cube[0][6] = cube[4][8]; cube[0][7]=cube[4][5]; cube[0][8]=cube[4][2];//upper to left

                cube[4][2] = cube[1][0];cube[4][5] = cube[1][1];cube[4][8] = cube[1][2];//left to bottom

                cube[1][0] = cube[5][6];cube[1][1] = cube[5][3];cube[1][2] = cube[5][0];//bottom right

                cube[5][0] = temp[0];cube[5][3] = temp[1];cube[5][6] = temp[2];//right to upper
                cube[2] = newF;
            }
            break;
        case 'B':
            if(s[1]=='-'){
                vector<char> newB(9,' ');
                newB = rot_counter_clock(cube[3]);
                vector<char> temp;
                temp.insert(temp.begin(),cube[0].begin(),cube[0].begin()+3);

                cube[0].erase(cube[0].begin(),cube[0].begin()+3);
                vector<char> t1;t1.push_back(cube[4][6]);t1.push_back(cube[4][3]);t1.push_back(cube[4][0]);
                cube[0].insert(cube[0].begin(),t1.begin(),t1.end());//upper to left

                cube[4][0] = cube[1][6];cube[4][3] = cube[1][7];cube[4][6] = cube[1][8];//left to bottom

                cube[1][6] = cube[5][8];cube[1][7] = cube[5][5];cube[1][8] = cube[5][2];//bottom to right

                cube[5][2] = temp[0];cube[5][5] = temp[1];cube[5][8] = temp[2];//right to upper
                cube[3] = newB;
            }
            else{
                vector<char> newB(9,' ');
                newB = rot_clock(cube[3]);
                vector<char> temp;
                temp.insert(temp.begin(),cube[0].begin(),cube[0].begin()+3);
                cube[0].erase(cube[0].begin(),cube[0].begin()+3);
                vector<char> t1;t1.push_back(cube[5][2]);t1.push_back(cube[5][5]);t1.push_back(cube[5][8]);
                cube[0].insert(cube[0].begin(),t1.begin(),t1.end());//upper to right

                cube[5][2] = cube[1][8];cube[5][5] = cube[1][7];cube[5][8] = cube[1][6];//right to bottom

                cube[1][8] = cube[4][6];cube[1][7] = cube[4][3];cube[1][6] = cube[4][0];//bottom to left

                cube[4][6] = temp[0];cube[4][3] = temp[1];cube[4][0] = temp[2];//left to upper
                cube[3] = newB;
            }
            break;
        case 'L':
            if(s[1]=='-'){
                vector<char> newL(9,' ');
                newL = rot_counter_clock(cube[4]);
                vector<char> temp;
                temp.push_back(cube[0][0]);temp.push_back(cube[0][3]);temp.push_back(cube[0][6]);
                
                cube[0][0] = cube[2][0];cube[0][3] = cube[2][3];cube[0][6] = cube[2][6];//upper to front

                cube[2][0] = cube[1][0];cube[2][3] = cube[1][3];cube[2][6] = cube[1][6];//front to bottom

                cube[1][0] = cube[3][8];cube[1][3] = cube[3][5];cube[1][6] = cube[3][2];//bottom to back

                cube[3][8] = temp[0];cube[3][5] = temp[1];cube[3][2] = temp[2];//back to upper
                cube[4] = newL;
            }
            else{
                vector<char> newL(9,' ');
                newL = rot_clock(cube[4]);
                vector<char> temp;
                temp.push_back(cube[0][0]);temp.push_back(cube[0][3]);temp.push_back(cube[0][6]);
                
                cube[0][0] = cube[3][8];cube[0][3] = cube[3][5];cube[0][6] = cube[3][2];//upper to back

                cube[3][2] = cube[1][6];cube[3][5] = cube[1][3];cube[3][8] = cube[1][0];//back to bottom

                cube[1][6] = cube[2][6];cube[1][3] = cube[2][3];cube[1][0] = cube[2][0];//bottom to front

                cube[2][0] = temp[0];cube[2][3] = temp[1];cube[2][6] = temp[2];//front to upper
                cube[4] = newL;
            }
            break;
        case 'R':
            if(s[1]=='-'){
                vector<char> newR(9,' ');
                newR = rot_counter_clock(cube[5]);
                vector<char> temp;
                temp.push_back(cube[0][2]);temp.push_back(cube[0][5]);temp.push_back(cube[0][8]);
                
                cube[0][2] = cube[3][6];cube[0][5] = cube[3][3];cube[0][8] = cube[3][0];//upper to back

                cube[3][6] = cube[1][2];cube[3][3] = cube[1][5];cube[3][0] = cube[1][8];//back to bottom

                cube[1][2] = cube[2][2];cube[1][5] = cube[2][5];cube[1][8] = cube[2][8];//bottom to front

                cube[2][2] = temp[0];cube[2][5] = temp[1];cube[2][8] = temp[2];//front to upper
                cube[5] = newR;
            }
            else{
                vector<char> newR(9,' ');
                newR = rot_clock(cube[5]);
                vector<char> temp;
                temp.push_back(cube[0][2]);temp.push_back(cube[0][5]);temp.push_back(cube[0][8]);
                
                cube[0][2] = cube[2][2];cube[0][5] = cube[2][5];cube[0][8] = cube[2][8];//upper to front

                cube[2][2] = cube[1][2];cube[2][5] = cube[1][5];cube[2][8] = cube[1][8];//front to bottom

                cube[1][2] = cube[3][6];cube[1][5] = cube[3][3];cube[1][8] = cube[3][0];//bottom to back

                cube[3][6] = temp[0];cube[3][3] = temp[1];cube[3][0] = temp[2];//back to upper

                cube[5] = newR;
            }
            break;
            default:
                cout<<"123123";
    }
    // cout<<s<<endl;
    // for(int k=0;k<6;k++){
    //     for(int i=0;i<3;i++){
    //         for(int j=0;j<3;j++){
    //             cout<<cube[k][i*3+j];
    //         }cout<<endl;
    //     }
    //     cout<<endl;
    // }
    // cout<<endl<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin>>T;
    for(int test_case = 0;test_case<T;test_case++){
        initiate();
        input();
        for(int k=0;k<N;k++){
            calc(rot[k]);
        }
        // cout<<"end state : "<<endl;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<cube[0][i*3+j];
            }cout<<endl;
        }
        // cout<<endl;
    }
    return 0;
}