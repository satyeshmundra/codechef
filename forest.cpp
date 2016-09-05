#include "bits/stdc++.h"
using namespace std;

int main()
{
	long long int n, w, l, hi, ri, i, j, months, sum, mon =0, sumr = 0;
	vector<long long int> h, r, m;
	long long int max = std::numeric_limits<long long int>::max();

	months = 0;
	cin>>n>>w>>l;

	for (i = 0; i < n; ++i)
	{
		cin>>hi>>ri;
		h.push_back(hi);
		r.push_back(ri);
		m.push_back((long long int)ceil((l-hi)/ri));		
		/* code */
	}

	if(w < l)
	{
		cout<<max<<"\n";
		return 0;
	}

	sum = 0;
	// while(sum < l)
	// {
	// 	sum = 0;
	// 	for (i = 0; i < n; ++i)
	// 	{
	// 		if(h.at(i) + r.at(i) * mon >= l)
	// 		sum += h.at(i) + r.at(i) * mon;
	// 		/* code */
	// 	}
	// 	mon++;
	// }

	// months = mon -1;

	// for (i = sum+1; i <= w; ++i)
	// {
	// 	months++;
		
	// 		sum = 0;
	// 		for (j = 0; j < n; ++j)
	// 		{
	// 			if(h.at(j) + r.at(j) * months >= l)
	// 			sum += h.at(j) + r.at(j) * months;
	// 			/* code */
	// 		}
	// 	i = sum;
	// 	/* code */
	// }

	for (i = 1; i <= w; ++i)
	{
		//months++;
		
			sum += sumr;
			for (j = 0; j < h.size(); ++j)
			{
				if(h.at(j) + r.at(j) * months >= l)
				{

					sum += h.at(j) + r.at(j) * months;
					sumr+=r.at(j);
					h.erase(h.begin() + j);
					r.erase(r.begin() + j);
					j--;				
				}
				/* code */
			}
		i = sum;
		if(sum >= w)
			break;

		months++;
		/* code */
	}
	cout<<months<<"\n";



	return 0;

}