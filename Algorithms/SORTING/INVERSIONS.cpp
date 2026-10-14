
//counting inversions using mergesort

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAX = 1000001;
int temp[MAX];

ll merge(int left[], int nleft, int right[], int nright, int c[])
{

    //merge 2 sorted arrays left & right into c
    ll ans = 0;
    int i = 0, j = 0, k = 0;

    while(i < nleft && j < nright)
    {
        while(left[i] <= right[j] && i < nleft) c[k++] = left[i++];

        while(left[i] > right[j] && j < nright)
        {
            //case of inversions
             c[k++] = right[j++];
             ans += (nleft-i);
        }
    }

    while(i < nleft) c[k++] = left[i++];
    while(j < nright) c[k++] = right[j++];

    return ans;

}

ll mergesort(int a[], int n)
{

    if(n == 1) return 0;

    int ans = 0;
    int mid = n/2;

    ans += mergesort(a, mid);
    ans += mergesort(a+mid, n-mid);
    ans += merge(a, mid, a+mid, n-mid, temp);

    for(int i = 0; i < n; ++i) a[i] = temp[i];
    return ans;

}

int main()
{

    int n;
    cin>>n;

    int a[n];
    for(int i = 0; i < n; ++i)
        cin>>a[i];

    cout<<"Inversions = "<<mergesort(a,n)<<endl;

    return 0;

}










