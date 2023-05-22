//delete a node from double linked-list at position n 

#include <bits/stdc++.h>
using namespace std;
struct Node {
   int data;
   struct Node *prev, *next;
};
void deleteNode(struct Node** head_ref, struct Node* del) {
   if (*head_ref == NULL || del == NULL) {
      return;
   }
   // head node
   if (*head_ref == del) {
      *head_ref = del->next;
   }
   // middle node
   if (del->next != NULL) {
      del->next->prev = del->prev;
   }
   // end node
   if (del->prev != NULL) {
      del->prev->next = del->next;
   }
   free(del);
}
void deleteNodeAtGivenPosition(struct Node** head_ref, int n) {
   if (*head_ref == NULL || n <= 0) {
      return;
   }
   struct Node* current = *head_ref;
   int i;
   for (int i = 1; current != NULL && i < n; i++) {
      current = current->next;
   }
   if (current == NULL) {
      return;
   }
   deleteNode(head_ref, current);
}
void insertNode(struct Node** head_ref, int new_data) {
   struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->prev = NULL;
   new_node->next = (*head_ref);
   if ((*head_ref) != NULL) {
      (*head_ref)->prev = new_node;
   }
   (*head_ref) = new_node;
}
void printLinkedList(struct Node* head) {
   while (head != NULL) {
      cout << head->data << "->";
      head = head->next;
   }
}
int main() {
	struct Node* head = new Node();
	head->data = 20;
	cout << head->prev << endl;
	cout << head->data << endl;
	cout << head->next << endl;
   /* struct Node* head = NULL; */
   /* insertNode(&head, 5); */
   /* insertNode(&head, 2); */
   /* insertNode(&head, 4); */
   /* insertNode(&head, 8); */
   /* insertNode(&head, 10); */
   /* cout << "Doubly linked list before deletion" << endl; */
   /* printLinkedList(head); */
   /* Node* temp = head; */
   
   /* cout << "\nDoubly linked list after deletion" << endl; */
   /* printLinkedList(head); */
   return 0;
}
