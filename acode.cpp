#include "bits/stdc++.h"

using namespace std;
int ar[5000] = {0};

long long int decode(string s, int i)
{

	if(i < 0)
		return 1;
	if(s[0] == '0')
		return 0;
	if(i == 0 && s[i] != '0')
		return 1;
	else if(i == 0 && s[i] == '0')
		return 0;
	if(ar[i] != 0)
		return ar[i];
	else
	{
		if(s[0] == '1' && s[1] != '0')
		{
			ar[i] = decode(s.substr(1), i-1) + decode(s.substr(2), i-2);
		}
		else if(s[0] == '1' && s[1] == '0')
		{
			ar[i] = decode(s.substr(2), i-2);
		}
		else if(s[0] == '2' && s[1] == '0')
		{
			ar[i] = decode(s.substr(2), i-2);
		}
		else if(s[0] == '2' && (s[1] == '1' || s[1] == '2' || s[1] == '3' || s[1] == '4' || s[1] == '5' || s[1] == '6'))
		{
			ar[i] = decode(s.substr(1), i-1) + decode(s.substr(2), i-2);
		}
		else
		{
			ar[i] = decode(s.substr(1), i-1);
		}

		return ar[i];

	}
}

int main()
{
	string s;
	long long int c;
	cin>>s;
	while(s.compare("0") != 0)
	{
		//vector<long long int> ar;
		c = decode(s, s.length()-1);
		// for (int i = 1; i < s.length(); ++i)
		// {
		// 	if(s[i-1] == '1')
		// 	{
		// 		if(s[i] == '0')
		// 			continue;
		// 		else
		// 			c*=2;
		// 	}
		// 	if(s[i-1] == '2')
		// 	{
		// 		if(s[i] == '0')
		// 			continue;
		// 		else if(s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6')
		// 			c*=2;
		// 	}
		// 	/* code */
		// }
		cout<<c<<"\n";
		memset(ar, 0, 20000);
		cin>>s;

	}

	return 0;

}