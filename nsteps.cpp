#include "bits/stdc++.h"

using namespace std;

int main()
{

	long long int n, x, y;
	cin>>n;
	while(n--)
	{

		cin>>x>>y;

		if(x == y || x-y == 2)
		{
			if(x%2 )
			{
				if(x == y)
					cout<<(x-1)*2 + 1<<"\n";
				else
					cout<<(x-1)*2 - 1<<"\n";
			}
			else
			{
				if(x == y)
					cout<<x*2<<"\n";
				else
					cout<<(x*2) - 2<<"\n";
			}
		}
		else
		{
			cout<<"No Number\n";
		}
	}
	/* code */
	return 0;
}