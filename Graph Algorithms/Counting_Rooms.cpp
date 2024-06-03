#include<iostream>
#include<vector>
#include<queue>
typedef long long ll;
using namespace std;


void bfs( int r , int c , vector<vector<int> >&vis , int n , int m ){

    queue<pair<int,int>>q ;

    q.push({r,c}) ; 
    vis[r][c] = 1 ; 

    vector<int>row = { 1,-1, 0 , 0 } ; 
    vector<int>col = { 0 , 0 , 1 , -1} ; 

    while (!q.empty())
    {
        int sr = q.front().first ; 
        int sc = q.front().second ; 
        q.pop();

        for( int i = 0 ; i < 4 ; i++){
            int a = sr + row[i] ; 
            int d = sc + col[i] ; 
            if( a < 0 || a >= n || d < 0 || d >= m || vis[a][d] == 1  )
            continue ; 

            vis[a][d] =1 ; 
            q.push({a,d}) ; 
        }
    }

}



int main()
{
    int row , col ; 

    cin >> row >> col ; 

    vector<vector<char> >plan(row , vector<char>(col )) ; 

    vector<vector<int> >vis( row , vector<int>(col , 0 )) ; 

    for( int i = 0 ; i < row ; i++ ){
        for( int j = 0 ; j < col ; j++){
            cin >> plan[i][j] ; 

            if( plan[i][j] == '#')
            vis[i][j] = 1 ; 
        }
    }
    
    int cnt = 0 ; 

    for( int i = 0 ; i < row ; i++ ){
        for( int j = 0 ; j < col ; j++){ 
            if(!vis[i][j]){
                cnt++ ; 
                bfs(i , j , vis , row , col  ) ; 
            }    
        }
    }

    cout << cnt  ;
    return 0 ;

}  