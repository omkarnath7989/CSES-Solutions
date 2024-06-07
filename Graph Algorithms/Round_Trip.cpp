#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;

int kr ; 

bool dfs( int ind , int prev , vector<int>adj[] , vector<int>&ds , vector<bool>&vis){

    ds.push_back(ind);
    vis[ind] = 1 ; 

    for( auto x : adj[ind]){
        if(!vis[x]){
          if(dfs( x , ind , adj , ds , vis)) 
          return true ;
        }
        else{
            if( x != prev){
                kr = x ; 
                ds.push_back(x); 
                return true ; 
            }
        }
    }

    ds.pop_back() ; 

    return false ; 
}

int main()
{
    int n , m ; 

    cin >> n >> m ; 

    vector<int>adj[n+1] ; 

    for( int i = 1 ; i <= m ; i++){
        int x , y ; 
        cin >> x >> y ; 
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int>ds; 
    vector<bool>vis(n+1 , false );

    bool k = false ; 

    for( int i = 1 ; i <= n ; i++){
        if(!vis[i]){
             k = dfs(i , -1 , adj , ds , vis ) ; 

            if(k == true )
            break;
        }
    }
    
    if(k){

        bool fg = false ;  
        vector<int>ad; 

        for( auto x : ds ){
            if(fg || x == kr ){
                fg = true ; 
                ad.push_back(x);
            }
        }

        cout<<ad.size()<<endl;
        for(auto x : ad ){
         cout << x << " " ; 
        }  
    }
    else{
        cout <<"IMPOSSIBLE" ; 
    }
    return 0 ;

} 