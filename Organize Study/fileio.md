### 파일 입출력

> ```c++
> #include<fstream>
> ifstream in("in.txt");
> ofstream out("out.txt");
> //or
> ifstream in;
> ofstream out;
> in.open("in.txt");
> out.open("out.txt");
> if(in.is_open()){
>   in>> ....;
> }
> out<<...;
> in.close();
> out.close();
> //꼭 닫아주어야 한다.
> ```
