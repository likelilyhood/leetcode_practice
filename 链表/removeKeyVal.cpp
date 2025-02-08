#include<iostream>
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
    ListNode* removeElements(ListNode* head, int val) {
        return myremoveElement(head, val);
    }

private:
    ListNode* myremoveElement(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;

        while (current->next != nullptr) {
            if (current->next->val == val) {
                // 临时保存要移除的节点
                ListNode* temp = current->next;
                // 跳过要移除的节点
                current->next = current->next->next;
                // 释放要移除节点的内存
                delete temp;
            } else {
                // 移动到下一个节点
                current = current->next;
            }
        }

        // 保存新的头节点
        ListNode* newHead = dummy->next;
        // 释放虚拟头节点的内存
        delete dummy;
        return newHead;
    }
};

int main() {
    // 创建示例链表
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    Solution s;
    // 移除值为 6 的节点
    ListNode *newhead = s.removeElements(head, 6);

    // 遍历并输出新链表的元素
    for (ListNode *cur = newhead; cur != nullptr; cur = cur->next) {
        cout << cur->val << " ";
    }
    cout << endl;

    // 释放新链表占用的内存
    while (newhead != nullptr) {
        ListNode* temp = newhead;
        newhead = newhead->next;
        delete temp;
    }

    return 0;
}