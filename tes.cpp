#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector <int> enc;
vector <int> flag(38);

void decode(int index)
{
    if (index == 38)
    {
        bool flag = true;
        for (int i = 0; i < 38; i+=2)
        {
            if (((flag[i] << 8)  + flag[i+1]) == enc[i/2])
        }
    }
    else
    {
        for (int i = 0; i <= 122; i++)
        {
            
        }
    }
}

int main()
{
    for (int i =0;i < 19;i++)
    {
        int x;
        cin >> x;
        enc.push_back(x);
    }
    return 0;
}