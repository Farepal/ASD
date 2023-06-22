#include <iostream>
using namespace std;
int countComparison = 0;
int arr[1000];

struct BST
{
    int value;
    struct BST *leftChild, *rightChild;
};
void insertBST(struct BST **pointToRoot, int angkaMasukan)
{
    struct BST *nodeBaru = (struct BST *)malloc(sizeof(struct BST));
    nodeBaru->value = angkaMasukan;
    nodeBaru->rightChild = NULL;
    nodeBaru->leftChild = NULL;
    struct BST *penunjukSimpul = *pointToRoot;
    if (*pointToRoot != NULL)
    {
        while (true)
        {
            if (angkaMasukan >= penunjukSimpul->value)
            {
                countComparison++;
                if (penunjukSimpul->rightChild != NULL)
                    penunjukSimpul = penunjukSimpul->rightChild;
                else
                {
                    penunjukSimpul->rightChild = nodeBaru;
                    break;
                }
            }
            else
            {
                if (penunjukSimpul->leftChild != NULL)
                    penunjukSimpul = penunjukSimpul->leftChild;
                else
                {
                    penunjukSimpul->leftChild = nodeBaru;
                    break;
                }
            }
        }
    }
    else
        *pointToRoot = nodeBaru;
}
void createArrayByInorderTraversal(struct BST *simpul, int *index)
{
    if (simpul == NULL)
        return;
    else
    {
        createArrayByInorderTraversal(simpul->leftChild, index);
        arr[*index] = simpul->value;
        *index = *index + 1;
        createArrayByInorderTraversal(simpul->rightChild, index);
    }
}
void createArrayByPreorderTraversal(struct BST *simpul, int *index)
{
    if (simpul == NULL)
        return;
    else
    {
        arr[*index] = simpul->value;
        *index = *index + 1;
        createArrayByInorderTraversal(simpul->leftChild, index);
        createArrayByInorderTraversal(simpul->rightChild, index);
    }
}
void createArrayByPostorderTraversal(struct BST *simpul, int *index)
{
    if (simpul == NULL)
        return;
    else
    {
        createArrayByInorderTraversal(simpul->leftChild, index);
        createArrayByInorderTraversal(simpul->rightChild, index);
        arr[*index] = simpul->value;
        *index = *index + 1;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    return 0;
}