#include "bits/stdc++.h"

using namespace std;
int l[2001][2001] = {-1};
int c[2001][2001] = {0};
int LCS(string a, string b, int la, int lb)
{
	int i,j;// count = 0;
	//l[0][0] = 0;
	for(i=0;i<=la; i++)
	{
		for(j=0;j<=lb;j++)
		{
			//count++;
			if(i==0 || j == 0)
				c[i][j] = max(i, j);
			else if(a.at(i-1) == b.at(j-1))
				c[i][j] = c[i-1][j-1];//min(min(c[i-1][j], c[i][j-1]),min(c[i-1][j], c[i-1][j-1]));
			else
				c[i][j] = 1 + min(min(c[i-1][j], c[i][j-1]),min(c[i-1][j], c[i-1][j-1]));
		}
	}
	return c[la][lb];
	// if(la == 0 || lb == 0)
	// 	return 0;
	// if(l[la][lb] != -1)
	// 	return l[la][lb];

	

	// if(a.at(la-1) == b.at(lb-1))
	// {	
	// 	l[la][lb] = 1+LCS(a,b,la-1, lb-1);
	// 	return l[la][lb];
	// }
	// else
	// {
	// 	l[la][lb] = max(LCS(a,b,la, lb-1),LCS(a,b,la-1, lb));
	// 	return l[la][lb];
	// }
}

int main()
{
	int t, maxl;
	string a,b;
	cin>>t;
	//t=10;
	while(t--)
	{
		memset(c, 0, sizeof(l));
		l[0][0] = 0;
		cin>>a;
		cin>>b;
		int la = a.length();
		int lb = b.length();

		maxl = LCS(a,b,la,lb);
		cout<<maxl<<"\n";
	}
}
