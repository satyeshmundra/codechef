#include "bits/stdc++.h"

using namespace std;
int main()
{
	int wt;
	cout<<1<<"\n";
	cout<<3<<" "<<2<<" "<<3<<" "<<3<<"\n";
	cout<<3<<" "<<4<<" "<<5<<" "<<5<<"\n";

	cout<<flush;

	cin>>wt;

	if(wt == 0)
		cout<<2<<"\n"<<1<<"\n";
	else if(wt == 1)
		cout<<2<<"\n"<<2<<"\n";
	else if(wt == 2)
		cout<<2<<"\n"<<3<<"\n";
	else if(wt == -1)
		cout<<2<<"\n"<<4<<"\n";
	else if(wt == -2)
		cout<<2<<"\n"<<5<<"\n";
		return 0;
}