#include<iostream>
#include<vector>
#include<queue>
typedef long long ll;
using namespace std;
int c1 , c2  ;
bool vis[100001];

int main()
{
    int n , m ; 

    cin >> n >> m ; 

    vector<int>adj[n+1] ; 

    for( int i = 0 ; i < m ; i++){
        cin >> c1 >> c2  ; 

        adj[c1].push_back(c2) ; 
        adj[c2].push_back(c1) ; 
    }
    vector<int>path ; 
    int ans = 0 ; 
    for( int i = 1 ; i <= n ; i++ ){ 
        if(!vis[i]){
            ans++;
            path.push_back(i);
            queue<int>q; 
            q.push(i); 

            vis[i] = true ; 

            while (!q.empty())
            {
                int t = q.front() ; 
                q.pop() ; 

                for( int x : adj[t] ){
                    if(!vis[x]){
                        vis[x] = true ; 
                        q.push(x); 
                    }
                }
            }
        }
    }
    int x = ans-1 ;
    cout<< x <<endl ; 

    for( int i = 1 ; i < ans ; i++){
        cout<<path[i-1]<<" "<<path[i]<<endl ; 
    }

    return 0 ;

} 