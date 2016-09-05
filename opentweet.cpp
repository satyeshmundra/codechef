#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n,k , c=0;
	cin>>n>>k;
	string s;
	bool *val = new bool[n+1];

	for (int i = 0; i < n+1; ++i)
	{
		val[i] = false;
		/* code */
	}
	while(k--)
	{
		cin>>s;
		if(s.substr(0,5).compare("CLICK") != 0)
		{	
			c=0;
			for (int i = 0; i < n+1; ++i)
			{
				val[i] = false;
				/* code */
			}
		}
		else
		{
			int a;
			cin>>a;
			if(val[a] == true)
			{
				c--;
				val[a]=false;
			}
			else
			{
				c++;
				val[a] = true;
			}
		}
		cout<<c<<"\n";
	}
}