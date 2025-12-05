#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // We can use the floyd's algorithm to find out the starting point of the cycle in the linked list if any.
        // First find out if there is any cycle.
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                slow = head;
                while(fast != slow){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL; // No cycle.
    }
};

int main() {
    Solution sol;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);
    // 1->2->3->4->5->6
    //        <-------
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n3;
    ListNode* ans = sol.detectCycle(n1);
    if (ans) {
  	 cout<< "The starting point of the loop is " << ans->val;
    }
    else {
         cout << "No cycle";
    }
    return 0;
}

