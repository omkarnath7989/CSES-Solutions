#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;

bool dfs( int c,int node ,vector<bool>&vis ,vector<int>adj[] , vector<int>&ans ){

    ans[node] = c ; 
    vis[node] = 1 ; 

    for( int x : adj[node] ){
        if(!vis[x]){
            if(!dfs(1-c , x , vis ,adj ,ans ))
            return false ; 
        }
        else{
            if(ans[node]==ans[x])
            return false ;
        }
    }

    return true ; 

}

int main()
{
    int n , m ; 

    cin >> n >> m ; 

    vector<int>adj[n+1]; 

    for( int i = 0 ; i < m ;i++){
        int x , y ; 
        cin >> x >> y ;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int>ans(n+1 , -1);
    vector<bool>vis(n+1,false);

    bool k = true ; 

    for( int i = 1 ; i <= n ; i++ ){
        if(!vis[i]){
           k = dfs( 0 , i , vis , adj , ans  ) ; 

            if(!k)
            break;
        }
    }

    if(!k)
    cout<<"IMPOSSIBLE";
    else
    for( int i = 1 ; i <= n ; i++)
    cout << ans[i]+1 <<" " ; 

    return 0 ;

} 