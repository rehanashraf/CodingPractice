/*
 * issmaetree.cpp
 *
 *  Created on: Aug 9, 2020
 *      Author: rehanashraf
 */

#include <iostream>
#include "print.h"
#include "macros.h"
using namespace std;

void runIsSameTree(void);
typedef struct TreeNode tnode;

bool isSameTree(TreeNode* p, TreeNode* q) {
	bool rv , lrv, rrv;
	rv = lrv = rrv = false;
	int temp = 0;

	TreeNode *pleft, *pright, *qleft, *qright;
	pleft = pright = qleft = qright = nullptr;

	if (p == nullptr && q == nullptr)
		return true;
	else if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr))
		return false;

	if (p->val == q->val)
		rv = true;
	else
		rv = false;
	lrv = isSameTree(p->left, q->left);
	rrv = isSameTree(p->right, q->right);

    return rv && lrv && rrv;
}

int maxDepth(TreeNode* root) {
	int ldepth, rdepth;
	ldepth = rdepth = 1;

	if (root == nullptr)
		return 0;

	ldepth = ldepth + maxDepth(root->left);
	rdepth = rdepth + maxDepth(root->right);

	return MAX(ldepth, rdepth);
}

bool isBSTUtil(tnode* node, int min, int max)
{
    /* an empty tree is BST */
    if (node==NULL)
        return 1;

    /* false if this node violates
    the min/max constraint */
    if (node->val < min || node->val > max)
        return 0;

    /* otherwise check the subtrees recursively,
    tightening the min or max constraint */
    return
        isBSTUtil(node->left, min, node->val-1) && // Allow only distinct values
        isBSTUtil(node->right, node->val+1, max); // Allow only distinct values
}

bool isBSTValid(tnode *root)
{
    return(isBSTUtil(root, INT_MIN, INT_MAX));
}
/*
	  1
	/   \
   2     3
  / \   / \
 4   5 6   7
 */
/* Breadth First Traversal or Level Order Traversal
 * 1 2 3 4 5 6 7
 * or
 * 7 6 5 4 3 2 1
 * */
/*Function to print level order traversal of tree*/
/*printLevelorder(tree)
for d = 1 to height(tree)
   printGivenLevel(tree, d);*/

/*Function to print all nodes at a given level*/
/*
printGivenLevel(tree, level)
if tree is NULL then return;
if level is 1, then
    print(tree->data);
else if level greater than 1, then
    printGivenLevel(tree->left, level-1);
    printGivenLevel(tree->right, level-1);
*/


void printGivenLevel( tnode* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->val);
    else if (level > 1)
    {
    	/* Check if you want to print right to left or left to right */
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

int height( tnode* node)
{
	int rv = 0;
	int lheight = 1, rheight = 1;

	if (node == NULL)
		return rv;

	lheight = lheight + height(node->left);
	rheight = rheight + height(node->right);

	rv = MAX(rheight, lheight);
	return rv;
}

void printLevelOrder(tnode* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printGivenLevel(root, i);
}

/*
	  1
	/   \
   2     3
  / \   / \
 4   5 6   7
 */
/* Depth First Traversal
 * In order (Left, Root, Right) 4 2 5 1 6 3 7
 * Pre order (Root, Left, Right) 1 2 4 5 3 6 7
 * Post order (Left, Right, Root) 4 5 2 6 7 3 1
 * */

/* Given a binary tree, print its nodes according to the
"bottom-up" postorder traversal. */
void printPostorder(tnode* node)
{
    if (node == NULL)
        return;

    // first recur on left subtree
    printPostorder(node->left);

    // then recur on right subtree
    printPostorder(node->right);

    // now deal with the node
    cout << node->val << " ";
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder( tnode* node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    cout << node->val << " ";

    /* now recur on right child */
    printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder( tnode* node)
{
    if (node == NULL)
        return;

    /* first print data of node */
    cout << node->val << " ";

    /* then recur on left sutree */
    printPreorder(node->left);

    /* now recur on right subtree */
    printPreorder(node->right);
}

/* Qualcom Question print numbers based on order */

void printNode(tnode *head, int level, int heigthToPrint)
{
	int right, left;
	right = left = 0;
	if(head == NULL)
		return;
	printNode(head->right, level+ 1,heigthToPrint);
	printNode(head->left,level+ 1, heigthToPrint);

	if (level == heigthToPrint)
	{
		printf("%d &d ", right, left);
	}

}

void printTreeNodes(tnode *root)
{
	int theight = 0;
	theight = maxDepth(root);
	for (int i = theight; i > 0; i--)
	{
		printNode(root, i, theight);
	}
}



