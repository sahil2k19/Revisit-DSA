#include <bits/stdc++.h>

using namespace std;

void increment(int &i)
{
    i++;
}

int main()
{
    int m, n;
    cin >> m >> n;
    int **p = new int *[m];
    for (int i = 0; i < m; i++)
    {
        p[i] = new int[i];
        for (int j = 0; j < n; j++)
        {
            cin >> p[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        delete[] p[i];
    }
    delete[] p;
}