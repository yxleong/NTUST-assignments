/*****************************************************************//**
 * File: bankAccountPasswordEncryptor.cpp
 * Author: Leong Yah Xuan
 * Create Date: November 2, 2023
 * Update Date: November 9, 2023
 * Description: This program is to generate the encrypted password by red-black tree.
 *********************************************************************/

#include <iostream>
#include <string>
#define NUM 25

enum COLOR {
    BLACK,
    RED
};

struct Node {
    int data;       // store data
    Node* left;     // left child node
    Node* right;    // right child node
    Node* parent;   // parent node
    COLOR color;    // node color

    // Construct a new node with data & set to a red node
    Node(int num) :data(num), left(nullptr), right(nullptr), parent(nullptr), color(RED) {}
};

/**
 * Intent: To implement a left rotation operation on a binary tree node.
 * Pre: A root pointer and a node pointer
 * Post: The function performs a left rotation on the node and updates the root if necessary.
 * \param root
 * \param node
 */
void leftRotate(Node*& root, Node* node) {
    Node* right = node->right;
    node->right = right->left;
    if (right->left != nullptr) {
        right->left->parent = node;
    }
    right->parent = node->parent;
    if (node->parent == nullptr) {
        root = right;
    }
    else if (node == node->parent->left) {
        node->parent->left = right;
    }
    else {
        node->parent->right = right;
    }
    right->left = node;
    node->parent = right;
}

/**
 * Intent: To implement a right rotation operation on a binary tree node.
 * Pre: A root pointer and a node pointer
 * Post: The function performs a right rotation on the node and updates the root if necessary.
 * \param root
 * \param left
 */
void rightRotate(Node*& root, Node* left) {
    Node* node = left->left;
    left->left = node->right;
    if (node->right != nullptr) {
        node->right->parent = left;
    }
    node->parent = left->parent;
    if (left->parent == nullptr) {
        root = node;
    }
    else if (left == left->parent->left) {
        left->parent->left = node;
    }
    else {
        left->parent->right = node;
    }
    node->right = left;
    left->parent = node;
}

/**
 * Intent: To fix the Red-Black Tree structure.
 * Pre: A root pointer and a node pointer
 * Post: The function returns the number of rotations performed to restore the Red-Black Tree properties.
 * \param root
 * \param newNode
 */
int checkConsequentRed(Node*& root, Node* current) {
    int count = 0;

    while (current != root && current->parent->color == RED && current->parent->parent != nullptr) {
        // check if parent is a left child
        if (current->parent == current->parent->parent->left) {
            // if current node is a right child
            if (current == current->parent->right) {
                // change current pointer to its parent
                current = current->parent;
                leftRotate(root, current);  // perform L rotation
            } // if current node is a left child already
            current->parent->color = BLACK; // change the (new)current node parent to black
            current->parent->parent->color = RED;   // (new)current node grandparent to red
            rightRotate(root, current->parent->parent); // perform R rotation
            count++;
        }
        else {  // if parent is a right child
            if (current == current->parent->left) { // if current node is a left child
                current = current->parent;
                rightRotate(root, current);
            } // if current node is a right child already
            current->parent->color = BLACK;
            current->parent->parent->color = RED;
            leftRotate(root, current->parent->parent);
            count++;
        }
    }

    return count;
}

/**
 * Intent: This function inserts a new node with a given value into a Red-Black Tree and maintains its properties.
 * Pre: A root pointer and an integer
 * Post: The function returns the number of rotations and adjustments performed during insertion to maintain the Red-Black Tree properties.
 * \param root
 * \param value
 */
int insert(Node*& root, int value) {
    Node* newNode = new Node(value);
    Node* parent = nullptr;
    Node* current = root;   // before every insertion, will loop starting from root
    int count = 0;

    // Searching the correct position for the data
    while (current != nullptr) {
        // In the searching process, if there is a node with two red children
        if (current->left != nullptr && current->right != nullptr) {
            if (current->left->color == RED && current->right->color == RED) {
                // Perform color change algorithm
                current->left->color = BLACK;
                current->right->color = BLACK;
                current->color = RED;
                // Check whether there are two consequent red nodes in the path
                count += checkConsequentRed(root, current); // If yes, do rotation!
            }
        }

        // moving current pointer to search next
        parent = current;
        if (newNode->data < current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    // Insert the data which is set to a red node
    newNode->parent = parent;
    if (parent == nullptr) {
        root = newNode;
    }
    else if (newNode->data < parent->data) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }

    // Check whether there are two consequent red nodes in the path
    count += checkConsequentRed(root, newNode);

    // Root should be black
    root->color = BLACK;

    return count;
}

/**
 * Intent: To print out red node of BTS in prefix form
 * Pre: A struct node
 * Post: The function shows the red node list in prefix way.
 * \param root
 */
void bts2preRed(Node* root) {

    // if tree is empty
    if (root == nullptr) {
        return;		// leave function
    }

    // print out data before going to sub-tree
    if (root->color == RED) {   // if node is red
        std::cout << root->data;
    }
    bts2preRed(root->left);
    bts2preRed(root->right);
}

/**
 * Intent: To print out black node of BTS in postfix form
 * Pre: A struct node
 * Post: The function shows the black node list in postfix way.
 * \param root
 */
void bts2postBlack(Node* root) {

    // if tree is empty
    if (root == nullptr) {
        return;		// leave function
    }

    // print out the data after go down the sub-tree
    bts2postBlack(root->left);
    bts2postBlack(root->right);
    if (root->color == BLACK) { // if node is black
        std::cout << root->data;
    }
}

/**
 * Intent: This function converts a string containing a number to an integer.
 * Pre: A string that represents the number
 * Post: The function returns the integer representation of the input string.
 * \param str
 * \return 
 */
int str2int(std::string str)
{
    int num = 0;

    // check if the input string is character form
    if (isalpha(str[0])) {  // if yes
        num = str[0];   // record the char in int ASCII form
    }
    else {  // if string is digits form
        for (int i = 0; i < str.length(); i++) {
            // process to become number/integer
            num *= 10;
            num += str[i] - '0';
        }
    }

    return num;
}

int main(void) {
    
    Node* root = nullptr;   // empty tree
    int counter = 0;

    // read input
    std::string input = "";
    int num = 0;
    std::getline(std::cin, input);

    // insert data as node to tree
    for (int i = 0; i < input.length(); i++)
    {
        // let input can be a suitable node
        std::string data = "";
        while (input[i] != ' ' && i < input.length())   // ignore space
        {
            data += input[i];   // handle digits form
            i++;
        }
        num = str2int(data);

        // building tree
        counter += insert(root, num);
    }

    // output the required result
    bts2postBlack(root);
    std::cout << "_";
    bts2preRed(root);
    std::cout << "_" << counter << std::endl;

    return 0;
}