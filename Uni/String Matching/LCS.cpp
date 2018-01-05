#include <iostream>

using namespace std;

int LCS ( string x, string y);

int LCS_max[100][100];

int main()
{
	string x,y;
	
	cin >> x >> y;

	cout << LCS(x,y);
}

/*

문제 정의 : 문자열 x 문자열 y 공통된 문자열 중 가장 긴거


1. LCS 함수가 이미 있다고 가정 
2. LCS는 자신보다 더 작은 문제를 풀어준다
3. 가장 작은 문제는 내가 푼다

//------------------------------------


3. 가장 작은 문제?
	비교할 문자열이 한개라도 0이 되었을때
	 x.size() == 0 || y.size() ==0 이면 return 0; 
	 
	 
이때 
	x의 마지막 문자열
	y의 마지막 문자열 
	
	같으면 return LCS(  x.substr(0,test.size()-2) , y.substr(0,test.size()-2)  ) + 1;
	x,y 보다 1길이 줄어든 문자열의 LCS보다 1크다
	
	다르면 return
	LCS(  x.substr(0,test.size()-1) , y.substr(0,test.size()-2)  ) 
	LCS(  x.substr(0,test.size()-2) , y.substr(0,test.size()-1)  ) 
	둘 중 큰거  

자 
*/

int LCS ( string x, string y)
{
	//다이나믹 처리 
	if( LCS_max[x.size()][y.size()] != 0 ) return LCS_max[x.size()][y.size()];
	
	
	if( x.size() == 0 || y.size() == 0 ) return 0;
	
	//마지막 문자 
	char last_x = x.at( x.size()-1 );
	char last_y = y.at( y.size()-1 );
	
//	cout << "현재 문자열 " << endl << x << endl << y << endl;
	
	if( last_x == last_y )
	{
	//	cout << "1증가";
		LCS_max[x.size()][y.size()] = LCS(  x.substr(0,x.size()-1) , y.substr(0,y.size()-1)  ) + 1;
	
		return LCS_max[x.size()][y.size()];
	} 
	else
	{
		int xDown = LCS(  x.substr(0,x.size()-1) , y.substr(0,y.size())  );
		int yDown = LCS(  x.substr(0,x.size()) , y.substr(0,y.size()-1)  );
		
		LCS_max[x.size()][y.size()] = xDown > yDown ? xDown : yDown;
			
		return LCS_max[x.size()][y.size()];
	}
}