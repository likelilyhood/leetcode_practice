#include<iostream>
#include<vector>
using namespace std;


//1->2->3->4==4->3->2->1
struct ListNode {
            int val ;
            ListNode *next;
            ListNode() :val(0),next(nullptr){}
            ListNode(int x) : val(x),next(nullptr){}
            ListNode(int x,ListNode *next): val(x),next(next){}
        };
class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            return myreveseList(head);
        }
    private:
       ListNode* myreveseList(ListNode* head){
            ListNode* dummy=new ListNode(0);//
            dummy->next=head;
            ListNode* cur= dummy;
            ListNode* pre=nullptr;
            while(cur->next!=nullptr){
                ListNode* temp=cur->next;//保存cur->next节点
                cur->next=cur->next->next;//删除temp节点
                temp->next=pre;//将temp节点插入到pre节点之前
                pre=temp;//pre节点后移
            }
            return pre;
        }
    };
class Soultion2{
    public:
        ListNode* reverseList(ListNode* head){
            return myreverseList(head);
        }
    private:
        ListNode* myreverseList(ListNode* head){
            if(head==nullptr||head->next==nullptr){
                return head;
            }
            ListNode* newhead=myreverseList(head->next);
            head->next->next=head;
            head->next=nullptr;
            return newhead;
        }
};
int main(){ 

    ListNode *head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    Solution s;
    ListNode *newhead=s.reverseList(head);
    for(ListNode *cur=newhead;cur!=nullptr;cur=cur->next){
        cout<<cur->val<<" ";
    }

    
    return 0;
}