#include "bits/stdc++.h"
using namespace std;

int main()
{
	long long int a, b, c;
	cin>>a>>b>>c;

	if(c == 0)
	{
		if(b ==a)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	}	
	else if(c>0)
	{

		if(b >= a && (b-a)%c == 0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	else
	{
		if(b <= a && (b-a)%c == 0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}