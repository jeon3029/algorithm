타켓넘버
===

## 구현 방법(DFS)
- 조건상 모든 case를 다 순회하여도 시간조건을 만족한다.
- 2^N가지 경우를 모두 탐색한다

```c++
// depth는 현재 위치, sum은 현재까지 합, arr은 배열
void dfs(int depth,int sum,vector<int> const arr){
    //끝까지 도달한 경우
    if(depth>=arr.size()){
        //조건을 만족할 때
        if(sum==num) cnt++;
        return;
    }
    dfs(depth+1,sum+arr[depth],arr);
    dfs(depth+1,sum-arr[depth],arr);
}
```
