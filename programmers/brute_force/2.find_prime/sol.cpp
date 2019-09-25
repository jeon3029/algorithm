#include <string>
#include <vector>
#include<math.h>
using namespace std;
int check[10];
vector<int> result;
void permute(string a, int l, int r)
{
    // Base case
    if (l == r)  {
        int t = atoi(a.c_str());
        int flag=0;
        int notprime=1;
        if(t==2)notprime=0;
        else{
            int i;
            for(i=2;i<t;i++){
                if(t%i==0){
                    notprime=1;
                    break;
                }
            }
            if(i==t)notprime=0;
        }
        if(notprime==0){
            for(int i=0;i<result.size();i++){
                if(result[i]==t){
                    flag=1;break;
                }
            }
            if(flag==0){
                result.push_back(t);
            }
        }
    }
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {
            // Swapping done
            swap(a[l], a[i]);
            // Recursion called
            permute(a, l+1, r);
            //backtrack
            swap(a[l], a[i]);
        }
    }
}
void dfs(int it,int a,int n,string s){
    if(a==n){
        string temp="";
        for(int i=0;i<s.size();i++){
            if(check[i]==1){
                temp.append(1,s[i]);
            }
        }
        permute(temp,0,temp.size()-1);
        return;
    }
    for(int i=it;i<s.size();i++){
        if(check[i]==0){
            check[i]=1;
            dfs(i,a+1,n,s);
            check[i]=0;
        }
    }
}
int solution(string numbers) {
    int answer = 0;
    for(int i=1;i<=numbers.size();i++){
        dfs(0,0,i,numbers);
    }
    return result.size();
}
