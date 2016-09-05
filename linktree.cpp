#include "bits/stdc++.h"
using namespace std;

int main()
{
	long long int flag=0, l, r, k, i, n, m;
	cin>>l>>r>>k;

	m = ceil(log(l)/log(k));
	n = log(r)/log(k)+0.00000001;

	//cout<<k<<" saty "<<(long long int)ceil((pow((long long int)k, 2)))<<"\n";
	for(i = m; i <= n; i++)
	{
		if(ceil((powl(k, i))) <= r && ceil((powl(k, i))) >= l)
		{
			flag =1;
			cout<<(long long int)ceil((powl((long long int)k, (int)i)))<<" ";
		}
	}


	if(flag == 0)
	{
		cout<<-1;
	}

//cout<<(long long int)powl(999999990LL, 2LL);
}