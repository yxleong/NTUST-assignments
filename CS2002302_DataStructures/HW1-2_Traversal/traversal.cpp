/*****************************************************************//**
 * File: traversal.cpp
 * Author: Leong Yah Xuan
 * Create Date: October 4, 2023
 * Update Date: October 5, 2023
 * Description: This program is to build a BST and print out the required traversal list.
 *********************************************************************/
#include <iostream>
#define NUM 100

// declare node in tree
struct Node {
	char data;
	Node* left;
	Node* right;
	Node(char value) :data(value), left(nullptr), right(nullptr) {}
};

/**
 * Intent: To get the position of data in array
 * Pre: A char array, a char data and two integer numbers
 * Post: The function returns the index of the data in array.
 * \param order
 * \param data
 * \param start
 * \param end
 * \return 
 */
int findPosition(char order[], char data, int start, int end) {

	// loop the array to find data
	for (int i = start; i < end; i++) {
		if (order[i] == data) {		// if found
			return i;	// return the index
		}
	}

	// if not found the match data
	return -1;
}

/**
 * Intent: To build the binary search tree
 * Pre: A infix array, a prefix/postfix array, a string, three integer numbers
 * Post: The function returns the root of built tree.
 * \param inorder
 * \param given
 * \param order
 * \param start
 * \param end
 * \param index
 * \return 
 */
Node* generateBST(char inorder[], char given[], std::string order, int start, int end, int& index) {
	
	// to avoid wrong index
	if (start > end) {
		return nullptr;		// return empty tree
	}

	// check the given order
	if (order == "prefix") {	// if given order is in prefix form

		// data will go by sequence
		char rootData = given[index++];		// increment
		Node* root = new Node(rootData);	// assign data to become a node

		// if done traversal
		if (start == end) {
			return root;	//	return the to root of built tree
		}

		// call function to get the index of current root
		int rootIndex = findPosition(inorder, rootData, start, end);
		
		// call function to get get the sub-tree for current root
		root->left = generateBST(inorder, given, order, start, rootIndex - 1, index);	// from first to data left of root
		root->right = generateBST(inorder, given, order, rootIndex + 1, end, index);	// from data right of root to end

		// return to root of built node
		return root;
	}
	else if (order == "postfix") {	// if given order is in postfix form
		
		// data will go in reverse
		char rootData = given[index--];		// read from back
		Node* root = new Node(rootData);	// assign data to become a node

		// if done traversal
		if (start == end) {
			return root;	//	return the to root of built tree
		}

		// call function to get the index of current root
		int rootIndex = findPosition(inorder, rootData, start, end);

		// call function to get get the sub-tree for current root
		root->right = generateBST(inorder, given, order, rootIndex + 1, end, index);	// from data right of root to end
		root->left = generateBST(inorder, given, order, start, rootIndex - 1, index); 	// from first to data left of root
		// reverse: right then left

		// return to root of built node
		return root;
	}
}

/**
 * Intent: To print out BTS in prefix form
 * Pre: A struct node
 * Post: The function shows the list in prefix way.
 * \param root
 */
void bts2pre(Node* root) {

	// if tree is empty
	if (root == nullptr) {
		return;		// leave function
	}

	// print out data before going to sub-tree
	std::cout << root->data;
	bts2pre(root->left);
	bts2pre(root->right);
}

/**
 * Intent: To print out BTS in postfix form
 * Pre: A struct node
 * Post: The function shows the list in postfix way.
 * \param root
 */
void bts2post(Node* root) {

	// if tree is empty
	if (root == nullptr) {
		return;		// leave function
	}

	// print out the data after go down the sub-tree
	bts2post(root->left);
	bts2post(root->right);
	std::cout << root->data;
}

/**
 * Intent: To calculate the height of node
 * Pre: A struct node
 * Post: The function returns the height of node in tree.
 * \param root
 * \return 
 */
int getHeight(Node* root) {
	
	// if tree is empty
	if (root == nullptr) {
		return 0;	// height is zero
	}

	// get the height of sub-tree
	int leftHeight = getHeight(root->left);
	int rightHeight = getHeight(root->right);

	// calculate the height of tree
	int height = leftHeight >= rightHeight ? leftHeight : rightHeight;

	return height + 1;	// include the height of tree
}

/**
 * Intent: To print out the level order of BTS
 * Pre: A struct node
 * Post: The function shows the BTS in level order.
 * \param root
 * \param level
 */
void bts2level(Node* root, int level) {

	// if tree is empty
	if (root == nullptr) {
		return;		// leave function
	}

	if (level == 0) {	// first level for root
		std::cout << root->data;
	}
	else if (level > 0) {
		// replace the upper root
		bts2level(root->left, level - 1);
		bts2level(root->right, level - 1);
	}	
}

/**
 * Intent: To get the level order of BTS
 * Pre: A struct node
 * Post: The function calls function bts2level for each node in BTS.
 * \param root
 */
void getLevelOrder(Node* root) {

	// call function to get the height of tree
	int height = getHeight(root);

	// loop from root to nodes below
	for (int i = 0; i < height; i++) {	// level start from 0
		bts2level(root, i);		// call function to print BTS in level order form
	}
}

int main(void) {

	// declare the reused variables outside loop
	std::string infixOrder = "", nowOrder = "";
	std::string from = "", to = "";

	// read the input
	while (std::cin >> infixOrder >> from >> nowOrder >> to) {

		// declare the variables needed
		char infix[NUM] = {}, given[NUM] = {};
		int index = 0;

		// convert the read string to array
		for (int i = 0; i < infixOrder.length(); i++) {
			infix[i] = infixOrder[i];
		}
		for (int i = 0; i < nowOrder.length(); i++) {
			given[i] = nowOrder[i];
		}

		// check the requirement
		if (from == "prefix" && to == "postfix") {
			index = 0;	// prefix start from front
			Node* binaryTree = generateBST(infix, given, from, 0, infixOrder.length() - 1, index);

			// call function to print the new list in the prefix traversal way
			bts2post(binaryTree);

			std::cout << std::endl;

			// call function to print the new list in level order
			getLevelOrder(binaryTree);
		}
		else if (from == "postfix" && to == "prefix") {
			index = nowOrder.length() - 1; // postfix will start from back
			Node* binaryTree = generateBST(infix, given, from, 0, infixOrder.length() - 1, index);
			
			// call function to print the new list in the prefix traversal way
			bts2pre(binaryTree);

			std::cout << std::endl;

			// call function to print the new list in level order
			getLevelOrder(binaryTree);
		}
	}
	return 0;
}
