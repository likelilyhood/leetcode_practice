#include<iostream>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {};
};
class Solution{
    public: 
        // 检测环的入口节点
        Node* detectCycle(Node* head){
            return myspy(head);
        }
    private: 
        // 辅助函数，用于实际检测环的入口节点
        Node* myspy(Node* head){
            Node* slow = head;
            Node* fast = head;
            // 快慢指针遍历链表
            while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
                // 当快慢指针相遇时，说明链表存在环
                if(slow == fast){
                    Node* ptr = head;
                    // 从链表头和相遇点同时出发，再次相遇的节点即为环的入口节点
                    while(ptr != slow){
                        ptr = ptr->next;
                        slow = slow->next;
                    }
                    // 找到入口节点后返回
                    return ptr;
                }
            }
            // 没有找到环，返回 NULL
            return NULL;
        }
};

int main(){
    Node* head=new Node(3);
    head->next=new Node(2);
    head->next->next=new Node(0);
    head->next->next->next=new Node(-4);
    head->next->next->next->next=head->next;
    Solution s;
    cout<<s.detectCycle(head)->val<<endl;
    return 0;
}
