#include "bits/stdc++.h"
using namespace std;

int main()
{
	long long int t;
	string s;

	cin>>t;
	while(t--)
	{
		cin>>s;

		//cout<<s.size()<<"\n";
	
		int l = s.size();
		int flag = 1;
		int i;
		if(l%2 == 0)
		{
			for (i = 0; i < l/2 - 1; ++i)
			{
				if(s[l-i-1] > s[i])
					flag = 1;
				else if(s[l-i-1] < s[i])
					flag = 0;
				s[l-i-1] = s[i];

			}
			if(flag == 0)
			{
				s[i+1] = s[i];
			}
			if(flag == 1)
			{
				if(s[i]!='9')
				{
					if(s[i] <= s[i+1])
						s[i]++;
						s[i+1] = s[i];
				}
				else
				{
					s[i] = s[i+1] = '0';
					for(i = l/2 - 2; i>=0; i--)
					{
						if(s[i] != '9')
						{	
							s[i]++;
							s[l-i-1]++;
							break;
						}
						else
						{
							s[i] = s[l-i-1] = '0';
						}
					}

					if(i == -1)
					{
						s="1";
						for(i=0;i<l-1;i++)
							s+="0";
						s+="1";
					}
				}
			}
		}
		else
		{

			for (i = 0; i < l/2; ++i)
			{
				if(s[l-i-1] > s[i])
					flag = 1;
				else if(s[l-i-1] < s[i])
					flag = 0;
				s[l-i-1] = s[i];

			}
			if(flag == 1)
			{
				if(s[i] != '9')
				{
					s[i]++;
				}
				else
				{
					s[i] ='0';
					for(i = l/2 - 1; i>=0; i--)
					{
						if(s[i] != '9')
						{	
							s[i]++;
							s[l-i-1]++;
							break;
						}
						else
						{
							s[i] = s[l-i-1] = '0';
						}
					}

					if(i == -1)
					{
						
						s="1";
						for(i=0;i<l-1;i++)
							s+="0";
						s+="1";
					}
				}
			}

		}

		cout<<s<<"\n";

	}	

}