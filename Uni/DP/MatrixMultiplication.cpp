#include <iostream>

#define COL 0 	//행(가로) 
#define ROW 1	//열(세로) 

using namespace std;

int A[101][2];
int chainMin[101][101];

int matrixChain(int i, int j);

int main()
{
	int n;
	
	cin >> n;
	
	for(int i = 0 ; i < n ; i++)
	{
		cin >> A[i][COL] >> A[i][ROW];
	}
	
	cout << matrixChain(0,n-1);
	
}

/*
문제정의 : 행렬 Ai 부터 Aj 까지의 최소 연산 횟수
 
1. matrixChain가 이미있음
2. matrixChain는 자신보다 더 작은문제를 해결해줌
3. 가장 작은 문제는 내가 푼다
//--------------------
3.가장 작은 문제?
	n번째부터 n번째까지 일때 즉 자기자신부터 자기자신일때
	i==j 	return 0
	
2.자신보다 작은문제?
	i부터 j까지 보다 작은문제?
	임의의 k 
	i부터 k까지
	k-1부터 j가 작은문제
	
	임의의 k는 연산횟수가 제일 작은 값이여야함
	
	k?를 어떻게 구하지
	그러네 k를 구하는게아니라 k를 반복문으로 돌리고 그중 작은걸 가져와야겠네 
	그리고 갈라진 나머지에 대해서 마저 연산하는거네
	실제 호출순서는 반대겠지만 
	
	
결국 i부터 j까지는 
i~k, k+1~j , 그리고 (Ai의 COL)*(Ak+1의 COL)*(Aj의 ROW) 를 더한것 (중앙이 Ak의 ROW여도 상관없음) 

*/

int matrixChain(int i, int j)
{
	//다이나믹 처리
	if( chainMin[i][j] != 0 ) return chainMin[i][j]; 
	
	
	
	if( i == j ) return 0;
	
	int min = 9999;
	int tmp;
	
	for(int k = i ; k < j ; k++)
	{	
		tmp = matrixChain(i,k) + matrixChain(k+1,j) + A[i][COL]*A[k+1][COL]*A[j][ROW];
		if( tmp < min)
		{
			min = tmp;
		} 
	} 
	
	chainMin[i][j] = min;
	return min;
}