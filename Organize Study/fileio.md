### 파일 입출력

```c++
#include<fstream>

ifstream in("in.txt");
ofstream out("out.txt");

if(in.is_open()){
  in>> ....;
}
out<<...;

in.close();
out.close();
```
