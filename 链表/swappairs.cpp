#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            return myswapPairs(head);
        }
    private:
        ListNode* myswapPairs(ListNode* head){
            ListNode* dummy=new ListNode(0);
            dummy->next=head;
            ListNode* cur=dummy;
            while(cur ->next!=nullptr&&cur->next->next!=nullptr){//cur->next->next!=nullptr是为了保证有两个节点
                ListNode* node1=cur->next;
                ListNode* node2=cur->next->next;
                cur->next=node2;//cur->next指向node2
                node1->next=node2->next;//node1->next指向node2->next
                node2->next=node1;//node2->next指向node1
                cur=node1;//cur指向node1
            }
            return dummy->next;
        }
    };
int main(){
    ListNode *head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    Solution s;
    ListNode *newhead=s.swapPairs(head);
    for(ListNode *cur=newhead;cur!=nullptr;cur=cur->next){
        cout<<cur->val<<" ";
    }
    return 0;
}
