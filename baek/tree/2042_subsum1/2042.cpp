#include <iostream>
long long tree[1 << 21],n,m,k, base, q;
long long range_sum(int a, int b){
	long long sum = 0;
	while (a < b){
		if (a % 2 == 1) sum += tree[a], a++;
		if (b % 2 == 0) sum += tree[b], b--;
		a >>= 1, b >>= 1;
	}
	if (a == b) sum += tree[a];
	return sum;
}
void update(int a, long long b){
	tree[a] = b;
	a >>= 1;
	while (a){
		tree[a] = tree[2 * a] + tree[2 * a + 1];
		a >>= 1;
	}
}
void initTree(){
    scanf("%lld%lld%lld", &n,&m,&k);
	for (base = 1; base < n; base *= 2);
    for (int i = base; i < n + base; i++) scanf("%lld", &tree[i]);
	for (int i = base - 1; i > 0; i--) tree[i] = tree[2 * i] + tree[2 * i + 1];
}
int main(){
    initTree();
	q=m+k;
	while (q--){
		long long a, b, c, d;
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 2){
			printf("%lld\n", range_sum(base + b - 1, base + c - 1));
		}
		else{
            // scanf("%lld",&d);
            // for(int i=b;i<=c;i++)update(base + i - 1, d);
            update(base+b-1,c);
		}
	}
	return 0;
}