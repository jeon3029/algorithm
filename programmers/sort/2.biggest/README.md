가장 큰 수
===

## Algotrithm

- custom cmp 함수를 만들어 준다
```c++
//수를 만들어 보고 더 크게디는 경우를 return
bool comp(int a,int b){
    string s1 ,s2;
    s1.append(to_string(a));
    s1.append(to_string(b));

    s2.append(to_string(b));
    s2.append(to_string(a));

    return s1>s2;
}
```
