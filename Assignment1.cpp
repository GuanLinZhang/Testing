
using namespace std;
#include <iostream>
#include <time.h>
#include <ctype.h>
char ch = 'i';
class treeNode {
public:
	int data;
	treeNode* left, * right; 	// pointers to left and right
} *root = 0;  		//root is a global pointer to the root entry
void branching(char);			// function forward declaration
void insertion();
treeNode* search(treeNode*, int);
void traverse(treeNode*);
void main() {  	// print a menu for selection
	string str;
	srand(time(NULL)); // Use current time as seed
	while (ch != 'q') {
		cout << "Enter your selection" << endl;
		cout << "		i: insert a new entry" << endl;
		cout << "		s: search an entry" << endl;
		cout << "		t: traverse the tree and print" << endl;
		cout << "		q: quit" << endl;
		cin>> str;
		ch = tolower(str[0]);
		branching(ch);
	}
}
void branching(char c) {   	// branch to different tasks
	int key;
	switch (c) {
	case 'i':
		insertion();  			// Not passing root, but use it as global
		break;
	case 's':
		cout << "Enter the key to search" << endl;
		cin >> key; 
		search(root, key);	// root call-by-value
		break;
	case 't':
		traverse(root);		// print all data
		break;
	default:
		cout << "Invalid input" << endl;
	}
}
treeNode* search(treeNode* top, int key) {
	treeNode* p = top;
	if (key == p->data) {
		if (ch == 's')
			cout << "The data is found. data = " << p->data << endl;
		// return p;
	}
	if (key <= p->data) {
		if (p->left == 0)
		{
			if (ch == 's')
				cout << "The data is not foundn" << endl;
			return p;
		}
		else search(p->left, key);
	}
	else {
		if (p->right == 0)
		{
			if (ch == 's')
				cout << "The data is not found." << endl;
			return p;
		}

		else search(p->right, key);
	}
	//return p;
}
void insertion() {    		// insert a new entry
	treeNode* p, * q;
	int i, n, key;
	cout << "Enter the number of entries you want to insert" << endl;
	cin >> n;
	cout << "The random keys inserted are:" << endl;
	for (i = 0; i < n; i++) {
		p = new(treeNode);
		if (p == 0)  cout << "out of memory" << endl;
		key = rand() % 100;	// a random key
		cout <<  key << ", ";
		p->data = key;
		p->left = 0; p->right = 0;
		if (root == 0) root = p;	// tree empty
		else {
			q = search(root, key);
			if (key < q->data) q->left = p;
			else  q->right = p;
		}
	}
	cout << endl;
}
void traverse(treeNode* top) {
	treeNode* p = top;
	if (p != 0) {
		traverse(p->left);
		cout << "data = " << p->data << endl;
		traverse(p->right);
	}
}
