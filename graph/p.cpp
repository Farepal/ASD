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

int main()
{
    bool visited[jumlahVertex];
    int key[jumlahVertex], parent[jumlahVertex];
    for (int i = 0; i < jumlahVertex; i++)
        key[i] = INFF, visited[i] = false;
    int jumlahEdges = 0;
    parent[0] = -1, key[0] = 0;
    int bobot = 0;
    for (int jumlahEdges = 0; jumlahEdges <= jumlahVertex - 1; jumlahEdges++)
    {
        //find the minimum key
        int min = INFF, menujuIndeks;
        for (int i = 0; i < jumlahVertex; i++)
        {
            if (key[i] < min && !visited[i])
                min = key[i], menujuIndeks = i;
        }
        visited[menujuIndeks] = true;
        cout << "vkepilih " << menujuIndeks +1 << endl;
        cout << min << endl;
        //UPDATED KEY
        for (int j = 0; j < jumlahVertex; j++)
        {
            if (!visited[j] && adjacencyMatrix[menujuIndeks][j] != 0 &&
            adjacencyMatrix[menujuIndeks][j] < key[j])
                parent[j] = menujuIndeks, key[j] = adjacencyMatrix[menujuIndeks][j];
        }
        for (int j = 0; j < jumlahVertex; j++)
            cout << key[j] << " ";
        cout << endl;
    }
    return 0;
}
