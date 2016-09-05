#include "bits/stdc++.h"
using namespace std;

//map<int, int> mp;
// void ways(int *ar, int *a , int i, int s, int n, int m)
// {
// 	//if(mp.find())
// 	i++;
// 	if(i == m)
// 	{
// 		a[s-1]++;
// 		return;
// 	}

// 	if(s+ar[i] <= n)
// 	{
// 		ways(ar, a, i, s+ar[i], n, m);
// 	}
// 	if(s-ar[i] >0)
// 	{
// 		ways(ar, a, i, s-ar[i], n, m);
// 	}

// }
int main()
{

	long long int t, n, m, s, i, j;
	cin>>t;
	
	while(t--)
	{

		cin>>n>>m>>s;
		long long int **a = new long long int*[m+1];
		for (i = 0; i < m+1; ++i)
		{
			/* code */
			a[i] = new long long int[n];
		}
		long long int *ar = new long long int[m];

		for (i = 0; i < m; ++i)
		{
			//cin>>val;
			cin>>ar[i];
			/* code */
		}
		

		for(i = 0; i<=m ; i++)
		{
			for(j=0; j<n; j++)
			{
				a[i][j] = 0;
			}
		}
		a[0][s-1] = 1;

		for(i = 1; i<=m ; i++)
		{
			for(j=0; j<n; j++)
			{
				if((j+ar[i-1]) < n )
				{
					if(a[i-1][j + ar[i-1]] > 0)
						a[i][j]+= a[i-1][j + ar[i-1]];
				}
				if((j - ar[i-1]) >=0)
				{
					if(a[i-1][j - ar[i-1]] > 0)
						a[i][j]+= a[i-1][j - ar[i-1]];
				}
				a[i][j] %= 1000000007;
			}
		}

		//ways(ar, a, -1, s, n, m);

		for (i = 0; i < n; ++i)
		{
			cout<<a[m][i]%1000000007<<" ";
			/* code */
		}
		cout<<"\n";

	}
	return 0;
}