#include "bits/stdc++.h"
using namespace std;
//int a[101][101];
//long long int b[100001];

struct node 
{
	int val;
	node *l;
	node *r;

};

 int a[100] = {0};


void width(node *head, int n)
{
	a[n] ++;
	if(head -> l != NULL)
		width(head->l, n+1);

	if(head -> r != NULL)
		width(head->r, n+1);
	
	return;
	
}

void make_node(node *head, int n, int num)
{
	// /cout<<"saty\n";

	if(n == 0)
	{
		head->l = new node();
		head->l->l = head->l->r = NULL;
		head->l->val = num;
	}
	if(n == 1)
	{
		head->r = new node();
		head->r->l = head->r->l = NULL;
		head->r->val = num;
	}

	

}

int main()
{
	int i;
	node *head = new node();
	head->val = 1;
	make_node(head, 0, 2);
	make_node(head->l, 0, 4);
	make_node(head->l, 1, 5);
	make_node(head, 1, 3);
	make_node(head->r, 1, 8);
	make_node(head->r->r, 0, 6);
	make_node(head->r->r, 1, 1);

	width(head, 0);
	for(i=0; i<9;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}