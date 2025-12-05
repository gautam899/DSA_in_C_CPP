#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
   int val;
   struct Node* next;
} Node;

struct Node* find_middle_node(struct Node* head) {
   if(head == NULL) {
   	return head;
   }
   struct Node* slow = head;
   struct Node* fast = head;
   while(fast != NULL && fast->next != NULL){
   	slow = slow->next;
	fast = fast->next->next;	
   }
   return slow;
}

int main() {
   struct Node* head;
   struct Node* n1 = NULL;
   struct Node* n2 = NULL;
   struct Node* n3 = NULL;
   struct Node* n4 = NULL;
   struct Node* n5 = NULL;
   struct Node* n6 = NULL;
   // Allocate memory
   n1 = malloc(sizeof(struct Node));
   n2 = malloc(sizeof(struct Node));
   n3 = malloc(sizeof(struct Node));
   n4 = malloc(sizeof(struct Node));
   n5 = malloc(sizeof(struct Node));
   n6 = malloc(sizeof(struct Node));
   n1->val = 1;
   n2->val = 2;
   n3->val = 3;
   n4->val = 4;
   n5->val = 5;
   n6->val = 6;
   n1->next = n2;
   n2->next = n3;
   n3->next = n4;
   n4->next = n5;
   n5->next = n6;
   n6->next = NULL;
   head = n1;
   struct Node* ans = find_middle_node(head);
   printf("The mid node for the linked list is %d", ans->val);
   return 0;
}
