#include <iostream>
#include <queue>

using namespace std;


int matrix[101][101];
int visited[101];

int BFS( int n, int v );

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

    //BFS
    //BFS(n,s-1);

    queue<int> q;
    int st = s-1;

    visited[st] = 1;
    cout << s << " ";

    q.push(st);

    while( !q.empty() )
    {
        int u = q.front();
        q.pop();

        for(int i = 0 ; i < n ; i++)
        {
            if( visited[i] == 0 && matrix[u][i] == 1 )
            {
                visited[i] = 1;
                q.push(i);

                cout << i + 1 << " ";
            }
        }
    }




}
//잘못짯..
int BFS( int n ,int v )
{
    if( visited[v] == 0 )
    {
        cout << v+1 << " ";
        visited[v] = 1;
    }


    queue<int> q;

    for( int i = 0 ; i < n ; i++)
        if( visited[i] == 0 && matrix[v][i] == 1 )
        {
            cout << i + 1 << " ";
            visited[i] = 1;

            q.push(i);
        }


    while( !q.empty() ){
        BFS( n,q.front() );
        q.pop();
    }

}
