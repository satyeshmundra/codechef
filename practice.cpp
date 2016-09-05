#include "bits/stdc++.h"
using namespace std;
struct node{
	long long int val;
	long long int wt;
};
long long int ar[200001];
long long int res[200001];
int visited[200001];
long long int DFS(long long int n,  map<long long int , list<node> > g)
{
	memset(visited, 0, sizeof(visited));
	stack<node> s;
	s.push({n,0});
	long long int max = 0;
	visited[n] = 1;
	while(!s.empty())
	{
		node a = s.top();
		s.pop();
		//visited[a.val] = 1;
		list<node>::iterator i;
		for(i = g[a.val].begin(); i!= g[a.val].end(); i++)
		{
			if(!visited[((*i).val)] && (*i).wt >= a.wt)
			{
				visited[(*i).val] = 1;
				s.push({((*i).val), ((*i).wt)});
				if((*i).val > max)
					max = (*i).val;
			}
		}
	}
return max;

}

int main()
{
	long long int i,n,m,t,a,b,day;
	
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		map<long long int , list<node> > g;
		long long int sum = 0;
		for(i=0;i<n;i++)
		{
			cin>>ar[i];
		}
		for(i=0;i<m;i++)
		{
			cin>>day;
			cin>>a;
			cin>>b;
			g[a].push_back({b,day});
			g[b].push_back({a,day});
		}

		for(i=0;i<n;i++)
		{
			res[i] = DFS(ar[i], g);
		}

		for(i=0;i<n;i++)
		{
			
			sum+=res[i];
		}
		cout<<sum<<"\n";
	}
	
	
}