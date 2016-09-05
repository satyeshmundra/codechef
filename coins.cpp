#include "bits/stdc++.h"

using namespace std;

long long int a[1000001] = {0};

long long int calc(long long int n)
{
	long long int val = 0;
	if(n == 0)
		return 0;
	if(n<1000001 && a[n]!= 0)
		return a[n];
	else
	{
		val = calc(n/2) + calc(n/3) + calc(n/4);
		if(val < n)
			val = n;
		if(n<1000001)
			a[n] = val;
		return val;

	}

}

int main()
{

	long long int n, t, i;
	//cin>>n;
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	while(scanf("%lld",&n)!=EOF)
	{
		//vector<long long int> v;
		//v.push_back(0);
		//v.push_back(1);


		
		// for(i = 2; i<=n/2; i++)
		// {
		// 	if(i >= v.at(i/2) + v.at(i/3) + v.at(i/4))
		// 	{
		// 		v.push_back(i);
		// 	}
		// 	else
		// 	{
		// 		v.push_back(v.at(i/2) + v.at(i/3) + v.at(i/4));
		// 	}
		// }
		// if(n >= v.at(n/2) + v.at(n/3) + v.at(n/4))
		// {
		// 	cout<<n<<"\n";
		// }
		// else
		// {
		// 	cout<<v.at(n/2) + v.at(n/3) + v.at(n/4)<<"\n";
		// }
	
		t = calc(n);
		cout<<t<<"\n";



	}
}	