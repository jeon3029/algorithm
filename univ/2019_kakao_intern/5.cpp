#include <string>
#include <vector>
#include <cstring>
using namespace std;
int tree[1<<22],base,n;
void init_tree(vector<int>& arr){
    for (base = 1; base < n; base *= 2);
    for (int i = base; i < n + base; i++) tree[i]=arr[i-base];
	for (int i = base - 1; i > 0; i--) tree[i] = max(tree[2 * i],tree[2 * i + 1]);
}
int range_max(int a, int b){
	int ret = 0;
	while (a < b){
		if (a % 2 == 1) ret = max(ret,tree[a]), a++;
		if (b % 2 == 0) ret = max(ret,tree[b]), b--;
		a >>= 1, b >>= 1;
	}
	if (a == b) ret = max(ret,tree[a]);
	return ret;
}
int solution(vector<int> stones, int k) {
    int answer = 2100000000;
    n=stones.size();
    memset(tree,0,sizeof(tree));
    init_tree(stones);
    for(int i=0;i<stones.size()-k+1;i++){
        answer = min(answer,range_max(base+i,base+i+k-1));
    }
    return answer;
}