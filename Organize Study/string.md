### String 정리본

```c++
#include<string>
//String to int
string s = "1234";
int x;
x = atoi(s.c_str());

//일부만 바꾸기
string s = "12+34";
int x,y;
x = atoi(s.substr(1,2).c_str());
y = atoi(s.substr(3,2).c_str());

//int to String
int x = 1234;
string s = to_string(x);
```
