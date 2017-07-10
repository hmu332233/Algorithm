#include <iostream>

using namespace std;

void naiveMatching(string A, string P);
bool isMatching(string A, string P, int k);
//---KMP
void preprocessing(int kmp[], string P);
void KMP(string A, string P, int kmp[]);
int a;

int main()
{
    a = 0;

    string A;
    string P;

    cin >> A >> P;

    A = "x" + A;
    P = "x" + P;


    int kmp[P.length()+1];
	KMP(A,P,kmp);


}

void KMP(string A, string P, int kmp[])
{
	preprocessing(kmp,P);
	int i = 1;
	int j = 1;
	/*
	for( int i = 1 ; i <= P.length() ; i++)
	{
		cout << kmp[i] << " ";
	}*/

	int n = A.length();
	int m = P.length();

	int count = 0;
	int sw = 0;

	while( i < n )
	{
		count++;
		/*
		cout << "A : " << A.at(i) << endl;
		cout << "P : " << P.at(j) << endl << endl;*/

		if( j == 0 || A.at(i)==P.at(j) )
		{
			i++;
			j++;
		}
		else
		{
			j = kmp[j];
		}

		if( j == m)
		{
			sw = 1;
			//여기가 매칭 완료된 부분 i-m부터 i가지가 P임
			//cout << i-m+1 << " 여기서 매칭됨" << endl;
			cout << count << endl;
			j = kmp[j];
		}

	}

	if(sw == 0) cout << "fail";
}


void preprocessing(int kmp[], string P)
{
	for(int i = 0 ; i<=P.length() ; i++)
		kmp[i] = 0;

	int j = 1;
	int k = 0;

	while(j<P.length())
	{
		if( k == 0 || P.at(j) == P.at(k) )
		{
			j++;
			k++;
			kmp[j] = k;
		}
		else
		{
			k = kmp[k];
		}
	}
}
