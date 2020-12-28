#include<bits/stdc++.h>
using namespace std;
//predefined
unsigned char Data[100000];
int sm,sc,si;
int T;
char Code[5000];
char Input[5000];
int bracketPos[5000];
void input(){
  cin>>sm>>sc>>si;
  cin>>Code;
  cin>>Input;
} 
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin>>T;
  for(int test=1;test<=T;test++){
    memset(Data,0,sizeof (Data));
    memset(Code,0,sizeof (Code));
    memset(Input,0,sizeof (Input));
    memset(bracketPos,0,sizeof bracketPos);
    input();
    int pointer = 0;
    int counter = 0;
    int pos = 0;
    int inputPos = 0;
    //calc bracket pos;
    stack<pair<char,int>> s;
    for(int i=0;i<sc;i++){
      if(Code[i] == '['){
        s.push({'[',i});
      }
      else if(Code[i]==']'){
        bracketPos[s.top().second] = i;
        bracketPos[i] = s.top().second;
        s.pop();
      }
    }
    int rightB = 0;
    int flag = 0;
    while(pos < sc){
      // cout<<pos<<" : "<<Code[pos]<<"\n";
      counter++;
      if(counter>50000000){
        break;
      }
      if(Code[pos] == '+'){
        Data[pointer] = (unsigned char)(Data[pointer]+1);
      }
      else if(Code[pos] == '-'){
        Data[pointer] = (unsigned char)(Data[pointer]-1);//check
      }
      else if(Code[pos] == '<'){
        pointer = (pointer + sm-1 )% sm;
      }
      else if(Code[pos] == '>'){
        pointer = (pointer + 1 )% sm;
      }
      else if(Code[pos] == '.'){//print
        
      }
      else if(Code[pos] == ','){
        if(inputPos>=si){
          Data[pointer] = 255;
        }
        else{
          Data[pointer] = Input[inputPos++];
        }
      }
      else if(Code[pos] == '['){//print
        if(Data[pointer]==0){
          pos = bracketPos[pos];
          pos--;
        }
      }
      else{//']'
        if(Data[pointer]!=0){  
          if (counter>=40000000){//루프된 상황이라고 가정
            if(pos>rightB)rightB = pos;//최대한 오른쪽
          }
          pos = bracketPos[pos];
          pos--;
        }
      }
      pos++;
    }
    if(counter<=50000000){
      cout<<"Terminates\n";
    }
    else{
      cout<<"Loops "<<bracketPos[rightB]<<" "<<rightB<<"\n";
    }
  }
}