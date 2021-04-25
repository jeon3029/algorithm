H-Index
===
- 다양한 예제에 대해서 생각해 봐야 한다.
- EX) [100,200] --> ans = 2
- EX) [0,1,100] --> ans = 1


## Pseudo code
```c++
vector<int> citations;
sort(citations);
for(i=0;i<citations.size();i++){// 0부터 찾아가면서 i번이상 인용되었다면 그것이 답이다.
    for(j=0;j<citations.size();j++){
            if(citations[j]>i)cnt++;
    }

    if(i>=cnt){//처음으로 만족하는 경우를 찾은 경우
            answer = i;
            break;
    }
}
```