#include<iostream>
#include<vector>
using namespace std;

//* Definition for singly-linked list.
  struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            return mygetIntersectionNode(headA,headB);
        }
    private:
        ListNode* mygetIntersectionNode(ListNode* HeadA,ListNode* HeadB){
            ListNode* curA=HeadA;
            ListNode* curB=HeadB;
            int lenA=0,lenB=0;
            while(curA->next!=nullptr){//计算链表A和链表B的长度
                lenA++;
                curA=curA->next;
            }
            while(curB->next!=nullptr){
                lenB++; 
                curB=curB->next;
            }
            curA=HeadA;//重新指向链表头
            curB=HeadB;
            if(lenA>lenB){
                for(int i=0;i<lenA-lenB;i++){
                    curA=curA->next;
                }
            }
            else{
                for(int i=0;i<lenB-lenA;i++){
                    curB=curB->next;
                }
            }
            while(curA!=curB){
                curA=curA->next;
                curB=curB->next;
            }
            return curA;
            
        }
    };
int main(){
    ListNode *headA=new ListNode(4);
    headA->next=new ListNode(1);
    headA->next->next=new ListNode(8);
    headA->next->next->next=new ListNode(4);
    headA->next->next->next->next=new ListNode(5);
    ListNode *headB=new ListNode(5);
    headB->next=new ListNode(0);
    headB->next->next=new ListNode(1);
    headB->next->next->next=headA->next->next;
    Solution s;
    ListNode *newhead=s.getIntersectionNode(headA,headB);
    cout<<newhead->val;
    return 0;
}