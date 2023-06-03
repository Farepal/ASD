#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define jumlahVertex 7
int adjacencyMatrix[jumlahVertex][jumlahVertex] = 
{
    {0, 2, 4, 1, 0, 0, 0},
    {2, 0, 0, 3, 10, 0, 0},
    {4, 0, 0, 2, 5, 0, 0},
    {1, 3, 2, 0, 7, 8, 4},
    {0, 10, 5, 7, 0, 0, 6},
    {0, 0, 0, 8, 0, 0, 1},
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

