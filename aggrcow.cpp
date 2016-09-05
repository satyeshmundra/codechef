#include "bits/stdc++.h"
using namespace std;

int main()
{

	long long int t, n, c, i, low, high, mid, flag;
	vector<long long int>::iterator e;
	cin>>t;
	while(t--)
	{
		cin>>n>>c;
		vector<long long int> x;

		for (i = 0; i < n; ++i)
		{
			cin>>low;
			/* code */
			x.push_back(low);

		}
		sort(x.begin(), x.end());

		low = x.at(0);
		high = x.at(n-1);

		while(high>low)
		{
			//cout<<"a\n";
			mid = low + (high-low+1)/2;
			e = x.begin();
			flag = 0;
			for(i = 1; i<c; i++)
			{
				e = lower_bound(e, x.end(), *(e) + mid);
				if((e - x.end()) == 0 && *x.end() < *(e) + mid)
				{
					flag = 1;
					break;
				}
			}

			if (flag == 1)
			{
				high = mid-1;
				//cout<<"B\n";
				/* code */
			}
			else
			{
				low = mid;
			}
		}

		cout<<low<<"\n";

	}

}