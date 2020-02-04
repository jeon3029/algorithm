#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
class Tree{
    public:
    Tree *leftTree;
    Tree *rightTree;
    string value;
    int index;
    Tree(){
        leftTree = NULL;
        rightTree = NULL;
        value = "";
        index = 1;
    }
    Tree(int i, string s= ""){
        index = i;
        value = s;
        leftTree = NULL;
        rightTree = NULL;
    }
};
Tree * search(Tree * t, int id){
    if(t==NULL)return NULL;
    if(t->index == id){
        return t;
    }
    //cout<<t->index<<endl;
    if(search(t->leftTree,id)){
        return search(t->leftTree,id);
    }
    else if(search(t->rightTree,id)){
        return search(t->rightTree,id);
    }
    return NULL;
}
double in_order(Tree *t){
    if(t->leftTree){
        if(t->value=="+")
            return in_order(t->leftTree)+in_order(t->rightTree);
        else if(t->value=="-")
            return in_order(t->leftTree)-in_order(t->rightTree);
        else if(t->value=="*")
            return in_order(t->leftTree)*in_order(t->rightTree);
        else //if(t->value=="/")
            return in_order(t->leftTree)/in_order(t->rightTree);
    }
    else{
        return atof(t->value.c_str());
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
        int answer;
        string input;
        int N;
        getline(cin,input);
        N=atoi(input.c_str());
        Tree *root = new Tree();
        for(int i=0;i<N;i++){
            getline(cin,input);
            istringstream ss(input);
            string str;
            getline(ss,str,' ');
            int index = atoi(str.c_str());
            Tree* t = search(root,index);
            getline(ss, str, ' ');
            t->value = str;
            if(str[0]=='+'||str[0]=='-'||str[0]=='*'||str[0]=='/'){
                getline(ss, str, ' ');
                int left = atoi(str.c_str());
                t->leftTree = new Tree(left);
                getline(ss, str, ' ');
                int right = atoi(str.c_str());
                t->rightTree = new Tree(right);
            }
        }
        answer = in_order(root);
        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;
}