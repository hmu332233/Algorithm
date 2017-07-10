#include <iostream>
#include <cmath>

using namespace std;

void basicRabinKarp(string A, string P, int d , int q);
int replaceNum( char a);
int mod(long long x, long long y);

int main()
{
	string A,P;

	cin >> A >> P;

	basicRabinKarp(A,P,26,113);


}

void basicRabinKarp(string A, string P, int d,int q)
{
	int n = A.size();
	int m = P.size();
	int p = 0;
	int a[1001] = {0};
	for( int i = 0 ; i < m ; i++ )
	{
		p = mod( d*p + replaceNum(P.at(i)) , q );
		a[0] = mod ( d*a[0] + replaceNum(A.at(i)) , q );
	}
	//a[1] = a[0];
	cout<< a[0] << " ";
	int result = 0;

	int b=1;
	for( int i = 0 ; i < m-1 ;i++)
	{
		b *= d;
	}
	b = mod(b,q);

	for(int i = 0 ; i < n - m + 1 ; i++ )
	{

		if( i != 0 ) a[i] = mod ( d*(a[i-1] - b*replaceNum(A.at(i-1))) + replaceNum(A.at(i+m-1)) , q );
		if( p == a[i] ){


			int sw = 0;
			for(int j = 0 ; j < m ; j++)
			{
				if( P.at(j) != A.at(i+j) ) sw = 1;
			}

			if( sw == 0 ) result++;
		}

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
		case 'k':
			return 10;
		break;
		case 'l':
			return 11;
		break;
		case 'm':
			return 12;
		break;
		case 'n':
			return 13;
		break;
		case 'o':
			return 14;
		break;
		case 'p':
			return 15;
		break;
		case 'q':
			return 16;
		break;
		case 'r':
			return 17;
		break;
		case 's':
			return 18;
		break;
		case 't':
			return 19;
		break;
		case 'u':
			return 20;
		break;
		case 'v':
			return 21;
		break;
		case 'w':
			return 22;
		break;
		case 'x':
			return 23;
		break;
		case 'y':
			return 24;
		break;
		case 'z':
			return 25;
		break;


	}


}

int mod(long long x, long long y)
	{
    	return (((x%y)+y)%y);
	}
