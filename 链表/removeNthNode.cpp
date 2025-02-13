#include <iostream>
#include <vector>
using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            return myremoveNthFromEnd(head,n);
        }
        private:
        ListNode* myremoveNthFromEnd(ListNode* head,int n){
            ListNode* dummy=new ListNode(0);
            dummy->next= head;
            ListNode* fast=dummy;
            ListNode* slow=dummy;
            while(n--){//fast指针先走n步
                fast=fast->next;
            }
            while(fast->next!=nullptr){
                fast=fast->next;
                slow=slow->next;
            }
            slow->next=slow->next->next;
            return dummy->next;
        }
    };
int main(){
    ListNode *head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    Solution s;
    ListNode *newhead=s.removeNthFromEnd(head,2);
    for(ListNode *cur=newhead;cur!=nullptr;cur=cur->next){
        cout<<cur->val<<" ";
    }
    return 0;
}