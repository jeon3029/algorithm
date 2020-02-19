#include<bits/stdc++.h>
using namespace std;
typedef union _s{
    float f;
    unsigned int i;
}S;
int main()
{
    S s1;
    S s2;
    s1.f=1.0;
    s2.f=0.0;
    for(int i=0;i<32;i++){
        cout << ((s1.i&(1<<i))>>i);
    }cout<<"\n";
    for(int i=0;i<32;i++){
        cout << ((s2.i&(0x1 << i))>>i);
    }
    cout << "\n";
    s2.f = -0.0;
    for (int i = 0; i < 32; i++){
        cout << ((s2.i & (0x1 << i))>>i);
    }
    cout << "\n";
}