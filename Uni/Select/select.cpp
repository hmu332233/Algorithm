#include <iostream>

using namespace std;

int times = 0;

int select(int arr[], int p, int r, int i);
int partition(int arr[], int p, int r );
int main()
{
    int n;
    int k;

    cin >> n;
    cin >> k;
   int arr[n];

   int i;
   for( i = 0 ; i < n ; i++)
   {
        cin>>arr[i];
   }

   select(arr,0,n-1,k);

   cout << times;
}

int select(int arr[], int p, int r, int i)
{
    if( p == r ) return arr[p];
    int q = partition(arr,p,r);


    int k = q - p + 1; // k 기준원소가 전체에서 k번째 작은 원소이다

    if( i < k ) return select(arr,p,q-1,i);//왼쪽
    else if( i > k ) return select(arr,q+1,r,i-k);//오른쪽
    else return arr[q];

}

int partition(int arr[], int p, int r )
{
    int tmp;


    int criterion = arr[r]; //기준원소
    int i = p-1; //왼쪽시작점

    //작으면 왼쪽 크면 오른쪽
    for( int j = p ; j <= r-1 ; j++ )
    {
        if(arr[j] < criterion )
        {
            tmp = arr[++i];
            arr[i] = arr[j];
            arr[j] = tmp;

            times++;
        }
    }

    int q = i+1;

    tmp = arr[q];
    arr[q] = arr[r];
    arr[r] = tmp;
    times++;

    return q;
}
