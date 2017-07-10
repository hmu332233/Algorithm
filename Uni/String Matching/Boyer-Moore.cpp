#include <iostream>

using namespace std;

void computeJump(string P, int jump[]);
void BoyerMooreHorspool(string A,string P);
int returnJump(char c, string P, int jump[]);

int main()
{


    string A;
    string P;

    cin >> A >> P;
    
    /*

    int jump[P.length()+1];
	computeJump(P,jump);

	cout << endl;

	cout << returnJump('e',P,jump);
	*/
	BoyerMooreHorspool(A,P);

}


void BoyerMooreHorspool(string A,string P)
{
	int n = A.length();
	int m = P.length();

	int jump[P.length()+1];

   computeJump(P, jump);

   int count = 0;
   int result = 0;

   int i = 0;
   int j,k;
   while(i < n-m+1)
   {
      j = m-1;
	  k = i + m - 1; // 패턴만큼 끝부분 부터 비교
      while(j>=0 && P[j] == A[k])
	  {
         count++;
         j--;
		 k--;
      }

      if(j == -1)
      {
      	//A[i]자리에서 매칭된거임
      	result++;
	  }

      i = i + returnJump(A.at(i+m-1),P,jump);

   }
   //cout << endl;

   cout << count << " " << result;
}

void computeJump(string P, int jump[])
{
	int n = P.length();

	jump[n] = n;
	jump[n-1] = n;

	for(int i = 0 ; i < P.length()-1 ; i++ )
		jump[i] = --n;

	/*
	for(int i = 0 ; i <= P.length() ; i++ )
		cout << jump[i] << " ";*/
}

int returnJump(char c, string P, int jump[])
{
	 for(int i = P.length()-1 ; i >= 0 ; i--)
      {
      		if( P.at(i) == c )
      		{
      			return jump[i];
			}
	  }

	  return jump[P.length()];
}
