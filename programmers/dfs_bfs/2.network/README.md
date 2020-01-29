네트워크
===

## 구현 방법(BFS : network search)

- Pseudo Code
``` c++
//간단한 bfs search로 해당 point와 연결된 모든 point 찾음
bfs : find all the network connected to x{
    q.push(first point)
    while !q.empty(){
     x=q.pop();
     for each point connected to x{
         if point is not searched
             point : search
             q.push(point)
     }
    }
}
//모든 point에 대해서 순회하며 네트워크갯수를 찾음(cnt)
for( all points){
    if(point not checked)
        cnt++;
        bfs(find point);
}
```