#include "bits/stdc++.h"
using namespace std;
int ar[100001] = {0};
vector<int> prime;
int main()
{
	long long int t, i, j, a, b, flag;

	ar[0] = ar[1] = 1;
	for(i=2; i<100001; i++)
	{
		if(ar[i] == 0)
		{
			j=2;
			prime.push_back(i);
			while(i*j < 100001)
			{
				ar[i*j] = 1;
				j++;
			}
		}
	}
	cin>>t;

	while(t--)
	{

		cin>>a>>b;
		// long long int *v = new long long int[b-a+1];
		// for (i = 0; i <= b-a+1; ++i)
		// {
		// 	v[i] = 0;
		// 	/* code */
		// }

		// if(a <=2 && b>=2)
		// {
		// 	cout<<2<<"\n";
		// 	a=3;
		// }

		// if(a%2 == 0)
		// 	a++;

		// for(i=3; i<=b; i+=2)
		// {
		// 	//flag = 0;
		// 	if(i>=a)
		// 	{
		// 		if(v[i-a] == 0)
		// 		{
		// 			cout<<i<<"\n";
		// 		}
					
		// 	}

		// 	j=2;

		// 	while((i*j) <= b && (i*j) >=a)
		// 	{
		// 		v[(i*j)-a] = 1;
		// 		j++;
		// 	}
		// }
		// cout<<"\n";
		//cout<<prime.size()<<"\n";
		if(a <= 2)
			cout<<2<<"\n";
		if(b<100001)
		{
			if(a%2 == 0)
				a++;
			for(i = a; i<=b; i+=2)
			{
				if(ar[i] == 0)
					cout<<i<<"\n";
			}
		}
		else 
		{
			if(a%2 == 0)
				a++;
			for(i=a; i<=100000; i+=2)
			{
				if(ar[i] == 0)
					cout<<i<<"\n";
			}
			for(; i<=b; i+=2)
			{
				flag = 0;
				for(j=0; prime.at(j)<=sqrt(i); j++)
				{
					if(i%(prime.at(j)) == 0)
					{
						flag = 1;
						break;
					}
					
				}
				if(flag == 0)
					cout<<i<<"\n";
			}
		}
	cout<<"\n";
	}
}