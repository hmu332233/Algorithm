#include <iostream>
#include <cmath>

using namespace std;

void basicRabinKarp(string A, string P, int d);
int replaceNum( char a);

int main()
{
	string A,P;

	cin >> A >> P;

	basicRabinKarp(A,P,10);


}

void basicRabinKarp(string A, string P, int d)
{
	int n = A.size();
	int m = P.size();
	int p = 0;
	int a[1001] = {0};
	for( int i = 0 ; i < m ; i++ )
	{
		p = d*p + replaceNum(P.at(i));
		a[0] = d*a[0] + replaceNum(A.at(i));
	}


	int result = 0;
	//거듭제곱 함수 쓰면 에러래..
	int b=1;
	for( int i = 0 ; i < m-1 ;i++)
	{
		b *= d;
	}

	cout<< a[0] << " ";
	for(int i = 0 ; i < n - m + 1 ; i++ )
	{

		if( i != 0 ) a[i] = d*(a[i-1] - b*replaceNum(A.at(i-1))) + replaceNum(A.at(i+m-1));
		if( p == a[i] ) result++;

		if( i != n - m )cout << a[i] << " ";
	}

	cout << result;


}

int replaceNum( char a)
{
	switch (a)
	{
		case 'a':
			return 0;
		break;
		case 'b':
			return 1;
		break;
		case 'c':
			return 2;
		break;
		case 'd':
			return 3;
		break;
		case 'e':
			return 4;
		break;
		case 'f':
			return 5;
		break;
		case 'g':
			return 6;
		break;
		case 'h':
			return 7;
		break;
		case 'i':
			return 8;
		break;
		case 'j':
			return 9;
		break;

	}

}
