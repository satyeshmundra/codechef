#include "bits/stdc++.h"
using namespace std;

long long int C(int n, int r)
{

	if(r==0)
		return 1;
	if(n == r)
		return 1;
	else
		return C(n-1, r) + C(n-1, r-1);

}

int main()
{
	long long int i,t, n, sum, k;

	cin>>t;
	while(t--)
	{

		cin>>n>>k;
		sum = 1;
		// long long int *f = new long long int[n];
		// f[0] = 1;

		// for (int i = 1; i < n; ++i)
		// {
		// 	/* code */
		// 	f[i] = i * f[i-1];
		// }
		// cout<<"saty"<<f[k-1];
		// cout<<"saty"<<f[n-k];

		for(i=1; i<k; i++)
		{
			sum = sum * (n-k+i);
			sum/=i;
		}
		cout<<sum<<"\n";
		// cout<<(f[n-1]/(f[k-1]*f[n-k]))<<"\n";
		
	}
}