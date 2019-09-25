단어 변환
===

## 알고리즘
- BFS로 words가 transition가능한 모든 경우를 q에 넣고 
  모든 words에 대해서 순회한다.
```c++
while(!q.empty()){
        string current = q.front().first;
        int count = q.front().second;
        q.pop();
        for(int i=0;i<words.size();i++){
            //compare함수는 단어 1개차이인지 확인하는 함수
            //D안에는 현재 단어까지 transition최소 횟수 저장
            if(compare(current,words[i])&&D[i] > count+1){
                    D[i] = count + 1;
                    q.push(make_pair(words[i],D[i]));
            }
        }    
    }
```