#include <iostream>
#include <cmath>

using namespace std;

int linearSelect(int arr[], int p, int r, int i);
int select(int arr[], int p, int r, int i);
int partition(int arr[], int p, int r );
int partitionByMedian(int arr[] ,int p,int r,int M);

int main()
{
    int n;
    int k;

    cin >> n;
    cin >> k;
   int arr[n+1];
   arr[0] = 0;

   int i;
   for( i = 1 ; i <= n ; i++)
   {
        cin>>arr[i];
   }

   linearSelect(arr,1,n,k);



}

int linearSelect(int arr[], int p, int r, int select_n)
{
    int numOfarray = r-p+1; //배열 범위의 갯수
    if( numOfarray <= 5 ) return select(arr,p,r,select_n);

    int ceil_n = ceil(((float)numOfarray)/5);

    int brr[ceil_n];//중앙값 담을 배열
    int arr_s = p; //임시 배열 시작점



    for(int brr_n = 0 ; brr_n < ceil_n ; brr_n++)
    {
        numOfarray = r-arr_s+1;
        if((numOfarray)<5)
        {
            if((numOfarray)==4) brr[brr_n] = select(arr,arr_s,r,2);
            else if((numOfarray)==3) brr[brr_n] = select(arr,arr_s,r,2);
            else if((numOfarray)==2) brr[brr_n] = select(arr,arr_s,r,1);
            else brr[brr_n] = select(arr,arr_s,r,1);

        }
        else
        {
            brr[brr_n] = select(arr,arr_s,arr_s+4,3);
            arr_s+=5;
        }
    }



    int M = linearSelect(brr,0,ceil_n-1,ceil(((float)ceil_n)/2));
    cout<<M<<endl;

    int q = partitionByMedian(arr,p,r,M);

    int k = q-p+1;

    if(select_n<k) return linearSelect(arr,p,q-1,select_n);//왼쪽
    else if(select_n>k) return linearSelect(arr,q+1,r,select_n-k); //오른쪽
    else return arr[q];
}

int partitionByMedian(int arr[] ,int p,int r,int M)
{
    for(int i = p ; i <= r ; i++)
    {
        if( arr[i] == M )
        {
            swap(arr[i],arr[r]);
            break;
        }
    }

    return partition(arr,p,r);
}
/*
int partitionByMedian(int arr[],int p, int r,int M)
{
   int i,j;
   for(j=p;j<=r;j++) if(M==arr[j]) i=j;

   swap(arr[i],arr[r]);

   return partition(arr,p,r);
}*/

/*
int select(int arr[], int p, int r, int i)
{
    if( p == r ) return arr[p];
    int q = partition(arr,p,r);


    int k = q - p + 1; // k 기준원소가 전체에서 k번째 작은 원소이다
    if( i < k ) select(arr,p,q-1,i);//왼쪽
    else if( i > k ) select(arr,q+1,r,i-k);//오른쪽
    else return arr[q];

}

int partition(int arr[], int p, int r )
{

    int criterion = arr[r]; //기준원소
    int i = p-1; //왼쪽시작점

    //작으면 왼쪽 크면 오른쪽
    for( int j = p ; j <= r-1 ; j++ )
    {
        if(arr[j] <= criterion )
        {
            swap(arr[++i],arr[j]);
        }
    }

    int q = i+1;

    swap(arr[q],arr[r]);

    return q;
}*/


int partition(int * arr,int p, int r){
   int x = arr[r];
   int i = p-1;
   int j;


   for(j=p;j<=r-1;j++){
      if(arr[j]<=x)swap(arr[++i],arr[j]);

   }

   swap(arr[i+1],arr[r]);
   return i+1;
}



int select(int *arr, int p,int r,int i){ // p..r에서 i번째를 찾음
   if(p==r) return arr[p];
   int q = partition(arr,p,r);
   int k = q-p+1;

   //printf("p : %d r : %d i : %d\n",p,r,i);
   //
/* 사용할 수 없는 시스템 콜(system)을 호출했습니다. */

   if(i<k) return select(arr,p,q-1,i);//왼쪽
   else if(i>k) return select(arr,q+1,r,i-k); //오른쪽
   else return arr[q];
}
