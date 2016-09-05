#include "bits/stdc++.h"
using namespace std;

long long int a[10001];
long long int sum[10001];
int main()
{
	int n, t, j;
	cin>>t;
	for(int i = 1; i<=t; i++)//while(t--)
	{
		cin>>n;
		for (j = 0; j < n; ++j)
		{
			/* code */
			cin>>a[j];
		}
		sum[0] = 0;
		sum[1] = a[0];
		for(j=2;j<=n; j++)
		{
			sum[j] = max(sum[j-1], (a[j-1] + sum[j-2]));
		}
		cout<<"Case "<<i<<": "<<sum[n]<<"\n";

	}
}