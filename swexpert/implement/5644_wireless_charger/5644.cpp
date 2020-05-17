#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
class Charger{
    public:
    int x;int y;
    int d;int power;
    Charger(int a,int b,int c,int d):x(a),y(b),d(c),power(d){}
};
int M,A;
int A_mov[100];
int B_mov[100];
Charger *Beacon[8];
void input(){
    cin>>M>>A;
    rep(i,0,M)cin>>A_mov[i];
    rep(i,0,M)cin>>B_mov[i];
    rep(i,0,A){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        Charger *temp = new Charger(a,b,c,d);
        delete Beacon[i];
        Beacon[i]=temp;
    }
}
int A_x,A_y,B_x,B_y;
int dx[5] = {0,0,1,0,-1};
int dy[5] = {0,-1,0,1,0};
int distance(int x1,int x2,int y1,int y2){
    return abs(x1-x2)+abs(y1-y2);
}
bool cmp(Charger *c1,Charger *c2){
    return c1->power>c2->power;
}
int calc(){
    A_x=1;A_y=1;
    B_x=10;B_y=10;
    sort(Beacon,Beacon+A,cmp);//sort by BC power 
    int battery = 0;
    rep(t,0,M+1){
        vector<int> A_access;//current acceble beacon list  
        vector<int> B_access;
        rep(i,0,A){
            if(distance(A_x,Beacon[i]->x,A_y,Beacon[i]->y)<=Beacon[i]->d){
                A_access.push_back(i);
            }
            if(distance(B_x,Beacon[i]->x,B_y,Beacon[i]->y)<=Beacon[i]->d){
                B_access.push_back(i);
            }
        }
        if(A_access.size()==0 && B_access.size()==0){
            //nothing happens
        }
        else if(A_access.size()>0 && B_access.size()==0){
            battery+=Beacon[A_access[0]]->power;
        }
        else if(A_access.size()==0 && B_access.size()>0){
            battery+=Beacon[B_access[0]]->power;
        }
        else{//both have accessble BC
            if(A_access[0] == B_access[0]){
                int cur_max = Beacon[A_access[0]]->power;//both sharing
                if(A_access.size()>1){
                    cur_max = max(cur_max,Beacon[A_access[0]]->power + Beacon[A_access[1]]->power);
                }
                if(B_access.size()>1){
                    cur_max = max(cur_max,Beacon[A_access[0]]->power + Beacon[B_access[1]]->power);
                }
                battery+=cur_max;
            }
            else{
                battery+= Beacon[A_access[0]]->power + Beacon[B_access[0]]->power;
            }
        }
        if(t < M){//do not move for last pos
            A_x = A_x + dx[A_mov[t]];
            A_y = A_y + dy[A_mov[t]];
            B_x = B_x + dx[B_mov[t]];
            B_y = B_y + dy[B_mov[t]];
        }
    }
    return battery;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        input();
        int answer = calc();
        cout<<"#"<<tc<<" "<<answer<<"\n";
    }
    rep(i,0,A)delete Beacon[i];
}