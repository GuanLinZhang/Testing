// The following code shows a simple implementation of search and insertion of binary search tree, where the common functions main and branching are similar to those discussed in the linked list section.
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // used by malloc
#include <time.h>
#include <ctype.h>
#include "miniunit.h"
#pragma warning(disable : 4996) // for Visual Studio Only

char ch = 'i';					// Global variable
struct treeNode
{
	int data;
	struct treeNode* left, * right; // pointers to left and right
} *root = 0;					   // root is a global pointer to the root entry
void branching(char);			   // function forward declaration
void insertion();
struct treeNode* search(struct treeNode*, int);
void traverse(struct treeNode*);
main()
{ // print a menu for selection
	char str[2];
	srand((unsigned)time(0)); // Use current time as seed
	while (ch != 'q')
	{
		printf("Enter your selection\n");
		printf("		i: insert a new entry\n");
		printf("		s: search an entry\n");
		printf("		t: traverse the tree and print\n");
		printf("		q: quit \n");
		scanf("%s", str);
		ch = tolower(str[0]);
		branching(ch);
	}
}
void branching(char c)
{ // branch to different tasks
	int key;
	switch (c)
	{
	case 'i':
		insertion(); // Not passing root, but use it as global
		break;
	case 's':
		printf("Enter the key to search\n");
		scanf("%d", &key); // For Visual Studio, you may need to use scanf_s, or add directive: #pragma warning(disable: 4996)
		search(root, key); // root call-by-value
		break;
	case 't':
		traverse(root); // print all data
		break;
		//	case '\n':
		//		break;  // buffer not flushed correctly
		break;
	default:
		printf("Invalid input\n");
	}
}
struct treeNode* search(struct treeNode* top, int key)
{
	struct treeNode* p = top;
	if (key == p->data)
	{
		if (ch == 's')
			printf("The data is found. data = %d\n", p->data);
		// return p;
	}
	if (key <= p->data)
	{
		if (p->left == 0)
		{
			if (ch == 's')
				printf("The data is not found.\n");
			return p;
		}
		else
			search(p->left, key);
	}
	else
	{
		if (p->right == 0)
		{
			if (ch == 's')
				printf("The data is not found.\n");
			return p;
		}

		else
			search(p->right, key);
	}
}
void insertion()
{ // insert a new entry
	struct treeNode* p, * q;
	int i, n, key;
	printf("Enter the number of entries you want to insert\n");
	scanf("%d", &n);
	printf("The random keys inserted are:\n");
	for (i = 0; i < n; i++)
	{
		p = (struct treeNode*)malloc(sizeof(struct treeNode));
		if (p == 0)
			printf("out of memory\n");
		key = rand() % 100; // a random key
		printf("%d %s", key, ", ");
		p->data = key;
		p->left = 0;
		p->right = 0;
		if (root == 0)
			root = p; // tree empty
		else
		{
			q = search(root, key);
			if (key < q->data)
				q->left = p;
			else
				q->right = p;
		}
	}
	printf("\n");
}
void traverse(struct treeNode* top)
{
	struct treeNode* p = top;
	if (p != 0)
	{
		traverse(p->left);
		printf("data = %d\n", p->data);
		traverse(p->right);
	}
}
// The input and output of testing this program is shown as follows:
// Enter your selection
//                 i: insert a new entry
//                 s: search an entry
//                 t: traverse the tree and print
//                 q: quit
// i
// Enter the number of entries you want to insert
// 8
// The random keys inserted are:
// 11 , 66 , 14 , 83 , 1 , 61 , 88 , 34 ,
// Enter your selection
//                 i: insert a new entry
//                 s: search an entry
//                 t: traverse the tree and print
//                 q: quit
// t
// data = 1
// data = 11
// data = 14
// data = 34
// data = 61
// data = 66
// data = 83
// data = 88
// Enter your selection
//                 i: insert a new entry
//                 s: search an entry
//                 t: traverse the tree and print
//                 q: quit
// s
// Enter the key to search
// 66
// The data is found. data = 66
// The data is not found.
// Enter your selection
//                 i: insert a new entry
//                 s: search an entry
//                 t: traverse the tree and print
//                 q: quit
// s
// Enter the key to search
// 83
// The data is found. data = 83
// The data is not found.
// Enter your selection
//                 i: insert a new entry
//                 s: search an entry
//                 t: traverse the tree and print
//                 q: quit
// s
// Enter the key to search
// 77
// The data is not found.
// Enter your selection
//                 i: insert a new entry
//                 s: search an entry
//                 t: traverse the tree and print
//                 q: quit
