#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define jumlahVertex 7
int adjacencyMatrix[jumlahVertex][jumlahVertex] = {
    {0, 2, 4, 1, 0, 0, 0},
    {2, 0, 0, 3, 10, 0, 0},
    {4, 0, 0, 2, 0, 5, 0},
    {1, 3, 2, 0, 7, 8, 4},
    {0, 10, 0, 7, 0, 0, 6},
    {0, 0, 5, 8, 0, 0, 1},
    {0, 0, 0, 4, 6, 1, 0}};

struct OneEdges
{
    int sourceVertex, destinationVertex, weight;
};

bool comparisonOfEdges (OneEdges A, OneEdges B)
{
    return (A.weight < B.weight);
}

vector<OneEdges> graph;//graph awal
vector <OneEdges> MST;//graph hasil MST
int jumlahEdges;//jumlah garis
int root[jumlahVertex];

int find_root(int numberOfVertex)
{
    if (root[numberOfVertex] == numberOfVertex)
    {
        return numberOfVertex;
    }
    return find_root(root[numberOfVertex]);
}

bool checkCycle(int sVertex, int dVertex)
{
    if (find_root(sVertex) == find_root(dVertex))
        return false;
    return true;
}

void unionSubtree(int rootOfSubtree1, int rootOfSubtree2)
{
    root[rootOfSubtree1] = root[rootOfSubtree2];
}

void cetakRoot()
{
    for (int i = 0; i < jumlahVertex; i++)
        cout << "v" << root[i]+1 << " ";
    cout << endl;
}

int main()
{
    for (int i = 0; i < jumlahVertex; i++)
    {
        for (int j = i + 1; j < jumlahVertex; j++)
        {
            if (adjacencyMatrix[i][j] != 0)
            {
                OneEdges temp;
                temp.sourceVertex = i;
                temp.destinationVertex = j;
                temp.weight = adjacencyMatrix[i][j];
                graph.push_back(temp);
            }
        }
    }

    //Jumlah Edges
    jumlahEdges = graph.size();

    ////////////KRUSKAL ALGORITHM////////////////////////
    sort (graph.begin(), graph.end(), comparisonOfEdges);

    //DECLARE array ROOT untuk
    for (int i = 0; i < jumlahVertex; i++)
        root[i] = i;
    for (int i = 0, hasilEdges = 0; i < jumlahEdges && hasilEdges < jumlahVertex - 1; i++)
    {
        if (checkCycle(graph[i].sourceVertex, graph[i].destinationVertex))
        {
            int rootOfVertex1 = find_root(graph[i].sourceVertex);
            int rootOfVertex2 = find_root(graph[i].destinationVertex);
            //vertex destinasi biasanya bakal menjadi root di subtree
            MST.push_back(graph[i]);
            unionSubtree(rootOfVertex1, rootOfVertex2);
            
        }
    }
    int TotalBobot = 0;
    for (int i = 0; i < MST.size(); i++)
    {
        cout << "v" << MST[i].sourceVertex + 1 << " - v" << MST[i].destinationVertex + 1 << " w: " << MST[i].weight << endl;
        TotalBobot += MST[i].weight;
    }
    cout << "Total Bobot : " << TotalBobot << endl;
    return 0;
}