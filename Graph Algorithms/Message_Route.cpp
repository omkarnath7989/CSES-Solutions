#include<iostream>
#include<vector>
#include<queue>
typedef long long ll;
using namespace std;


int main()
{
    int n , m ; 

    cin >> n >> m; 

    vector<int>adj[n+1] ; 

    for( int i = 0 ; i < m ; i++){
        int x , y ; 
        cin >> x >> y ; 
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool> vis(n+1, false);
    vector<int> bt(n+1, -1), dis(n+1, -1);

    queue<int>q;  
    q.push(1); 
    vis[1] = true ; 
    dis[1] = 1 ; 

    while(!q.empty()){

        int node = q.front() ; 
        q.pop() ; 

        if( node == n)
        break;

        for( int x : adj[node]){
            if(!vis[x]){
            dis[x] = 1 + dis[node] ; 
            vis[x] = true ; 
            bt[x] = node ; 
            q.push(x) ;
            } 
        }
    }

    if(!vis[n]){
        cout<<"IMPOSSIBLE";
        return 0 ; 
    }

    cout << dis[n] << endl;

    vector<int>ans(dis[n]) ; 

    int t = n ; 
    ans[dis[n]-1] = n ; 

    for( int i = dis[n]-1 ; i >= 0 ; i-- ){
        ans[i] = t ;
        t = bt[t] ; 
    } 

    for( int i = 0 ; i < dis[n] ; i++)
    cout<<ans[i]<<" ";

    return 0 ;

} 