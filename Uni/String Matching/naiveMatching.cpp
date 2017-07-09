#include <iostream>

using namespace std;

void naiveMatching(string A, string P);
bool isMatching(string A, string P, int k);

int a;

int main()
{
    a = 0;

    string A;
    string P;
      
    cin >> A >> P;

    naiveMatching(A,P);

}

void naiveMatching(string A, string P)
{
    int n = A.length();
    int m = P.length();
    /*
    cout << "n : " << n << endl;
    cout << "m : " << m << endl;
    */
    int result = 0;

    for(int i = 0 ; i < n-m+1; i++)
    {
        if( isMatching(A,P,i) ) result++;
    }

    cout << a << " ";
    cout << result;
}

bool isMatching(string A, string P, int k)
{
   for(int j = 0 ; j < P.length() ; j++)
   {
        a++;
        if(P.at(j) != A.at(k++) ) return false;
   }
   return true;
}
