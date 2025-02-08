#include <iostream>
using namespace std;

class MyLinkedList {
public:
    MyLinkedList() {//初始化链表
        head=new Node(0);
        tail=head;
        size=0;
       
    }
    
    int get(int index) {//返回链表中第index个节点的值。如果索引无效，则返回-1。
        if(index<0||index>=size){
            return -1;
        }
        Node *cur=head->next;
        for(int i=0;i<index;i++){
            cur=cur->next;
        }
        return cur->data;
    }
    //在链表的第一个元素之前添加一个值为val的节点。插入后，新节点将成为链表的第一个节点。
    void addAtHead(int val) {
        Node *cur=new Node(val);
        cur->next=head->next;//新节点的next指向原来的第一个节点
        head->next=cur;
        if(size==0){
            tail=cur;
        }
        size++;
    }
    //将值为val的节点追加到链表的最后一个元素。
    void addAtTail(int val) {
        Node *cur=new Node(val);
        tail->next=cur;//原来的最后一个节点的next指向新节点
        tail=cur;
        size++;
    }
    //在链表中的第index个节点之前添加值为val的节点。如果index等于链表的长度，则该节点将附加到链表的末尾。
    void addAtIndex(int index, int val) {
        if(index>size){
            return;
        }
        if(index<0){//如果index小于0，则在头部插入
            addAtHead(val);
            return;
        }
        if(index==size){//如果index等于size，则在尾部插入
            addAtTail(val);
            return;
        }
        Node *cur=head;//找到index的前一个节点
        for(int i=0;i<index;i++){
            cur=cur->next;
        }
        Node *newNode=new Node(val);
        newNode->next=cur->next;
        cur->next=newNode;
        size++;

    }
    //如果索引index有效，则删除链表中的第index个节点。   
    void deleteAtIndex(int index) {
        if(index<0||index>=size){
            return;
        }
        Node *cur=head; //找到index的前一个节点
        for(int i=0;i<index;i++){
            cur=cur->next;
        }
        Node *temp=cur->next;
        cur->next=cur->next->next;
        delete temp;
        size--;
        if(index==size){
            tail=cur;
        }

    }
private:
    struct Node
    {   
        int data;
        Node *next;
        Node *prev;
        Node(int x):data(x),next(NULL),prev(NULL){};
        Node* clear(){
            if(next!=NULL){
                next->clear();
                delete next;
            }
        }
    };
    Node *head;
    Node *tail;
    int size;

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */