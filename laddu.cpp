#include "bits/stdc++.h"
using namespace std;


int main()
{

	int t, a, rank, sev;
	int laddu;
	string origin;
	string act;
	cin>>t;
	while(t--)
	{
		laddu = 0;
		cin>>a;
		cin>>origin;

		while(a--)
		{
			cin>>act;
			if(act.compare("CONTEST_WON") == 0)
			{
				laddu += 300;
				cin>>rank;
				if(rank <20)
					laddu += (20-rank);
			}
			else if(act.compare("TOP_CONTRIBUTOR") == 0)
			{
				laddu += 300;
			}

			else if(act.compare("BUG_FOUND") == 0)
			{
				cin>>sev;
				laddu += sev;
			}

			else if(act.compare("CONTEST_HOSTED") == 0)
			{
				laddu += 50;
			}

		}

		if(origin.compare("INDIAN") == 0)
			cout<<laddu/200<<"\n";
		else if(origin.compare("NON_INDIAN") == 0)
			cout<<laddu/400<<"\n";
	}
	return 0;
}