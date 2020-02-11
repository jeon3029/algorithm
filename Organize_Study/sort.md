## custom cmp 만들기

1.

```c++
bool cmp(vector<int> vec1,vector<int> vec2){
    if(Time!=0){
        if(vec1[1]<=Time && vec2[1]<=Time){
            return vec1[2]<vec2[2];
        }
        else if(vec1[1]>Time && vec2[1]<=Time){
            return 0;
        }
        else if(vec1[1]<=Time && vec2[1]>Time){
            return 1;
        }
    }
    if(vec1[1]==vec2[1])return vec1[2]<vec2[2];
    return vec1[1]<vec2[1];
}
```

2.

```c++
bool comp(int a,int b){
    string s1 ,s2;
    s1.append(to_string(a));
    s1.append(to_string(b));

    s2.append(to_string(b));
    s2.append(to_string(a));

    return s1>s2;
}
```

3.

```c++
bool cmp(const int a,const int b){
  if(w[a] == w[b]) return h[a]<h[b];
  return w[a]<w[b];
}

sort(s,s+n+1,cmp);//remember sorting position

```
