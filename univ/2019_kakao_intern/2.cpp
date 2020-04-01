
bool cmp(vector<int> a,vector<int> b){
    if(a.size()<b.size())return true;
    else return false;
}
vector<int> solution(string s) {
    vector<vector<int>> data;
    bool check[200010];
    for(int i=0;i<s.length();i++){ //parsing data
        vector<int> t;
        if(s[i]=='{'){
            for(int j=i+1;;j++){
                if(s[j]>='0' && s[j]<='9') {
                    int c;
                    int flag = 0;
                    int k;
                    for ( k = j + 1;; k++) {
                        if (s[k] == ',') {
                            c = k;

                            break;
                        }
                        if (s[k] == '}') {
                            c = k;
                            flag = 1;

                            break;
                        }
                    }
                    int x = atoi(s.substr(j, c - j).c_str());
                    j=k;
                    t.push_back(x);
                    if (flag == 1) {
                        i = j;
                        break;
                    }
                }
            }
            data.push_back(t);
            t.clear();
        }
    }
    sort(data.begin(),data.end(),cmp); //sorting data by size
    vector<int> answer;
    for(int i=0;i<data.size();i++){ //make tuple
        for(int j=0;j<data[i].size();j++){
            if(check[data[i][j]]==0){
                answer.push_back(data[i][j]);
                check[data[i][j]]=1;
            }
        }
    }
    
    return answer;
}