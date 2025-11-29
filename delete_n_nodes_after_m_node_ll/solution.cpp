#include<bits/stdc++.h>
using namespace std;
/*
delete n nodes after m nodes
  The input list will have at least one element
  Node is defined as
*/
struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        // code here
        // Create a new node to keep track of the new head.
        Node* dummy = new Node(0);
        dummy->next = head;
        Node* p1 = dummy;
        while(p1 != NULL){
            // Move p1 ahead by m 
            for(int i=1;i<=m && p1 != NULL;i++){
                p1 = p1->next;
            }
            if(p1 == NULL){
                return dummy->next;
            }
            Node* p2 = p1;
            // Move p2 ahead by n
            for(int i=1;i<=n && p2!=NULL;i++){
                p2 = p2->next;
            }
            // Only point p1->next to p2->next if p2 is not null otherwise it will
            // give seg fault.
            p1->next = p2 ? p2->next : NULL;
            // Only point p2->next to null if it is not already null.
            if(p2 != NULL){
                p2->next = NULL;
            }
        }
        return dummy->next;
    }
};

int main() {
    //Create a linked list.
    //9->1->3->5->9->4->10->1, n = 1, m = 2
    Node* n1 = new Node(9);
    Node* n2 = new Node(1);
    Node* n3 = new Node(3);
    Node* n4 = new Node(5);
    Node* n5 = new Node(9);
    Node* n6 = new Node(4);
    Node* n7 = new Node(10);
    Node* n8 = new Node(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    Solution sol;
    Node* newHead = sol.linkdelete(n1, 1, 2);
    Node* temp = newHead;
    while(temp != NULL){
    	cout << temp->data << " ";
	temp = temp->next;
    }
    return 0;
}
