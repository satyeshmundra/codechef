#include "bits/stdc++.h"
using namespace std;
int sum[101][101] = {0};
int ar[101][101] = {0};
int main()
{

	int t, h, w, i, j, m;
	cin>>t;
	while(t--)
	{
		m = 0;
		memset(ar, 0, sizeof(ar));
		memset(sum, 0, sizeof(sum));
		cin>>h>>w;
		for(i = 1; i<=h;i++)
		{
			for(j=1; j<=w; j++)
			{
				cin>>ar[i][j];
				sum[i][j] = ar[i][j] + max(max(sum[i-1][j-1], sum[i-1][j]), max(sum[i-1][j], sum[i-1][j+1])); 
				if(sum[i][j] > m)
					m = sum[i][j];
			}
		}
		cout<<m<<"\n";


	}
}
