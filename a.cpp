// delete a node from double linked-list at position n

#include <iostream>
using namespace std;
void quickSort(int left, int right)
{
   // Operasi partisi,
   // operasi mencari indeks pivot, menempatkan subarray yg lebih kecil dari pivot di kiri
   // dan menempatkan subarray yang lebih besar dari pivot di kanan
   if (left < right)
   {
      int pivot = arr[right];
      int indexPositionShouldBe = left;  // pivoIndex yang akan digantikan
      for (int i = left; i < right; i++) // sampai right, karena right itu indeks pivot
      {
         countComparison++;
         if (arr[i] < pivot)
         {
            swap(&arr[indexPositionShouldBe], &arr[i]);
            indexPositionShouldBe++;
         }
      }
      swap(&arr[indexPositionShouldBe], &arr[right]);
      quickSort(left, indexPositionShouldBe - 1);
      quickSort(indexPositionShouldBe + 1, right);
   }
}
int main()
{
   struct Node *head = new Node();
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
