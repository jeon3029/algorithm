#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    vector<int> A(9,0);
    int index = 0;
    for(int i=0;i<9;i++){
        cin>>A[i];
        if(A[i]>A[index])index=i;
    }
    cout<<A[index]<<endl<<index+1;
    return 0;
}