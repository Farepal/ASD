#include <bits/stdc++.h>
using namespace std;
struct Node {
   int data;
   Node *prev, *next;
};
void deleteNode(Node** head_ref, Node* del) {
   if (*head_ref == NULL || del == NULL) {
      return;
   }
   if (*head_ref == del) {
      *head_ref = del->next;
   }
   if (del->next != NULL) {
      del->next->prev = del->prev;
   }
   if (del->prev != NULL) {
      del->prev->next = del->next;
   }
   free(del);
 
   return;
}
void insertNode(Node** head_ref, int x) {
   Node* new_node = new Node();
   new_node->data = x;
   new_node->prev = NULL;
   new_node->next = (*head_ref);
   if ((*head_ref) != NULL) {
      (*head_ref)->prev = new_node;
   }
   (*head_ref) = new_node;
}
void printLinkedList(Node* node) {
   while (node != NULL) {
      cout << node->data << " --> ";
      node = node->next;
   }
}
int main() {
   Node* head = NULL;
   insertNode(&head, 1);
   insertNode(&head, 2);
   insertNode(&head, 3);
   insertNode(&head, 4);
   insertNode(&head, 5);
   cout << "Linked List before deletion:" << endl;
   printLinkedList(head);
   deleteNode(&head, head->next);
   cout << "\nLinked List after deletion:" << endl;
   printLinkedList(head);
   return 0;
}
