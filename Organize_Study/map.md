```c++
#include<map>
#include<unordered_map>
//정렬 필요하지 않은 경유 unordered_map사용
map<string,int> m;
string s1;
int n1;
m.insert({s1,n1});

//찾기
string s2;
if(m.find(s2)!=m.end()){//찾은 경우
    //idx = m.at(s2);
}


```