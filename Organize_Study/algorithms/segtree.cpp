//5
//7 2 1 9 8
//2
//2 4 3
//1 3 5
#include <iostream>
int tree[1 << 18], n, base, q;
int range_sum(int a, int b){
	int sum = 0;
	while (a < b){
		if (a % 2 == 1) sum += tree[a], a++;
		if (b % 2 == 0) sum += tree[b], b--;
		a >>= 1, b >>= 1;
	}
	if (a == b) sum += tree[a];
	return sum;
}
void update(int a, int b){
	tree[a] = b;
	a >>= 1;
	while (a){
		tree[a] = tree[2 * a] + tree[2 * a + 1];
		a >>= 1;
	}
}
void initTree(){
    scanf("%d", &n);
	for (base = 1; base < n; base *= 2);
    for (int i = base; i < n + base; i++) scanf("%d", &tree[i]);
	for (int i = base - 1; i > 0; i--) tree[i] = tree[2 * i] + tree[2 * i + 1];
}
int main(){
	scanf("%d", &q);
	while (q--){
		int c, a, b;
		scanf("%d %d %d", &c, &a, &b);
		if (c == 1){
			printf("%d\n", range_sum(base + a - 1, base + b - 1));
		}
		else{
			update(base + a - 1, b);
		}
	}
	return 0;
}