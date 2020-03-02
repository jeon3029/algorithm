#include <iostream>
#include <cstring>
#define MAX 12

using namespace std;
int N;
int big, small;
int oper[4];
int mat[MAX];

void init(){
    memset(mat, 0, sizeof(mat));
    oper[0] = 0;oper[1] = 0;oper[2] = 0;oper[3] = 0;
    big = -100000000;
    small = 100000000;
}

int check(int idx, int res){
    if (idx == N-1){
        if (res < small)
        small = res;
        if (res > big)
        big = res;

        return res;
    }

    if (oper[0]){
        oper[0]--;
        check(idx + 1, res + mat[idx + 1]);
        oper[0]++;
    }
    if (oper[1]){
        oper[1]--;
        check(idx + 1, res - mat[idx + 1]);
        oper[1]++;
    }
    if (oper[2]){
        oper[2]--;
        check(idx + 1, res * mat[idx + 1]);
        oper[2]++;
    }
    if (oper[3]){
        oper[3]--;
        check(idx + 1, res / mat[idx + 1]);
        oper[3]++;
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int tc = 1;tc <= T;tc++){
        init();
        cin >> N;

        for (int i = 0;i < 4;i++)
        cin >> oper[i];
        for (int i = 0;i < N;i++)
        cin >> mat[i];

        check(0, mat[0]);

        cout << "#" << tc << " " << big - small << endl;
    }
    return 0;
}