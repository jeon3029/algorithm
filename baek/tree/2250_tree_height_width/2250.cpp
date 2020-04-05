    #include<bits/stdc++.h>
    using namespace std;
    int N;
    int tree[10001][3];
    int root = 0;
    void input(){
        cin>>N;
        for(int i=0;i<N;i++){
            int a,b,c;
            cin>>a>>b>>c;
            tree[a][0]=b;
            tree[a][1]=c;
            tree[b][2]=a;
            tree[c][2]=a;
        }
    }
    int idx;
    void preOrder(int n){
        if(n==-1)return;
        preOrder(tree[n][0]);
        tree[n][2]=++idx;
        preOrder(tree[n][1]);
    }
    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        input();
        idx=0;
        for(int i=1;i<=N;i++){
            if(tree[i][2]==0){
                root=i;break;
            }
        }
        preOrder(root);
        queue<int> q;
        q.push(root);
        int depth = 0;
        int width = 0;
        int d=0;
        while(!q.empty()){
            int len = q.size();
            int min_pos = 10001;
            int max_pos = -1;
            d++;
            for(int i=0;i<len;i++){
                int cur = q.front();
                q.pop();
                if(tree[cur][2]>max_pos){
                    max_pos=tree[cur][2];
                }
                if(tree[cur][2]<min_pos){
                    min_pos=tree[cur][2];
                }
                if(tree[cur][0]!=-1){
                    q.push(tree[cur][0]);
                }
                if(tree[cur][1]!=-1){
                    q.push(tree[cur][1]);
                }
            }
            if(max_pos-min_pos+1>width){
                depth = d;
                width = max_pos-min_pos+1;
            }
        }
        cout<<depth<<" "<<width<<"\n";
    }