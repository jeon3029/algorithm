```c++
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