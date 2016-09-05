#include "bits/stdc++.h"

using namespace std;
long long int ar[500001];

long long int max(long long int a, long long int b)
{
	if (a>b)
	{
		return a;/* code */
	}
	else
		return b;
}

long long int min_binary_search(long long int low, long long int high, long long int k, long long int n)
{
	long long int sum = 0, mid;
	while(high > low)
	{
		sum = 0;
		mid = low + (high - low )/2;
		if(low == mid)
			mid++;
		for (int i = 0; i < n; ++i)
		{
			/* code */
			sum = sum + max(0, (mid -ar[i]));
		}
		if(sum <= k)
			low = mid ;
		else
			high = mid - 1;
	}
	//mid = low +(high - low )/2;
	return low;
}

long long int max_binary_search(long long int low, long long int high, long long int k, long long int n)
{
	long long int sum = 0, mid;
	while(high > low)
	{
		sum = 0;
		mid = low + (high - low )/2;
		for (int i = 0; i < n; ++i)
		{
			/* code */
			sum = sum + max(0, (ar[i] - mid));
		}
		if(sum > k)
			low = mid + 1;
		else
			high = mid ;
	}
	//mid = low +(high - low )/2;

	return low;
}

int main()
{
	long long int n, k, min_, max_=0, low, high;
	cin>>n>>k;
	for (int i = 0; i < n; ++i)
	{
		/* code */cin>>ar[i];
		if(max_ < ar[i])
			max_ = ar[i];
	}

	high = max_;
	low = 1;
	min_ = min_binary_search(low, high, k, n);
	//cout<<"min = "<<min_<<"\n";
	low = k;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		low-= max(0, (min_ - ar[i]));
		ar[i] = max(ar[i], min_);
	}
	for(int i=0 ; i<n ; i++)
		if(ar[i] == min_ and low){
			low--;
			ar[i]++;
		}

	for (int i = 0; i < n; ++i)
	{
		/* code */cout<<ar[i]<<" ";
	}
	cout<<"\n";
	low = 1;
	high = max_;
	max_ = max_binary_search(low, high, k, n);
	//cout<<"max = "<<max_<<"\n";
	low = k;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		low-= max(0, (ar[i] - max_));
		ar[i] = min(ar[i], max_);
	}
	for(int i=0 ; i<n ; i++)
		if(ar[i] == max_ and low){
			low--;
			ar[i]--;
		}

	max_ = min_ = ar[0];
	for (int i = 0; i < n; ++i)
	{
		/* code */
		if(ar[i] > max_)
			max_ = ar[i];
		if(ar[i] < min_)
			min_ = ar[i];
		cout<<ar[i]<<" ";
	}
	cout<<"\n";
	cout<<(max_ - min_)<<"\n";
}