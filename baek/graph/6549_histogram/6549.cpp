#include<bits/stdc++.h>
#define f(i,n) for(int i=0;i<n;i++)
using namespace std;
//세그먼트 트리 - 구간별 최소 높이 구하기 : O(logn)
int N;
//각 구간별로 값이 가장 작은 것을 노드로 만들어 준다
void make_seg_tree(vector<int>&a,vector<int> &tree,int node,int start,int end){
    if(start == end){
        tree[node] = start;
    }
    else{
        make_seg_tree(a,tree,node*2,start,(start+end)/2);
        make_seg_tree(a,tree,node*2+1,(start+end)/2+1,end);
        if(a[tree[node*2]] <= a[tree[node*2+1]]){
            tree[node] = tree[node*2];
        }
        else{
            tree[node] = tree[node*2+1];
        }
    }
}
int query(vector<int> &a, vector<int> &tree, int node, int start, int end, int i, int j) {
    if (i > end || j < start) {
        return -1;
    }
    if (i <= start && end <= j) {
        return tree[node];
    }
    int m1 = query(a, tree, 2*node, start, (start+end)/2, i, j);
    int m2 = query(a, tree, 2*node+1, (start+end)/2+1, end, i, j);
    if (m1 == -1) {
        return m2;
    } else if (m2 == -1) {
        return m1;
    } else {
        if (a[m1] <= a[m2]) {
            return m1;
        } else {
            return m2;
        }
    }
}
//divide by minimum of start from end
long long largest(vector<int> &a, vector<int> &tree, int start, int end) {
    int m = query(a, tree, 1, 0, N-1, start, end);
    long long area = (long long)(end-start+1)*(long long)a[m];
    if (start <= m-1) {
        long long temp = largest(a, tree, start, m-1);
        if (area < temp) {
            area = temp;
        }
    }
    if (m+1 <= end) {
        long long temp = largest(a, tree, m+1, end);
        if (area < temp) {
            area = temp;
        }
    }
    return area;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(1){
        cin>>N;
        vector<int> Data(N);
        if(!N)break;
        f(i,N){
            cin>>Data[i];
        }
        int h = (int)(ceil(log2(N)));
        int tree_size = (1<<(h+1));
        vector<int> tree(tree_size);
        make_seg_tree(Data,tree,1,0,N-1);
        cout<<largest(Data,tree,0,N-1)<<"\n";
    }
    return 0;
}