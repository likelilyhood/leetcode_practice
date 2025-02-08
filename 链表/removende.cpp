#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x):data(x),next(NULL){}

};
Node *removeNthFromEnd(Node *head,int n){
    Node* dummy=new Node(0);
    dummy->next=head;
    Node* first=dummy;//双指针法，一个用来找到对应数值，另外一个用来删除指向这个节点的指针
    Node* second=dummy; 
    for(int i=0;i<n+1;i++){
        first=first->next;
    }
    while(first!=NULL){
        first=first->next;
        second=second->next;
    }
    second->next=second->next->next;
    return dummy->next;
}
int main(){
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    Node *newhead=removeNthFromEnd(head,2);
    for(Node *cur=newhead;cur!=NULL;cur=cur->next){
        cout<<cur->data<<" ";
    }
    return 0;
}

