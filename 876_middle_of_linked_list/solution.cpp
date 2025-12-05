#include<bits/stdc++.h>
using namespace std;

struct ListNode {
   int val;
   ListNode* next;
   ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main() {
   Solution sol;
   ListNode* n1 = new ListNode(1);
   ListNode* n2 = new ListNode(2);
   ListNode* n3 = new ListNode(3);
   ListNode* n4 = new ListNode(4);
   ListNode* n5 = new ListNode(5);
   ListNode* ans = sol.middleNode(n1);
   cout << "The middle node is: " << ans->val;
}
