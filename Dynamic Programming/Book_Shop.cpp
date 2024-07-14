#include <iostream>
#include <vector>
#include <climits>
typedef long long ll;
using namespace std;

int f(int ind, int x, vector<int> &pages, vector<int> &price, vector<vector<int> > &dp)
{

    if (x == 0)
        return 0;

    if (ind == 0)
    {
        if (price[0] <= x)
        {
            return pages[0];
        }
        else
        {
            return 0;
        }
    }

    if (dp[ind][x] != -1)
        return dp[ind][x];

    int t = 0;
    if (price[ind] <= x)
        t = pages[ind] + f(ind - 1, x - price[ind], pages, price, dp);

    int nt = f(ind - 1, x, pages, price, dp);

    return dp[ind][x] = max(nt, t);
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> price(n);
    vector<int> pages(n);

    for (int i = 0; i < n; i++)
        cin >> price[i];

    for (int i = 0; i < n; i++)
        cin >> pages[i];

    vector<vector<int> > dp(n, vector<int>(x + 1, 0));

    // cout << f( n-1 , x , pages , price, dp );

    for (int i = 0; i <= x; i++)
    {
        if (i >= price[0])
            dp[0][i] = pages[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int pr = 1; pr <= x; pr++)
        {

            int t = 0;
            if (price[ind] <= pr)
                t = pages[ind] + dp[ind - 1][pr - price[ind]];

            int nt = dp[ind - 1][pr];

            dp[ind][pr] = max(nt, t);
        }
    }

    cout << dp[n-1][x] ; 

    return 0;
}