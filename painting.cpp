#include "bits/stdc++.h"
using namespace std;

int main()
{
	long long int i, j, n, a, b, c, d, a1, b1, c1, d1, count =0;
	cin>>n>>a>>b>>c>>d;


	a1 = a+b;
	b1 = b+d;
	c1 = c+d;
	d1 = a+c;

	int m1 = max(max(c1, d1), max(a1, b1));

	int m2 = min(min(a1, b1), min(c1, d1));

	count = (n - (m1 - m2)) * n;

	if(count < 0)
		count = 0;

	cout<<count<<"\n";
}