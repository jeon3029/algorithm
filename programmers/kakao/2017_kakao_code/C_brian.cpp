#include <string>
#include<iostream>
#include<vector>
using namespace std;
vector<char> used;
bool already(char c){
    for(int i=0;i<used.size();i++){
        if(used[i]==c)return 1;
    }
    return 0;
}
bool isLower(char c){
    return c<='z' && c>='a';
}
bool isUpper(char c){
    return c<='Z' && c>='A';
}
bool type1check(string s){
    int cnt = 0;
    for(int i=0;i<s.size();i++){
        if(isLower(s[i]))cnt++;
    }
    if(cnt==0)return 1;
    if(!isUpper(s[0]) || !isUpper(s[s.size()-1])){
        return 0;
    }
    char c = s[1];
    if(isUpper(c)){
        return 0;
    }
    for(int i=0;i<s.size();i++){
        if(i%2==1){
            if(s[i]!=c){
                return 0;
            }
        }
    }
    return 1;
}
string solution(string s) {
    string answer = "";
    vector<int> stype(s.size(),0);
    used.clear();
    for(int i=0;i<s.size();i++){
        if(s[i]==' ')return "invalid";
        if(isUpper(s[i]))continue;
        else if(already(s[i])){
            return "invalid";
        }
        else{//find type 1 or type 2
            int cnt = 1;
            int j;
            int pos = i;
            // cout<<i<<" : "<<s[i]<<"\n";
            for(j=i+2;j<s.size();j++){
                if(isUpper(s[j]))continue;
                else if(s[j]==s[i]){
                    cnt++;
                    pos=j;
                }
            }
            if(cnt==1){
                if(i==0)return "invalid";
                if(i==s.size()-1)return "invalid";
                string temp = s.substr(i-1,3);
                if(type1check(temp)){
                    if(i>=1)stype[i-1]=3;
                    // stype[i-1]=1;
                    stype[i]=1;
                    stype[i+1]=1;
                    if(i+2<s.size())stype[i+2]=3;
                    i++;
                }
                else return "invalid";
            }
            else if(cnt==2){//type 2
                int cnt_U=0;
                for(int k=i;k<=pos;k++){
                    if(isUpper(s[k]))cnt_U++;
                }
                if(cnt_U==0)return "invalid";
                for(int k=i;k<=pos;k++){
                    if(isLower(s[k])&&s[k]!=s[i]){
                        string temp = s.substr(i+1,pos-i-1);
                        if(!type1check(temp)){
                            return "invalid";
                        }
                        else{
                            break;
                        }
                    }
                }
                for(int k=i+1;k<=pos-1;k++){
                    stype[k]=2;
                }
                stype[i]=3;
                stype[pos]=3;
                used.push_back(s[i]);
                i=pos;
            }
            else{//type 1
                int cnt_U=0;
                for(int k=i;k<=pos;k++){
                    if(stype[k]==3)return "invalid";
                    if(isUpper(s[k]))cnt_U++;
                }
                if(cnt_U==0)return "invalid";
                
                if(pos==s.size()-1)return "invalid";
                string temp = s.substr(i-1,pos-i+3);
                // cout<<"type1 : "<<temp<<"\n";
                if(type1check(temp)){
                    stype[i-1]=3;
                    for(int k=i;k<=pos+1;k++){
                        stype[k]=1;
                    }
                    if(pos+2<s.size())stype[pos+2]=3;
                    
                    if(pos<=s.size()-3)stype[pos+2]=3;
                    used.push_back(s[i]);
                    i=pos+1;
                }
                else{
                    return "invalid";
                }
            }
        }
    }
    for(int i=0;i<stype.size();i++){
        if(stype[i]==3){
            if(answer[answer.size()-1]!=' ')answer.append(" ");
        }
        if(isUpper(s[i])){
            answer.append(1,s[i]);
        }
    }
    for(int i=0;;i++){
        if(answer[i]==' '){
            answer.erase(i,1);
            i--;
        }
        else break;
    }
    for(int i=answer.size()-1;;i--){
        if(answer[i]==' '){
            answer.erase(i,1);
        }
        else break;
    }
    return answer;
}
int main(){
    string s;
    getline(cin,s);
    cout<<solution(s)<<"\n";
}