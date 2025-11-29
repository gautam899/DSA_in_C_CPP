#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL) {};
};
class Solution{
public:
    ListNode* reverseList(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        // Reverse rest of the list.
        ListNode* rest = reverseList(head->next);
        // Keep track of head's next, this is need to reverse the node connection.
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return rest;

        /*
        // 1->2->3->4->NULL.
        reverseList(1) {
            head:1
            rest: reverseList(2)
            rest = 4
            front = 2
            2->next = 1
            1->next = NULL 
            4->3->2->1->NULL
            return 4 
        }
        reverseList(2) {
            head:2
            rest= reverseList(3)
            rest = 4
            front = 2->next i.e 3
            front->next = head i.e 3->2
            head->next = NULL 3->2->NULL
            return rest

        }
        reverseList(3) {
            head:3
            rest = reverseList(4)
            rest = 4
            front = head->next = 4
            front->next = head i.e 4->3
            head->next = NULL 4->3->NULL
            return rest i.e 4
        }

        reverseList(4){
            head:4
            head->next == NULL, just one node, return head
        }
        */

    }
};

int main() {
    Solution sol;
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    ListNode* newHead = sol.reverseList(node1);
    // Print the reverse linked list.
    ListNode* temp = newHead;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    return 0;
}