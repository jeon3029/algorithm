#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int value;
    Node *next;
    Node *prev;
    Node(int x){
        value=x;
        next=NULL;
        prev=NULL;
    }
};
class dPQ{
public:
    int size;
    Node *head;
    Node *end;
    dPQ(){
        size=0;
        head=NULL;
        end=NULL;
    }
    void insert(int x){
        if(size==0){
            size++;
            head=end=new Node(x);
            return;
        }
        Node *p = head;
        Node *before = NULL;
        while(p!=NULL){
            if(p->value<x){
                break;
            }
            before=p;
            p=p->next;
        }
        if(p==head){//첫번째 위치에 삽입
            Node * temp=head;
            head = new Node(x);
            head->next=temp;
            temp->prev=head;
            size++;
        }
        else if(p==NULL){//마지막 위치에 삽입
            Node *temp=new Node(x);
            temp->prev=end;
            end->next=temp;
            end=temp;
            size++;
        }
        else{//중간 위치에 삽입
            Node *temp = new Node(x);
            before->next = temp;
            temp->prev=before;
            temp->next = p;
            p->prev=temp;
            size++;
        }
    }
    void deleteMax(){
        if(size==0){
            return;
        }
        else if(size==1){
            size=0;
            free(head);
            return;
        }
        else{
            Node *temp = head;
            head=head->next;
            head->prev=NULL;
            free(temp);
            size--;
        }
    }
    void deleteMin(){
        if(size==0){
            return;
        }
        else if(size==1){
            size=0;
            free(end);
            end=NULL;
            return;
        }
        else{
            //시간 안나오면 이부분 수정
            free(end->next);
            end=end->prev;
            end->next=NULL;
            size--;
        }
    }
    int getS(){
        return size;
    }
    int getF(){
        return head->value;
    }
    int getT(){
        return end->value;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;cin>>T;
    while(T--){
        dPQ *q = new dPQ();
        int t;cin>>t;
        while(t--){
            string s;int k;
            cin>>s>>k;
            if(s=="I"){
                q->insert(k);
            }
            else{//D
                if(k==1){
                    q->deleteMax();
                }
                else{
                    q->deleteMin();
                }
            }
        }
        if(q->getS()==0){
            cout<<"EMPTY\n";
        }
        else{
            cout<<q->getF()<<" "<<q->getT()<<endl;
        }
        free(q);
    }
}