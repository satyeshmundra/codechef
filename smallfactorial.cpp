#include "bits/stdc++.h"
using namespace std;
int fact[200] ={0};
int fact1[200][3] = {0};
int c[200];
void fac(int fact[], int n)
{
	int i, count = -1;
	while(n>0)
	{
		int r = n % 10;
				
		count++;		
		memset(c, 0, 800);		
		for(i=199; i>0 ; i--)
		{
			c[i-1] = (fact[i] * r)/10;
			fact1[i-count][count] = (fact[i] * r)%10 + c[i];
			
			//cout<<"fact="<<fact[i]<<"r="<<r<<" "<<c<<"saty\n";
		}
		// for(i=0; i<10 ; i++)
		// {
		// 	cout<<fact[i]<<" ";
		// }
		n = n/10;
	}
	memset(c, 0, 800);
	c[199] = 0;
	for(i=199; i>0; i--)
	{
		fact[i] = (fact1[i][0] + fact1[i][1] + fact1[i][2]) % 10 + c[i];
		c[i-1] = (fact1[i][0] + fact1[i][1] + fact1[i][2]) / 10;
	}
	memset(fact1 , 0, 2400);
}
int main()
{
	long long int t, n, sum, flag =0;
	cin>>t;

	while(t--)
	{
		cin>>n;
		flag  = 0;
		memset(fact, 0, 800); 
		fact[199]=1;
		n++;
		while(--n)
		{

			fac(fact, n);
			/* code */
		}
		for (int i = 0; i < 200; ++i)
		{
			if(fact[i] == 0 && flag == 0)
			{
				continue;
			}
			else
			{
				flag = 1;
				cout<<fact[i];
			}
			/* code */
		}
	cout<<"\n";
	}
}
