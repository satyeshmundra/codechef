#include "bits/stdc++.h"
using namespace std;

int tree[2000002] = {0};
int lazy[2000002] = {0};
void build_tree(int node, int a, int b)
{
	if(a>b)
		return;
	if(a == b)
	{
		tree[node] = 0;
		return;
	}

	build_tree(node*2, a, (a+b)/2);
	build_tree(node*2 + 1, ((a+b)/2)+1, b);

	tree[node] = max(tree[node * 2], tree[node*2 + 1]);
}


void update_tree(int node, int a, int b, int i, int j)
{

	if(lazy[node] != 0)
	{
		tree[node] = abs(tree[node] - (b-a+1));
		if(a != b)
		{
			lazy[node*2] = abs(lazy[node*2] - 1);
			lazy[node *2 + 1] = abs(lazy[node*2 + 1] - 1);
		}
		lazy[node] = 0;

	}
	if(a>b || i>j || a>j || b<i)
		return;

	if(a >= i && b<=j)
	{
		tree[node] = abs(tree[node] - (b-a+1));
		if(a != b)
		{
			lazy[node*2] = abs(lazy[node*2] - 1);
			lazy[node*2 + 1] = abs(lazy[node*2 + 1] - 1);
		}
		// if(tree[node] == 0)
		// 	tree[node] = 1;
		// else
		// 	tree[node] = 0;
		return;
	}

	update_tree(node*2, a, (a+b)/2, i, j);
	update_tree(node *2+1, ((a+b)/2) + 1, b, i, j);

	tree[node] = tree[node*2] + tree[node*2 + 1]; 

}


int query_tree(int node, int a, int b, int i, int j)
{
	if(a>b || i>j || a>j || b<i)
		return 0;

	if(lazy[node] != 0)
	{
		tree[node] = abs(tree[node] - (b-a+1));
		if(a != b)
		{
			lazy[node*2] = abs(lazy[node*2] - 1);
			lazy[node *2 + 1] = abs(lazy[node*2 + 1] - 1);
		}
		lazy[node] = 0;
	}

	if(a>=i && b<=j)	
	{
		return tree[node];
	}

	int q1 = query_tree(node*2, a, (a+b)/2, i , j);
	//q1 = max(q1, 0);
	int q2 = query_tree(node*2 + 1, ((a+b)/2) +1, b, i , j);

	return q1+q2;
}

int main()
{
	long long int q, n, a, b, c;
	cin>>n>>q;
 	
	//build_tree(1, 0, n-1);
	// bool *ar = new bool[n];
	// long long int *sum = new long long int[n];
	// memset(ar, false, n);
	while(q--)
	{
		//count = 0;
		cin>>c>>a>>b;
		if(c == 0)
		{
			update_tree(1, 0, n-1, a, b);
			// for (int i = 0; i < 3*n; ++i)
			// {
			// 	cout<<tree[i]<<" ";
			// 	/* code */
			// }
			// cout<<"\n";
			
		}
		if(c == 1)
		{
			cout<<query_tree(1, 0, n-1, a, b)<<"\n"	;
		}
		// if(c == 0)
		// {
		// 	for(i=a; i<=b; i++)
		// 	{
		// 		ar[i] = !ar[i];
		// 	}
		// }


		// else if(c == 1)
		// {
		// 	for(i=a; i<=b; i++)
		// 	{
		// 		if(ar[i])
		// 		{
		// 			count++;
		// 		}
		// 	}
		// 	cout<<count<<"\n";
		// }

		// if(c == 0)
		// {
		// 	for (i = a; i <= n; ++i)
		// 	{
		// 		if(i>=a && i<=b)
		// 		{
		// 			ar[i] = !ar[i];
			
		// 		}
		// 		if(ar[i])
		// 			count++;
				
		// 		sum[i] = count;
		// 		/* code */
		// 	}
		// }

		// if(c == 1)
		// {
		// 	if(a == 0)
		// 		cout<<sum[b]<<"\n";
		// 	else
		// 		cout<<sum[b]-sum[a-1]<<"\n";
		// }

	}
}