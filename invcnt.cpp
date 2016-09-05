#include "bits/stdc++.h"

#define lli long long int
using namespace std;
long long int count;

void merge(vector<lli> &a, lli l, lli mid, lli r)
{
	lli i, j;
	vector<lli> b;
	for(i = l, j = mid+1; i<=mid && j<=r;)
	{
		if(a.at(i) > a.at(j))
		{
			::count+=(mid - i+1);
			//cout<<"saty "<<a.at(i)<<" "<<a.at(j)<<"\n";
			b.push_back(a.at(j));
			j++;
		}
		else
		{
			b.push_back(a.at(i));
			i++;
		}
	}

	for(; i<=mid; i++)
	{
		b.push_back(a.at(i));
	}

	for(; j<=r; j++)
	{
		b.push_back(a.at(j));
	}
	
	for(i = l,j=0; i<=r; i++, j++)
	{
		a.at(i) = b.at(j);
		//cout<<a.at(i)<<" ";
	}
	
}

void mergesort(vector<lli> &a, lli l, lli r)
{
	if(l == r)
		return;
	lli mid = l + (r-l)/2;
	mergesort(a, l, mid);
	mergesort(a, mid+1, r);
	merge(a, l, mid, r);

}
int main(int argc, char const *argv[])
{

	lli n, t, ar, i, j;//, count;
	vector<lli> a;

	cin>>t;
	while(t--)
	{
		cin>>n;
		::count = 0;
		for (i = 0; i < n; ++i)
		{
			cin>>ar;
			a.push_back(ar);
			/* code */
		}


		mergesort(a, 0, n-1);
		// for(i = 0; i < n; i++)
		// {
		// 	for(j = i+1; j < n; j++)
		// 	{
		// 		if(ar.at(i) > ar.at(j))
		// 		{
		// 			count++;
		// 		}
		// 	}
		// }

		cout<<::count<<"\n";
		// for (i = 0; i < a.size(); ++i)
		// {
		// 	cout<<a.at(i)<<"\n";	 
		// 	/* code */
		// }
		a.clear();

	}

	return 0;
}