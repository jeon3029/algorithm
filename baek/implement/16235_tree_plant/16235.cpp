#include<bits/stdc++.h>
using namespace std;
int Map[10][10];
int A[10][10];
int N,M,K;
class Tree{
    public:
    int x;
    int y;
    int age;
    bool live;
    Tree(int r,int c,int a){
        x=r;y=c;age=a;
        live = true;
    }
};
vector<Tree> trees;
vector<Tree> deadTrees;
void input(){
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            Map[i][j] = 5;
            cin>>A[i][j];
        }
    }
    for(int i=0;i<M;i++){
        int r,c,a;
        cin>>r>>c>>a;
        Tree t(r-1,c-1,a);
        trees.push_back(t);
    }
}
bool my_cmp(Tree a,Tree b){
    return a.age<b.age;
}
void spring(){
    //나무 나이만큼 양분먹고 나이 1 증가
    for(int i=0;i<trees.size();i++){
        int x = trees[i].x;int y = trees[i].y;
        int age = trees[i].age;
        if(Map[x][y]<age){//양분이 부족한 경우
            trees[i].live = false;//dead tree
        }
        else{
            Map[x][y]-=age;
            trees[i].age++;
        }
    }
    deadTrees.clear();
    vector<Tree> newTree;
    for(int i=0;i<trees.size();i++){//delete dead tree
        if(trees[i].live==false){
            deadTrees.push_back(trees[i]);
        }
        else{
            newTree.push_back(trees[i]);
        }
    }
    trees = newTree;
}
void summer(){
    for(int i=0;i<deadTrees.size();i++){
        int x = deadTrees[i].x;
        int y = deadTrees[i].y;
        Map[x][y]+=deadTrees[i].age/2;
    }
}
bool isWall(int x,int y){
    if(x<0||y<0||x>=N||y>=N)return true;
    return false;
}
void fall(){
    int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    vector<Tree> newTree;
    for(int i=0;i<trees.size();i++){
        if(trees[i].age%5==0){
            int curX = trees[i].x;
            int curY = trees[i].y;
            for(int i=0;i<8;i++){
                int nextX = curX+dir[i][0];
                int nextY = curY+dir[i][1];
                if(!isWall(nextX,nextY)){
                    Tree t(nextX,nextY,1);
                    newTree.push_back(t);
                }
            }
        }
    }
    trees.insert(trees.begin(),newTree.begin(),newTree.end());
}
void winter(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            Map[i][j]+=A[i][j];
        }
    }
}
int main(int argc,char**argv){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    sort(trees.begin(), trees.end(), my_cmp);
    for(int t=0;t<K;t++){
        spring();
        summer();
        fall();
        winter();
    }
    cout<<trees.size();
}