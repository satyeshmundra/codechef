#include "bits/stdc++.h"

using namespace std;
int a[2001];
int main()
{
	int n, i;
	while(true)
	{
		cin>>n;
		if(n == 0)
			break;
		list<int> l;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int c = 1, flag = 0;
		i = 0;
		while(i<n)
		{
			/* code */
			if(a[i] == c)
			{
				i++;
				c++;
				continue;
			}
			else if(!l.empty() && l.front() == c)
			{
				c++;
				l.pop_front();
			}
			else
			{
				l.push_front(a[i]);
				i++;
			}
		}
		while(!l.empty())
		{
			if(l.front() == c)
			{
				c++;
				l.pop_front();
			}
			else
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			cout<<"yes\n";
		else
			cout<<"no\n";
	}

}