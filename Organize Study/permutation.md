### 조합 문제
```c++
// N combination M
//#include<algorithm>
vector<int> array(N);
vector<int> check(N,0);
for(int i=0;i<M;i++){
    check[i] = 1;
}
sort(check.begin(),check.end());
do{
    //do something
    continue;
}while(next_permutation(check.begin(),check.end()));

```