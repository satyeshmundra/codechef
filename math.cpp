#include "bits/stdc++.h"
using namespace std;

int main()
{
	long long int q, x, k, i, j, l, m;
	cin>>q;
	while(q--)
	{
		cin>>x>>k;
		int *f = new int[x];
		int **a = new int*[x+1];
		for(i=0; i<=x; i++)
		{
			a[i] = new int[k+1];
			bzero(a[i],4*(k+1));
		}

		i = 0;
		f[i] = 1;
		a[f[i]][1] = 1;
		while(f[i] <= x)
		{
			i++;
			if(i == 1)
			{
				f[i] = 2;
			}
			else
			{
				f[i] = f[i-1] + f[i-2];
			}
			if(f[i] <= x)
			{
				a[f[i]][1] = 1;
			}

		}

		// for(j=2; j<=x; j++)
		// 	{
		// 		for(l=1; l<=j/2; l++)
		// 		{
		// 			if(a[l][1] > 0 && a[j-l][1] > 0)
		// 			{
		// 				a[j][2] += a[l][1];
		// 			}
		// 		}
		// 	}
		
		for(i=2; i<=k; i++)
		{
			for(j=i; j<=x; j++)
			{
				for(l=i -1; l<=j/2; l++)
				{
					if(a[l][i-1] > 0 && a[j-l][1] > 0)
					{
						a[j][i] += a[l][i-1];
					}
				}
			}
		}

		for(i=0; i<=x; i++)
		{
			for(j=0; j<=k; j++)
			cout<<a[i][j]<<" ";
		cout<<"\n";
		}
		cout<<"saty\n";
		cout<<a[x][k]<<"\n";
	}
}