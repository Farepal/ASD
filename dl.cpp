#include <iostream>

using namespace std;

struct NODE {
	int data;
	struct NODE *prev, *next;
};

void insertNode(struct NODE** pointToHead, int x)
{
	struct NODE* node_baru = (struct NODE*)malloc(sizeof(struct NODE));
	node_baru->data = x;
	node_baru->prev = NULL;
	node_baru->next = (*pointToHead);
	if (node_baru->next != NULL)
	{
		(*pointToHead)->prev = node_baru;
	}
	(*pointToHead) = node_baru;
}

void insertAtGivenPos(struct NODE** pointToHead, int position, int value)
{
	struct NODE* baru = (struct NODE*)malloc(sizeof(struct NODE));
	baru->data = value;
	struct NODE* temp = *pointToHead;
	bool apakahTerakir = false;
	if (temp == NULL || position <= 0) return;
	for (int i = 1; i < position; i++)
	{
		if (temp == NULL) return;
		if (temp->next == NULL && i == position-1)
		{
			apakahTerakir = true;
			break;
		}
		temp = temp->next;
	}
	cout << temp << endl;
	
	if (temp == *pointToHead)
	{
		baru->prev = NULL;
		baru->next = temp;
		temp->prev = baru;
		*pointToHead = baru;
	}
	else if (apakahTerakir)
	{
		baru->next = NULL;
		baru->prev = temp;
		temp->next = baru;
	}
	else
	{
		baru->next = temp;
		baru->prev = temp->prev;
		temp->prev->next = baru;
		if (temp->next != NULL)
			temp->next->prev = baru;
	}
	
}

void deleteNODE(struct NODE** pointToHead, struct NODE* dihapus)
{
	if ((*pointToHead) == NULL || dihapus == NULL)
		return;
	if (*pointToHead == dihapus)
		*pointToHead = dihapus->next;
	else if (dihapus->next == NULL)
		dihapus->prev->next = NULL;
	else
		dihapus->prev->next = dihapus->next;
}

void deleteAtGivenPos(struct NODE** pointToHead, int x)
{
	if (*pointToHead == NULL || x <= 0)
		return;
	x--;
	struct NODE* temp = *pointToHead;
	while (x--)
	{
		if (temp == NULL)
			return;
		temp = temp->next; 
	}
	deleteNODE(pointToHead, temp);
}

void printNode(struct NODE* simpul)
{
	for (int i = 1; simpul != NULL; i++)
	{
		cout << "node ke-" << i << " = " << simpul << endl;
		if (simpul->prev == NULL)
			cout << "simpul->prev = NULL" << endl;
		else
			cout << "simpul->prev = " << simpul->prev << endl;
		
		if (simpul == NULL)
			cout << "simpul_data = kosong" << endl;
		else
			cout << "simpul->data = " << simpul->data << endl;

		if (simpul->next == NULL)
			cout << "simpul->next = NULL" << endl;
		else
			cout << "simpul->next = " << simpul->next << endl;

		simpul = simpul->next;
		cout << endl;
	}
}

int main()
{
	struct NODE* head = NULL;
	insertNode(&head, 10);
	insertNode(&head, 20);
	insertNode(&head, 7);
	insertNode(&head, 982);
	insertAtGivenPos(&head, 5, 109);
	printNode(head);
	return 0;
}
