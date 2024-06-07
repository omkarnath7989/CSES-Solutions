#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;
#define N 7  
bool vis[N+1][N+1];
int ans=0 ; 

bool coutofB( int x , int y ){

    return ( x >= 1 &&  x <= N && y >= 1 && y <= N ) ; 
}

void f(int i ,  int x , int y , string &s ){

    if( i == 48 || ( x == N && y == 1 ) ){
        ans += (i == 48 && ( x == N && y == 1 )) ; 
        return ;
    }

    if((!coutofB(x+1,y) || vis[x+1][y]) && (!coutofB(x-1,y)||vis[x-1][y]) )
      if( coutofB(x,y+1)&&coutofB(x,y-1)&&!vis[x][y+1] && !vis[x][y-1])
        return ; 

    if((!coutofB(x,y+1) || vis[x][y+1]) && (!coutofB(x,y-1)||vis[x][y-1]) )
      if( coutofB(x+1,y)&&coutofB(x-1,y)&&!vis[x+1][y] && !vis[x-1][y])
        return ; 

    vis[x][y] = true ; 

    if( s[i] =='?' || s[i] == 'U' )
     if( !vis[x-1][y] && coutofB(x-1,y) )
       f( i+1 , x-1 , y , s ) ; 

    if( s[i] =='?' || s[i] == 'D' )
     if( !vis[x+1][y] && coutofB(x+1,y) )
       f( i+1 , x+1 , y , s ) ; 

    if( s[i] =='?' || s[i] == 'R' )
     if( !vis[x][y+1] && coutofB(x,y+1) )
       f( i+1 , x , y+1 , s ) ; 

    if( s[i] =='?' || s[i] == 'L' )
     if( !vis[x][y-1] && coutofB(x,y-1) )
       f( i+1 , x , y-1 , s ) ; 

    vis[x][y] = false ; 
}


int main()
{
    string s ; 
    cin >> s ; 

    f(0 , 1 , 1 , s);

    cout << ans ; 
    return 0 ;

} 