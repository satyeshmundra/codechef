#include "bits/stdc++.h"	


using namespace std;
//#define INT_MAX 10000000000;

int ar[1001][1001];
int sum[1001][1001] = {0};
int B[1001][1001] = {-1};
int C[1001][1001] = {-1};
long long int findsum(int i, int j, int a, int b)
{
	if(i==0 && j==0)
		return (sum[a-1][b-1]);
	if(i==0)
		return (sum[a-1][j+b-1] - sum[a-1][j-1]);
	if(j == 0)
		return (sum[i+a-1][b-1] - sum[i-1][b-1]);
	else
		return (sum[i+a-1][j+b-1] + sum[i-1][j-1] - sum[i-1][j+b-1] - sum[i+a-1][j-1]);
}
int main()
{
	long long int n,m,a,b,q,i,j, minsum, max, k, l, s;

	cin>>n>>m;
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			cin>>ar[i][j];
		}
	}

	for(i=0; i<n;i++)
	{
		s = 0;
		for(j=0;j<m;j++)
		{
			if(i>0)
				sum[i][j] = s + ar[i][j] + sum[i-1][j];
			else
				sum[i][j] = s + ar[i][j];
			s+= ar[i][j];
		}
	}

	cin>>q;
	while(q--)
	{
		max = -1;
		minsum = INT_MAX;
		// memset(B, -1, sizeof(B));
		// memset(C, -1, sizeof(C));
		cin>>a>>b;
		
		for(i=0; i<n; i++)
		{
			list<int> lt;
			for(j=0;j<m;j++)
			{
				while (!lt.empty() && lt.back() < ar[i][j])
    				lt.pop_back();

				lt.push_back(ar[i][j]);

				if(j>=b && ar[i][j-b] == lt.front() )
					lt.pop_front();

				if(j>= (b-1))
				{
					B[i][j-b+1] = lt.front(); 
				}
			}
		}
	
		for(i=0; i<m; i++)
		{
			list<int> lt;
			for(j=0;j<n;j++)
			{
				while (!lt.empty() && lt.back() < B[j][i])
    				lt.pop_back();

				lt.push_back(B[j][i]);

				if(j>=a && B[j-a][i] == lt.front() )
					lt.pop_front();

				if(j>= (a-1))
				{
					C[j-a+1][i] = lt.front(); 
				}
			}
		}

		for (i = 0; i <= n-a; ++i)
		{
			for(j=0 ; j<=m-b; j++)
			{
				max = C[i][j];
				s = a*b*max - findsum(i,j,a,b);
				if(s<minsum)
		 			minsum = s;
			}
		}
		
		cout<<minsum<<"\n";
	}
}