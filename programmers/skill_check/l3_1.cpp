#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer=0;
    bool check[n+1];//1~n coverage check
    fill(check,check+n+1,0);
    for(int i=0;i<stations.size();i++){
        int a=stations[i]-w;
        int b=stations[i]+w;
        if(a<1)a=1;
        if(b>n)b=n;
        for(int j=a;j<=b;j++)check[j]=true;
    }
    for(int i=1;i<=n;i++){
        if(check[i]==1)continue;
        else{//check == 0
            int j;
            for(j=i+1;j<=n;j++){//find 1
                if(check[j]==1)break;
            }
            int t = (j-i)/(2*w+1);
            int tt = (j-i)%(2*w+1);
            //cout<<j-i<<endl;
            answer+=t;
            if(tt!=0)answer++;
            i=j;
        }
    }
    return answer;
}
