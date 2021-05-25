class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> answer;
        for(int i=0;i<words.size();i++){
            vector<int> pat_check(26,-1);
            bool isPattern = true;
            for(int j=0;j<words[i].size();j++){
                int pat_cur = pattern[j]-'a';
                int word_cur = words[i][j]-'a';
                if(pat_check[pat_cur]==-1){
                    pat_check[pat_cur] = word_cur;
                }
                else{
                    if(pat_check[pat_cur]!=word_cur){
                        isPattern = false;
                        break;
                    }
                }
            }
            for(int a=0;a<26 && isPattern==true;a++){
                if(pat_check[a]==-1)continue;
                for(int b=a+1;b<26;b++){
                    if(pat_check[b]==-1)continue;
                    if(pat_check[a]==pat_check[b]){
                        isPattern = false;
                        break;
                    }
                }
            }
            if(isPattern){
                answer.push_back(words[i]);
            }
        }
        return answer;
    }
};