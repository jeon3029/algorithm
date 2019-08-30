#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  while(n--){
    string s;
    cin>>s;
    //type check
    int flag = 0; // 0 =alpha type 1 = r/c type
    int i;
    for(i=0;i<s.size();i++){
      if(s[i]>='A' && s[i]<='Z')continue;
      else break;
    }
    for(;i<s.size();i++){
      if(s[i]>='0' && s[i] <='9')continue;
      else break;
    }
    if(i==s.size()) flag = 0;
    else flag = 1;

    //cale numeration system
    if(flag==0){//alpha -> r/c
      for(i=0;i<s.size();i++){
        if(s[i]>='A' && s[i]<='Z')continue;
        else break;
      }
      //calc row
      int row = atoi(s.substr(i,s.size()-i).c_str());
      //calc col
      string temp = s.substr(0,i);
      int col=0;
      int mul = 1;
      while(i--){
        col += (temp[i]-'A'+1)*mul;
        mul*=26;
      }
      cout<<"R"<<row<<"C"<<col<<endl;
    }
    else{//r/c -> alpha
      for(i=1;i<s.size();i++){
        if(s[i]=='C')break;
      }
      int row = atoi(s.substr(1,i-1).c_str());
      int col = atoi(s.substr(i+1,s.size()-(i+1)).c_str());
      //cout<<row<<" "<<col;
      string temp = "";
      while(col!=0){
        char x = col%26+'A'-1;
        if(x<'A'){
         temp.append("Z");
         col-=26;
         col/=26;
        }
        else{
          temp.append(1,x);
          col/=26;
        }
      }

      for(int i=temp.size()-1;i>=0;i--){
        cout<<temp[i];
      }
      cout<<row<<endl;
    }
  }
  return 0;
}
