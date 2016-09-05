#include "bits/stdc++.h"
using namespace std;


struct node{
	int n;
	node *right;
	node *left;

};

void print_inorder(node *head)
{
	if(head == NULL)
		return;

	print_inorder(head->left);
	cout<<(head->n)<<"  ";
	print_inorder(head->right);
}

int findheight(node *head)
{
	if(head ==NULL)
		return 0;
	else 
		return 1+max(findheight(head->left), findheight(head->right));
}

void printlevel(node *head, int level, int l)
{
	if(head == NULL)
		return;
	if(level == 1)
		cout<<head->n<<"  ";
	else
		if(l == 1)
		{
			printlevel(head->left, level-1, l);
			printlevel(head->right, level-1, l);
		}
		else if(l== -1)
		{
			printlevel(head->right, level-1, l);
			printlevel(head->left, level-1, l);

		}

}

void spiralorder(node *head, int h)
{
	int l = 1, i;
	for(i=1; i<=h; i++)
	{
		printlevel(head, i, l);
		cout<<"\n";
		l = -l;
	}
}

void levelorderspiral(node *head)
{
	int h = findheight(head);
	cout<<"height = "<<h<<"\n";
	spiralorder(head, h);

}

node * newNode(int a)
{
	node *temp = new node;
	temp->n = a;
	temp->right = temp->left = NULL;
	return temp;
}
int main()
{
	node *list = NULL;
	node *head  =  NULL;
	node *root = newNode(1);
	root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5);
     root->right->right = newNode(6);
     root->left->left->left = newNode(7);
     root->left->left->right = newNode(8);
     root->right->right->left = newNode(9);
     root->right->right->right = newNode(10);


     print_inorder(root);

     levelorderspiral(root);

}

// int maxSubArray(const vector<int> &A) {

// int n = A.size();
// int sum[n];
// cout<<n<<"saty\n";
// int m = A[0];
// int i;
// sum[0] = A[0];
// for(i=1;i<n;i++)
// {
// 	cout<<i<<"\n";
// sum[i] = max((sum[i-1] + A[i]), A[i]);
// if(sum[i] > m)
// m = sum[i];
// }
// return m;
//     // Do not write main() function.
//     // Do not read input, instead use the arguments to the function.
//     // Do not print the output, instead return values as specified
//     // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
// }

// int main()
// { 
// 	vector<int> A;
// int n;
// int i, a;
// cin>>n;
// cout<<n<<"A\n";
// for(i=0;i<n; i++)
// {
// 	cin>>a;
// 	A.push_back(a);
// }
// cout<<maxSubArray(A);
//     // Do not write main() function.
//     // Do not read input, instead use the arguments to the function.
//     // Do not print the output, instead return values as specified
//     // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
// }
