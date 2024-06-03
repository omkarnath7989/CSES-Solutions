#include <iostream>
#include <vector>
using namespace std;

bool isval(int i, int j, vector<vector<char> > &ds)
{

    if (ds[i][j] == '*')
        return false;

    int row = i;

    while (row >= 0)
    {
        if (ds[row][j] == 'Q')
            return false;

        row--;
    }

    int col = j;
    int row1 = i;

    while (row1 >= 0 && col >= 0)
    {
        if (ds[row1][col] == 'Q')
            return false;

        row1--;
        col--;
    }

    while (i >= 0 && j < 8)
    {
        if (ds[i][j] == 'Q')
            return false;

        i--;
        j++;
    }

    return true;
}

void f(int ind, vector<vector<char> > &ds, int &cnt){

    if (ind == 8)
    {
        cnt++;
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        if (isval(ind, i, ds))
        {
            ds[ind][i] = 'Q';
            f(ind + 1, ds, cnt);
            ds[ind][i] = '.';
        }
    }
}

int main()
{
    vector<vector<char> > ds(8, vector<char>(8));

    int cnt = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> ds[i][j];
        }
    }

    f(0, ds, cnt);
    cout << cnt;
    return 0;
}