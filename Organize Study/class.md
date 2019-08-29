### Class pointer
- 클래스 여러개 생성
```c++
class A{
private:
int x;
int y;
public:
  A(int _x,int _y):x(_x),y(_y){}
}
A *data[1000];
for...
   data[i] = new A(x,y);
...
```
### bool operator
```c++
//정렬 조건 설정 가능
bool operator <(const A &k)const{
  return x < k.x;
}
```
### Vector Class : more efficient than pointer
- 마찬가지 클래스 여러개 생성

```c++
vector<A> data;
data.push_back(A(x,y));

sort(A.begin(),A.end());
```
