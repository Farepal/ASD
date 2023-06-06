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

int main()
{
    bool visited[jumlahVertex];
    int key[jumlahVertex], parent[jumlahVertex];
    for (int i = 0; i < jumlahVertex; i++)
        key[i] = INFF, visited[i] = false;
    int jumlahEdges = 0;
    //START ALGORITHM
    parent[0] = -1, key[0] = 0;
    int bobot = 0;
    for (int jumlahEdges = 0; jumlahEdges <= jumlahVertex - 1; jumlahEdges++)
    {
        //find the minimum key
        int keVertex = findTheMinimumKey(key, visited);
        visited[keVertex] = true;
        //UPDATED KEY
        updateKey(key, visited, parent, keVertex);
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
