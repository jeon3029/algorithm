#include <stdio.h>
#include <math.h>
#include<iostream>
#include<algorithm>
#include<tuple>
#include<vector>
using namespace std;
int main(void)
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%f\n", sqrt(a + b));
	cout<<min({1,2,3,4})<<'\n';
	int t1,t2;
	tie(t1,t2) = minmax({1,2,3,4,5,6});
	cout<<t1<< " "<<t2<<"\n";
	vector<int> temp = {1,2,3,4,5,6};
	for(auto &it:temp){
		it=1;
		cout<<it<<" ";
	}puts("");
	for(auto it:temp){
		cout<<it<<" ";
	}
	puts("");
	return 0;
}
