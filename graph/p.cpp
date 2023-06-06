#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define jumlahVertex 7
#define INFF 214748364
int adjacencyMatrix[jumlahVertex][jumlahVertex] = {
    {0, 2, 4, 1, 0, 0, 0},
    {2, 0, 0, 3, 10, 0, 0},
    {4, 0, 0, 2, 0, 5, 0},
    {1, 3, 2, 0, 7, 8, 4},
    {0, 10, 0, 7, 0, 0, 6},
    {0, 0, 5, 8, 0, 0, 1},
    {0, 0, 0, 4, 6, 1, 0}
};

int findTheMinimumKey(int *key, bool* visited)
{
    int min = INFF, keVertex;
    for (int i = 0; i < jumlahVertex; i++)
    {
        if (key[i] < min && !visited[i])
            min = key[i], keVertex = i;
    }
    return keVertex;
}

void updateKey(int *key, bool *visited, int *parent, int keVertex)
{
    for (int j = 0; j < jumlahVertex; j++)
        {
            if (!visited[j] && adjacencyMatrix[keVertex][j] != 0 &&
            adjacencyMatrix[keVertex][j] < key[j])
                parent[j] = keVertex, key[j] = adjacencyMatrix[keVertex][j];
        }
}

void printVisited(bool* visited)
{
    cout << endl << "LIST VERTEX YG SUDAH DIKUNJUNGI" << endl;
    for (int i = 0; i < jumlahVertex; i++)
    {
        cout << "v" << i+1 << " ";
    }
    cout << endl;
    for (int i = 0; i < jumlahVertex; i++)
    {
        if (visited[i])
            cout << "Y  ";
        else
            cout << "N  ";
    }
    cout << endl << endl;
}

void printUpdateKey(int key[], int parent[])
{
    for (int i = 0; i < jumlahVertex; i++)
        (parent[i] > 100 or parent[i] == -1 ? cout << " X " : cout << "v" << parent[i]+1 << " ");
    cout << "\tparent" << endl;
    for (int i = 0; i < jumlahVertex; i++)
        cout << " | ";
    cout << endl;
    for (int i = 0; i < jumlahVertex; i++)
        cout << " | ";
    cout << endl;
    for (int i = 0; i < jumlahVertex; i++)
        cout << " | ";
    cout << endl;
    for (int i = 0; i < jumlahVertex; i++)
        cout << " V ";
    cout << endl;
    for (int i = 0; i < jumlahVertex; i++)
        cout << "v" << i+1 << " ";
    cout << endl;
    for (int i = 0; i < jumlahVertex; i++)
        (key[i] > 100 ? cout << "IF " : cout << key[i] << "  ");
    cout << "\tkey" << endl;
}

int main()
{
    bool visited[jumlahVertex];
    int key[jumlahVertex], parent[jumlahVertex];
    for (int i = 0; i < jumlahVertex; i++)
        key[i] = INFF, visited[i] = false, parent[i] = INFF;
    int jumlahEdges = 0;
    //START ALGORITHM
    parent[0] = -1, key[0] = 0;
    int bobot = 0;
    for (int jumlahEdges = 0; jumlahEdges <= jumlahVertex - 1; jumlahEdges++)
    {
        //find the minimum key
        printVisited(visited);
        printUpdateKey(key, parent);
        int keVertex = findTheMinimumKey(key, visited);
        cout << endl << "vertex yang kepilih : v" << keVertex+1 << endl << endl; 
        visited[keVertex] = true;
        //UPDATED KEY
        updateKey(key, visited, parent, keVertex);
        printUpdateKey(key, parent);
    }
    //END ALGORITHM
    cout << endl;
    int TotalBobot = 0;
    for(int i = 0; i < jumlahVertex; i++)
    {
        cout << "v" << parent[i]+1 << " - v" << i+1 << " w: " << key[i] << endl;
        TotalBobot += adjacencyMatrix[i][parent[i]];
    }
    cout << "Total Bobot : " << TotalBobot << endl;
    return 0;
}
