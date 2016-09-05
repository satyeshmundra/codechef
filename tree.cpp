#include "bits/stdc++.h"

using namespace std;
map<int, list<int> > tree;
int visited[100001] = {0};

int cost[100001] = {0};
long long int BFS(int a)
{
	int v;
	queue<int> q;
	q.push(a);
	while(!q.empty())
	{
		v = q.front();
		q.pop();
		visited[v] = 1;
		list<int>::iterator i;
		for(i = tree[v].begin(); i!= tree[v].end(); i++)
		{
			if(!visited[*i])
				q.push(*i);
		}
	}
	
	q.push(v);
	cost[v] = 0;
	memset(visited, 0 , sizeof(visited));
	while(!q.empty())
	{
		v = q.front();
		q.pop();
		visited[v] = 1;
		list<int>::iterator i;
		for(i = tree[v].begin(); i!= tree[v].end(); i++)
		{
			if(!visited[*i])
			{
				cost[*i] = cost[v]+1;
				q.push(*i);
			}
		}
	}
	return cost[v];
}
int main()
{
	long long int n, m, i,a,b;
	cin>>n;
	for(i=1	; i<n; i++)
	{
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);

	}

	m = BFS(a);
	cout<<m<<"\n";

}