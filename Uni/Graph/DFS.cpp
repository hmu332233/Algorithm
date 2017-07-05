#include <iostream>

using namespace std;


int matrix[101][101];
int visited[101];

int DFS( int n, int v );

int main()
{
    int n, m;

    cin >> n >> m;


    //초기화
    for(int i = 0 ; i < n ; i++)
    {
        for( int j = 0 ; j < n ; j++)
        {
            matrix[i][j] = 0;
        }
        visited[i] = 0;
    }



    int x,y;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> x >> y;

        matrix[x-1][y-1] = 1;
        matrix[y-1][x-1] = 1;
    }
    //출발 노드
    int s;

    cin >> s;
    /*
    for(int i = 0 ; i < n ; i++)
    {
        for( int j = 0 ; j < n ; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }*/

    //DFS
    DFS(n,s-1);

}

int DFS( int n ,int v )
{
    cout << v+1 << " ";

    visited[v] = 1;
    for( int i = 0 ; i < n ; i++)
        if( visited[i] == 0 && matrix[v][i] == 1 ) DFS(n,i);
}
