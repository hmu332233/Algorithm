#include <iostream>

using namespace std;


int matrixPath(int i, int j);
int matrix[101][101] = {0};
int matrix_sum[101][101];

int main()
{
	int n,m;
	
	cin >> n >> m;
	
	//int matrix[n][m];
	
	
	for( int i = 0 ; i < n ; i++)
		for( int j = 0 ; j < m ; j++)
		{
			cin >> matrix[i][j];
		}
		

		
	cout << matrixPath(n-1,m-1);


	return 0;
}

/*
오른쪽이나 아래쪽만 이동할 수 있다고 한다.
 
1. matrixPath() 가 이미 있다고 가정
2. matrixPath() 는 자신보다 저 작은 문제만을 해결할수있다
3. 가장 작은 문제는 스스로 푼다.
//--------------------------------------------
2. 자신보다 작은문제?
 자신의 왼쪽과 자신의 위쪽 중 작은거! 
 왼쪽 [i][j-1]
 위쪽 [i-1][j] 
 
 근데 제일 왼쪽이면(j==0) 왼쪽이 없으니까 return 위쪽꺼 [i-1][0] 
 제일 위쪽이면(i==0) 위쪽이 없으니까 return 왼쪽꺼  [0][j-1]
  
3. 가장 작은 문제는 뭐야 그럼
 가장 작은 문제는 첫번째에서 첫번째
 1,1 에서 1,1까지니까 배열[0][0]의 값이다 
 
 
 //--------------------- 

*/

//택시타고 가는데 가장 덜 걸리는 시간을 구하는 중 
int matrixPath(int i, int j)
{
	if( matrix_sum[i][j] != 0 ) return matrix_sum[i][j];
	
	
	if( i == 0 && j == 0 )
	{
		matrix_sum[0][0] = matrix[0][0];
		return matrix[0][0];
	} 
	//제일 위쪽이면 
	if( i == 0 )
	{
		matrix_sum[0][j] = matrix[0][j] + matrixPath(0,j-1);
		return matrix[0][j] + matrixPath(0,j-1); 
	} 
	//제일 왼쪽이면 
	else if( j == 0 )
	{
		matrix_sum[i][0] = matrix[i][0] + matrixPath(i-1,0); 
		return matrix[i][0] + matrixPath(i-1,0); 
	} 
	//걍 중앙에 있으면
	else 
	{
		int up = matrixPath(i-1,j);
		int left = matrixPath(i,j-1);
		
	  	matrix_sum[i][j] = matrix[i][j] + (up > left ? left : up);
		return matrix[i][j] + (up > left ? left : up);
	}
}

