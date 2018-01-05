#include <iostream>
#include <queue> 
 
using namespace std;
 
 
int matrix[10000][10000];
int color[10000];
int visited[10000];
 
bool valid(int i,int c, int n);

bool kColoring(int i ,int c, int k, int n);

int main()
{
    int n, m, k;
     
    cin >> n >> m >> k;
     
    //초기화 
    for(int i = 0 ; i < n ; i++)
    {
        for( int j = 0 ; j < n ; j++)
        {
            matrix[i][j] = 0;
        }
        visited[i] = 0;
        color[i] = 0;
    }

     
    int x,y;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> x >> y;
         
        matrix[x-1][y-1] = 1;
        matrix[y-1][x-1] = 1;         
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
    */
    /*
    color[1] = 1;
    
    if( valid(1,1,n) ) cout << "true";
    else cout << "false";
    
   */
    
    if( kColoring(0,1,k,n) )
    	cout << "possible";
    else 
    	cout << "impossible";
}

bool valid(int i,int c, int n) 
{ 

	for( int j = 0 ; j < n ; j++)
	{
		if(matrix[i][j] == 1 && color[j] == c) return false;
	}

/*
	for(int j = 0 ; j < i-1 ; j++)
	{
		//나랑 연결 되어있는데 색이 겹치면 false, 그런 애들 없으면 true 
		if(matrix[i][j] == 1 && color[j] == c) return false;
	
	}*/

	
	return true;
} 

int sw = 0;

bool kColoring(int i ,int c, int k, int n) 
{ 
	bool result = false;
	int d=1;
	
	if( sw == 1 ) return false; 

	cout << "(" << i+1 << ", " << c <<")" << endl;

	if( valid(i,c,n) )
	{
		//cout<<"됨" << endl;
		color[i] = c;
		//마지막 
		if( i == n - 1 ) return true;
		else
		{
			result = false;
			d = 1;	//color
			while( result == false && d <= k)	// k는 색의  수 
			{
				result = kColoring(i+1,d,k,n);
				d++;	//다음 색
			}
		} 
		return result;
	} 
	else
	{
		if(  i == n - 1 && c == k) sw = 1;
		
		return false;
	} 
} 
