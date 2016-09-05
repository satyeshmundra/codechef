#include "bits/stdc++.h"

using namespace std;

int main()
{

	long long int n, x;
	cin>>n;

	while(n!=0)
	{
		x = n * (n+1) * (2*n +1);
		x = x/6;

		cout<<x<<"\n";
		cin>>n;
	}
}