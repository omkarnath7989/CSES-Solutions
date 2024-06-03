#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;
typedef pair<int, int> pr;
#define x first
#define y second

bool vis[1000][1000];
char c, rou[1000][1000], ans[1000000];
int sr, sc, er, ec, dist[1000][1000];
queue<pr> q;
int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, 1, -1};

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c;

            if (c == '#')
                vis[i][j] = true;
            if (c == 'A')
                sr = i, sc = j;
            if (c == 'B')
                er = i, ec = j;
        }
    }

    q.push({sr, sc});
    vis[sr][sc] = 1;

    int flag = false;

    while (!q.empty())
    {

        pr p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int a = p.x + row[i];
            int d = p.y + col[i];

            if (a < 0 || a >= n || d < 0 || d >= m || vis[a][d] == true)
                continue;

            if (i == 0)
                rou[a][d] = 'U';
            else if (i == 1)
                rou[a][d] = 'D';
            else if (i == 2)
                rou[a][d] = 'R';
            else
                rou[a][d] = 'L';

            q.push({a, d});
            dist[a][d] = 1 + dist[p.x][p.y];
            vis[a][d] = true;

            if (a == er && d == ec)
            {
                flag = true;
                break;
            }
        }

        if (flag)
            break;
    }

    if (!vis[er][ec])
        cout << "NO" << endl;
    else
    {

        cout << "YES" << endl;
        cout << dist[er][ec]<<endl;

        pr p = {er , ec } ; 

        for (int i = dist[er][ec]; i > 0 ; i--){
            char y = rou[p.x][p.y] ; 

            if(y=='U') p = { p.x+1 , p.y} ; 
            else if(y=='D') p = { p.x-1 , p.y } ; 
            else if(y=='R') p = { p.x , p.y-1 } ; 
            else p = { p.x , p.y+1 } ; 

            ans[i] = y ; 
        }

        for( int i = 1 ; i <= dist[er][ec] ; i++)
        cout<< ans[i] ; 
        
    }
}