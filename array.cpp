#include "bits/stdc++.h"
using namespace std;
long long int ar[100001];
long long int inv[100001];

long long int power(long long int a, long long int p)
{
	
	if(p == 0)
		return 1;
	
		long long int x = power(a, p/2);
		x = (x*x) % 1000000007;
		if(p % 2 == 0)
			return x;
		else
			return (x*a) % 1000000007;
}
long long int inverse(long long int a)
{
	return power(a, 1000000005)%1000000007;
}

int main()
{
	memset(ar, 0, sizeof(ar));
	memset(ar, 0, sizeof(ar));
	
	long long int n, t, k, i, j, a, c, sum =0, n1;//, p5, p10;
	//vector<<long long int> v;
	cin>>t;
	ar[0] = ar[1] = 1;
	//cout<<"ar = \n";
	for (i = 2; i <= 100000; ++i)
	{
		ar[i] = i * ar[i-1];
		ar[i] = ar[i] % 1000000007;
		/* code */
	}
	for (i = 0; i <= 100000; ++i)
	{
		inv[i] = inverse(ar[i]) % 1000000007;
		/* code */
	}
	
	while(t--)
	{
		sum = 0;
		cin>>n>>k;
		n1 = n;
		for (i = 0; i < n; ++i)
		{
			//a = 1;
			cin>>a;
			if(a == 0)
				n1--;
			/* code */
		}
		if(n != n1)
			n = n1+1;
		
		// for (i = 0; i <= n; ++i)
		// {
		// 	cout<<ar[i]<<" ";
		// 	/* code */
		// }
		// cout<<"\n";
		
		if(k%2 == 0)
		{
			c=1;
			sum = c;
			for (i = 2; i <= min(n,k); i+=2)
				{ 
					a = inv[i];
					n1 = inv[n-i];
					c = (a*n1) % 1000000007;
					c = (c * ar[n]) % 1000000007;
					//c = ar[n] * ((inverse(ar[n-i]) * inverse(ar[i])) % 1000000007);//(ar[i] % 1000000007+ ar[i-1] % 1000000007) % 1000000007;
					c = c % 1000000007;//
					sum = sum + c;
					sum = sum % 1000000007;
					/* code */
				}	
		}
		else
		{
			c=n;
			sum = c;
			for (i = 3; i <= min(n,k); i+=2)
				{
					a = inv[i];
					n1 = inv[n-i];
					c = (a*n1) % 1000000007;
					c = (c * ar[n]) % 1000000007;
					//c = ar[n] * ((inverse(ar[n-i]) * inverse(ar[i])) % 1000000007);//(ar[i] % 1000000007+ ar[i-1] % 1000000007) % 1000000007;
					c=c%1000000007;//c = (ar[i] % 1000000007+ ar[i-1] % 1000000007) % 1000000007;
					sum = sum + c;
					sum = sum % 1000000007;
					/* code */
				}
		}
		cout<<(sum % 1000000007)<<"\n";
	
	}
	return 0;
}