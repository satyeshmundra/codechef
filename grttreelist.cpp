#include <iostream>
using namespace std;

typedef struct tree
{
	int data;
	tree *left;
	tree *right;
}tree;

typedef struct dlist
{
	int data;
	dlist *next;
	dlist *prev;
}dlist;

tree* insert_tree(tree *head, int n)
{
	
	if(head == NULL)
	{
		tree *node = new tree();
		node->data = n;
		node->left = node->right = NULL;
		head = node;

	}
	else if(head->data > n)
	{

		head->left = insert_tree(head->left, n);
	}
	else if(head->data < n)
	{
		head->right = insert_tree(head->right, n);
	}
	
	return head;
}

void print_inorder(tree *head)
{
	if(head == NULL)
		return;
	print_inorder(head->left);
	cout<<head->data<<" ";
	print_inorder(head->right);
}

int main()
{
	int i, n, N;
	tree *head;	
	cout<<"Enter the number of numbers\n";
	cin>>N;
	for(i=0; i<N; i++)
	{
		cout<<"Enter a number";
		cin>>n;
		head = insert_tree(head, n);
	}
	print_inorder(head);
	cout<<"\n";
}

