#include <iostream>

using namespace std;


int matrix[3][101];
int peb[4][101];

int pebbleSum(int j,int p);

int main()
{
	
	//보드판 가로크기 
	int m;
	
	cin >> m;
	
	//초기화
	for(int i = 0 ; i < 4 ; i++)
		for(int j = 0 ; j < m ; j++)
		{
			peb[i][j] = -999;
		}
	
	
	for(int i = 0 ; i < 3 ; i++)
		for(int j = 0 ; j < m ; j++)
		{
			cin >> matrix[i][j];
		}

	
	int tmp;
	int max = -999;
	
	for(int p = 0 ; p < 4 ; p++)
	{
		tmp = pebbleSum(m-1,p);
		if( tmp > max) max = tmp;
	}
		
		
	cout << max;
	
	
}
/*
패턴 1 [0][x]
패턴 2 [1][x] 
패턴 3 [2][x]
패턴 4 [0][x] + [2][x]

matrixSum[i][p] = i번째의 패턴별 합. 

문제정의 : i번째 열이 패턴p로 놓일때의 최고 점수 
1. pebbleSum이 이미 있다고 가정
2. pebbleSum은 그보다 더 작은 문제만 풀 수있다
3. 가장 작은 문제는 내가 푼다

//----------------------------------------
3.가장 작은 문제?
	패턴 별 합산 

	첫번째 열일때 ( i == 0 )
		return matrixSum[1][p] 

2. 그보다 더 작은문제?
	i번째의 패턴p와 조합가능한 
	i-1번째의 패턴p 중 가장 큰 값 
	
	패턴 0 = 패턴 1,2
	패턴 1 = 패턴 0,2,3
	패턴 2 = 패턴 0,1 
	패턴 3 = 패턴 1 

*/
int pebbleSum(int j,int p)
{
	//다이나믹 처리부분 
	if( peb[p][j] != -999 ) return peb[p][j];
	
	//패턴별 합산
	int matrixSum[4];
	
	matrixSum[0] = matrix[0][j];
	matrixSum[1] = matrix[1][j];
	matrixSum[2] = matrix[2][j];
	matrixSum[3] = matrix[0][j] + matrix[2][j];
	

	int sum[4];
	int max;
	
	if( j == 0 ) return matrixSum[p];
	else
	{
		for(int i = 0 ; i < 4 ; i++)
			sum[i] = pebbleSum(j-1,i);
			

		if( p == 0 ) max = sum[1] > sum[2] ? sum[1] : sum[2];
		else if( p == 1 )
		{
			int tmp;
			
			tmp = sum[0] > sum[2] ? sum[0] : sum[2];
			
			max = tmp > sum[3] ? tmp : sum[3];
		}
		else if( p == 2 ) max = sum[0] > sum[1] ? sum[0] : sum[1];
		else max = sum[1];
	}
	
	peb[p][j] = max + matrixSum[p];
	return peb[p][j];
}
