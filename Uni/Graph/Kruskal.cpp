#include <iostream>
#include <algorithm>

using namespace std;


int matrix[101][101];
int visited[101];
int weight[101][101];


struct Node{

    Node* parent;
    int x;

};

Node* make_Set( int x );

Node* union_( Node* set_x, Node* set_y );

Node* find_Set( Node* set );



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



    int x,y,w;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> x >> y >> w;

        matrix[x-1][y-1] = 1;
        matrix[y-1][x-1] = 1;

        weight[x-1][y-1] = w;
        weight[y-1][x-1] = w;

    }

    /*
    for(int i = 0 ; i < n ; i++)
    {
        for( int j = 0 ; j < n ; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for(int i = 0 ; i < n ; i++)
    {
        for( int j = 0 ; j < n ; j++)
        {
            cout << weight[i][j] << " ";
        }
        cout << endl;
    }*/

    int A[m];
    Node* node[n];
    for(int i = 0 ; i < n ; i++)
    {
        node[i] = make_Set( i );
    }

    int a = 0;

    for(int i = 0 ; i < n ; i++)
        for( int j = i ; j < n ; j++)
        {
            if( weight[i][j] != 0 ) A[a++] = weight[i][j];
        }


    sort(A , A + m);

    int sum = 0;
    int t = -1;
    while( 1 )
    {
        t++;
        //나중에 바꾸기 최소비용 u v 찾는건데 미리 저장해두고 써야할듯
        for( int i = 0 ; i < n ; i++)
        {
            for( int j = 0 ; j < n ; j++)
            {
                if( A[t] == weight[i][j] )
                {
                    if( find_Set( node[i] ) != find_Set( node[j] ) )
                    {
                        sum += A[t];

                        cout << A[t] << " ";

                        union_( node[i] , node[j] );
                    }
                }
            }

        }


        if( t == n) break;
    }


    cout << sum;




}


Node* make_Set( int x )
{
    Node* node = new Node();
    node->parent = node;
    node->x = x;

    return node;
}

Node* union_( Node* set_x, Node* set_y )
{
    Node* set = find_Set(set_x);
    set->parent = find_Set(set_y);
}

Node* find_Set( Node* set )
{
    if( set == set->parent ) return set;
    else find_Set( set->parent );
}
