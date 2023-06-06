#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define jumlahVertex 7
int adjacencyMatrix[jumlahVertex][jumlahVertex] = 
{
    {0, 2, 4, 1, 0, 0, 0},
    {2, 0, 0, 3, 10, 0, 0},
    {4, 0, 0, 2, 0, 5, 0},
    {1, 3, 2, 0, 7, 8, 4},
    {0, 10, 0, 7, 0, 0, 6},
    {0, 0, 5, 8, 0, 0, 1},
    {0, 0, 0, 4, 6, 1, 0}
}; 

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
int Parent[jumlahVertex];

int find_root(int numberOfVertex)
{
    if (Parent[numberOfVertex] == numberOfVertex)
    {
        return numberOfVertex;
    }
    return find_root(Parent[numberOfVertex]);
}

bool checkCycle(int sVertex, int dVertex)
{
    if (find_root(sVertex) == find_root(dVertex))
        return false;
    return true;
}

void unionSubtree(int rootOfSubtree1, int rootOfSubtree2)
{
    Parent[rootOfSubtree1] = Parent[rootOfSubtree2];
}

void cetakParent()
{
    for (int i = 0; i < jumlahVertex; i++)
        cout << "v" << i+1 << " ";
    cout << endl;
    for (int i = 0; i < jumlahVertex; i++)
        cout << "v" << Parent[i]+1 << " ";
    cout << endl << endl;
}

int main()
{
    for (int i = 0; i < jumlahVertex; i++)
    {
        for (int j = 0; j < jumlahVertex; j++)  
        {
            cout << adjacencyMatrix[i][j] << "  ";
        }
        cout << endl;
    }

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
        Parent[i] = i;

    cout << "SORTED GRAPH" << endl;
    cout << "EDGE\t\t" << "WEIGHTS" << endl; 
    for (int i = 0; i < jumlahEdges; i++)
        cout << "v" << graph[i].sourceVertex + 1 << " - v" << graph[i].destinationVertex + 1 << "\t\t" << graph[i].weight << endl;
    cout << endl;

    int hasilEdges = 0;
    for (int i = 0; i < jumlahEdges && hasilEdges < jumlahVertex-1; i++)
    {
        cout << "Step ke-" << i+1 << endl << endl;
        cout << "Jumlah Edges MST : " << hasilEdges << endl << endl;
        cout << "Parent before PASS" << endl;
        cetakParent();
        cout << "PASS EDGE" << endl;
        cout << "v" << graph[i].sourceVertex+1 << " - v" << graph[i].destinationVertex+1  << " " << graph[i].weight << "\t" << endl;

        if (checkCycle(graph[i].sourceVertex, graph[i].destinationVertex))
        {
            cout << endl << "BERHASIL" << endl << endl;
            int rootOfVertex1 = find_root(graph[i].sourceVertex);
            int rootOfVertex2 = find_root(graph[i].destinationVertex);

            //vertex destinasi biasanya bakal menjadi root di subtree
            MST.push_back(graph[i]);
            unionSubtree(rootOfVertex1, rootOfVertex2);\
            cout << "Parent after PASS" << endl;
            cetakParent();
            hasilEdges++;
        }
        else
        {
            cout << endl << "GAGAL" << endl << endl;
            cout << "Parent after PASS" << endl;
            cetakParent();
        }
        cout << "Jumlah Edges MST : " << hasilEdges << endl << endl;
    }

    int total_Bobot = 0;
    cout << "EDGE\t\t" << "WEIGHTS" << endl; 
    for (int i = 0; i < MST.size(); i++)
    {
        cout << "v" << MST[i].sourceVertex + 1 << " - v" << MST[i].destinationVertex + 1 << "\t\t" << MST[i].weight << endl;
        total_Bobot += MST[i].weight;
    }
    cout << "TOTAL WEIGHT : " << total_Bobot << endl;
    return 0;
}