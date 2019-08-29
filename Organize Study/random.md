### 임의 랜덤 넘버 생성
```cpp
//Small random
#include<ctime>
#include<iostream>
using namespace std;
srand((int)time(0));
r = rand()%100+1; 





//Big Random
#include <random>
using namespace std;

/* Seed */
random_device rd;
/* Random number generator */
default_random_engine generator(rd());

/* Distribution on which to apply the generator */
uniform_int_distribution<long long unsigned> distribution(0x0,0x7FFFFFF);
unsigned long long x;
x = distribution(generator);//random number
```
