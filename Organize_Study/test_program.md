- 참고 : [errichto youtube](https://github.com/Errichto/youtube)

### brute 와 나의 answer를 비교할 때
```zsh
for((i=1;;++i)); do
    echo $i;
    ./gen $i > int
    #./a.out < int > out1
    #./brute < int > out2
    diff -w out1 out2 || break
    #diff -w (./brute < int) (./a.out < int ) ||break
done
```
### Generator
```c++
#include<bits/stdc++.h>
using namespace std;
int rand(int a,int b){
    return a+rand()%(b-a+1);
}
int main(int argc,char** argv){
    srand(atoi(argv[1]));
    int n = rand(2,20);
    cout<<n<<"\n";
    set<int> used;
    for(int i=0;i<n;i++){
        int x;
        do{
            x=rand(1,20);
        }while(used.count(x));
        cout<<x<<" ";
        used.insert(x);
    }puts("");
}
```

### Compile flags
```bash
# 1. fast running time
g++ -O2 -std=c++17 -Wno-unused-result -Wall -o a a.cpp
# 2. check for mistakes
g++ -std=c++17 .Wshadow -Wall -o -a a.cpp
 -fsanitize=address -fsanitize=undefined -D_GBLIBCXX_DEBUG -g
```


### Warnings
```c++
#warining TODO : remember to do ----something
```