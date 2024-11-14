#include <bits/stdc++.h>
using namespace std;

int getMax(int A[],int n)
{
    int maxVal=A[0];
    for (int i=1;i<n;i++)
    {
        if (A[i]>maxVal)
        {
            maxVal=A[i];
        }
    }
    return maxVal;
}

void countSort(int A[],int n,int pos)
{
    int count[10]={0};
    int output[n];

    for (int i = 0; i<n;i++)
    {
        count[(A[i]/pos)%10]++;
    }

    for (int i=1;i<10;i++)
    {
        count[i]+=count[i-1];
    }

    for(int i=n-1; i>=0;i--)
    {
        output[count[(A[i]/pos)%10] - 1] = A[i];
        count[(A[i]/pos)%10]--;
    }

    for (int i=0;i<n;i++)
    {
        A[i]=output[i];
    }
}

void radixSort(int A[], int n)
{
    int maxVal = getMax(A, n);

    for (int pos = 1; maxVal / pos > 0; pos *= 10)
    {
        countSort(A, n, pos);
    }
}

int main()
{
    int n;
    cin >> n;
    int A[n];

    for (int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    radixSort(A, n);

    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
    }
    cout << endl;
    return 0;
}
