#include "bits/stdc++.h"

using namespace std;

int b[101];
int f[101];
int opt[101][501];
int sum[101][501];
void maxopt(int n, int B)
{
	for(int i = 0; i<=n; i++)
	{
		for(int j=0; j<=B; j++)
		{
			if(i == 0 || j == 0)
			{
				opt[i][j] = 0;
				sum[i][j] = 0;
			}
			else if(b[i-1] > j)
			{
				opt[i][j] = opt[i-1][j];
				sum[i][j] = sum[i-1][j];
			}
			else
			{
				if((f[i-1] + opt[i-1][j - b[i-1]]) > opt[i-1][j])
				{
					opt[i][j] = (f[i-1] + opt[i-1][j - b[i-1]]);
					sum[i][j] = b[i-1] + sum[i-1][j-b[i-1]]; 
				}
				else if((f[i-1] + opt[i-1][j - b[i-1]]) == opt[i-1][j])
				{
					if((b[i-1] + sum[i-1][j-b[i-1]]) < sum[i-1][j])
					{
						opt[i][j] = (f[i-1] + opt[i-1][j - b[i-1]]);
						sum[i][j] = b[i-1] + sum[i-1][j-b[i-1]]; 
					}
					else
					{
						opt[i][j] = opt[i-1][j];
						sum[i][j] = sum[i-1][j];
					}
				}
				else
				{
					opt[i][j] = opt[i-1][j];
					sum[i][j] = sum[i-1][j];
				}
			}
		}
	}
	cout<<sum[n][B]<<" "<<opt[n][B]<<"\n";
}

// int main()
// {
// 	int n, B;
// 	while(true)
// 	{
// 		cin>>B>>n;
// 		if(B == 0 && n == 0)
// 			break;
// 		for (int i = 0; i < n; ++i)
// 		{
// 			/* code */
// 			cin>>b[i]>>f[i];
// 		}

// 		maxopt(n, B);
// 	}
// }