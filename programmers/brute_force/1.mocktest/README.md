모의고사
===
1번 수포자 : 1,2,3,4,5...
2번 수포자 : 2,1,2,3,2,4,2,5...
3번 수포자 : 3,3,1,1,2,2,4,4,5,5...
### 알고리즘
- answer = {a1.....an}
- 가장 많이 맞춘 사람?
#### Pseudo code
> ```c++
> //단순히 answer를 각각 순회하며 pattern과 일치하는지비교한다.
> for each element in answer{
>    if(ai == 1번 수포자 pattern) a1_ans++;
>    if(ai == 2번 수포자 pattern) a2_ans++;
>    if(ai == 2번 수포자 pattern) a3_ans++;
>  }
>  find max(a1,a2,a3_ans);
> }
> ```
