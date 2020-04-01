vector<vector<int>> mlist;//possible banned id list
vector<vector<int>> possible;
int banned_len;
void find(int current,vector<int> check,vector<int>l){
    if(current==banned_len){
        //check duplicate
        sort(l.begin(),l.end());
        int flag=0;
        for(int i=0;i<mlist.size();i++){
            if(mlist[i].size()!=l.size())continue;
            int j;
            for(j=0;j<mlist[i].size();j++){
                if(mlist[i][j]==l[j])continue;
                else{
                    break;
                }
            }
            if(j==mlist[i].size()){//같은걸 찾은경우
                flag=1;break;
            }
        }
        if(flag==1)return;
        else mlist.push_back(l);
        //input to list
        return;
    }
    for(int j=0;j<possible[current].size();j++){
        if(check[possible[current][j]]==0){
            check[possible[current][j]]=1;
            l.push_back(possible[current][j]);

            find(current+1,check,l);

            check[possible[current][j]]=0;
            l.pop_back();
        }
    }
}
bool check(string s1,string s2){
    if(s1.size()!=s2.size())return false;
    for(int i=0;i<s1.size();i++){
        if(s1[i]=='*')continue;
        if(s1[i]==s2[i])continue;
        else{
            return false;
        }
    }
    return true;
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    banned_len = banned_id.size();
    for(int i=0;i<banned_id.size();i++){
        vector<int> t;
        for(int j=0;j<user_id.size();j++){
            if(check(banned_id[i],user_id[j])){//pattern correct
                t.push_back(j);
            }
        }
        possible.push_back(t);
    }
    vector<int> check(user_id.size(),0);
    vector<int> l;
    find(0,check,l);
    cout<<mlist.size()<<endl;
    return 0;
}