#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n;
	cin>>n;
	long long int a,b,c, reva= 0, revb=0, revc;
	while(n--)
		{
	
			cin>>a>>b;
			reva = revb = revc = 0;
			while(a>0)
			{
				int r = a%10;
				reva = reva*10 + r;
				a=a/10;
			}
			while(b>0)
			{
				int r = b%10;
				revb = revb * 10 + r;
				b/=10;
			}
			c=reva+revb;
			while(c>0)
			{
				int r = c%10;
				revc = revc * 10 + r;
				c/=10;
			}
			cout<<revc<<"\n";
		}
}