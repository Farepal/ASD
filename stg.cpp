#include <iostream>
#include <vector>
#include <utility>

using namespace std;

struct node {
    int ind;
    int visited = 0;
    vector <pair<struct node*, int>> out;
};

void resetVisited (struct node* moving)
{
    if (moving->visited != 0)
    {
        moving->visited = 0;
        for (int i = 0; i < (moving->out).size(); i++)
            resetVisited((moving->out)[i].first);
    }
}

void insertEdge (int V, int toV, int bobot, bool *sudah, struct node* moving, struct node** root)
{
    if (root != nullptr)
    {
        moving->visited = 1;
        if (moving->ind == V)
        {
            struct node *baru;
            baru->ind = toV;
            (baru->out).push_back(make_pair(baru, bobot));
            *sudah = 1;
        }
        else
        {
            for (int i = 0; i < (moving->out).size(); i++)
            {
                insertEdge(V, toV, bobot, bobot);
            }
        }
    }
    else
    {
        struct node* baruV, *barutoV;
        baruV->ind = V;
        barutoV->ind = toV;
        (barutoV->out).push_back(make_pair(barutoV, bobot));
        *root = baruV;
    }
    resetVisited(*root);
}

int main()
{
    struct node **root = nullptr;


    return 0;
}