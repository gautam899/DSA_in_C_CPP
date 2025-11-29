#include<bits/stdc++.h>
using namespace std;

struct Node {
 int val;
 Node* next;
 Node(int x): val(x), next(NULL) {};
};

class Solution {
   public:
	Node* remove_node(Node* head, int n){
	    if(head->next && n == 1){
		return NULL;
	    } 
	    Node* p1 = head;
	    Node* p2 = head;
	    for(int i=1;i<=n;i++){
		p2 = p2->next;			   
	    }
	    // If p2 is null. That will only be the case where the first node is removed.
	    if(p2 == NULL){
	    	return p1->next;
	    }
	    while(p2->next != NULL){
	    	p1 = p1->next;
		p2 = p2->next;
	    }
	    p1->next = p1->next->next;
	    return head;
	    /*
	    // In another approach we can rather use a extra node to avoid checking explicitly for p2 == NULL.
	    Node* start = head;
	    Node* fast = start;
	    Node* slow = start;

	    for(int i=1;i<=n;i++){
	    	fast = fast->next;
	    }
	    while(fast->next != NULL){
	    	slow = slow->next;
		fast = fast->next;
	    }
	    slow->next = slow->next->next;
	    return start->next;
	    */
	}
};

int main(){
   Solution sol;
   Node* n1 = new Node(1);
   Node* n2 = new Node(2);
   Node* n3 = new Node(3);
   Node* n4 = new Node(4);
   n1->next = n2;
   n2->next = n3;
   n3->next = n4;
   n4->next = NULL;

   Node* ans = sol.remove_node(n1, 2);
   // Print the list;
   Node* temp = ans;
   while(temp != NULL){
   	cout<< temp->val << " ";
	temp = temp->next;
   }
   return 0;
}

