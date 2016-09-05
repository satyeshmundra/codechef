#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	int n, i, m, x, y;
	long long int sum = 0, max = 0;
	int a[50000];
	cin>>n;
	for (i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cin>>m;
	while(m--)
	{
		sum = 0;
		cin>>x>>y;
		max = a[x-1];
		for(i=x-1; i<y; i++)
		{
			sum+=a[i];
			if(sum > max)
				max = sum;
			if(sum < 0)
				sum = 0;
		}

		cout<<sum<<"\n";
	}
		/* code */
	

	return 0;
}