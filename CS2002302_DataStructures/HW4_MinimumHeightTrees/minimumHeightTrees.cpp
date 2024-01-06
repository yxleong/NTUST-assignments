/*****************************************************************//**
 * File: minimumHeightTrees.cpp
 * Author: Leong Yah Xuan
 * Create Date: December 11, 2023
 * Update Date: December 12, 2023
 * Description: This program is to find which nodes as root node result in the minimum value of tree height.
 *********************************************************************/
#include <iostream>
#define MAX 100

 /**
  * Intent: To calculate the height of the tree rooted at a given node.
  * Pre: The currentNode,parentNode are valid nodes in the tree.
  * Post: The function returns the height of the tree rooted at the given node.
  * \param currentNode
  * \param parentNode
  * \param isBetweenEdge
  * \param nodeHeights
  * \return
  */
int getHeight(int currentNode, int parentNode, bool isBetweenEdge[][MAX], int nodeHeights[]) {
    int currentHeight = 0;

    for (int adjacentNode = 0; adjacentNode < MAX; adjacentNode++) {
        // check if current node got edge to adjacent node and adjacent node is not parent node
        if (isBetweenEdge[currentNode][adjacentNode] && adjacentNode != parentNode) {   //  to avoid cycle
            // current node height is itself 1 + maximum height of subtree rooted at adjacent node
            currentHeight = std::max(currentHeight, 1 + getHeight(adjacentNode, currentNode, isBetweenEdge, nodeHeights));
        }
    }
    return currentHeight;
}

/**
 * Intent: To show the root nodes resulting in the minimum height.
 * Pre: The num is the correct count of nodes in the tree.
 * Post: The nodeHeights array is updated with the height of each node.
 * \param num
 * \param isBetweenEdge
 * \param nodeHeights
 */
void findMinHeightRoot(int num, bool isBetweenEdge[][MAX], int nodeHeights[]) {
    int minHeight = MAX;
    int parentNode = -1;    // no parent yet

    // loop all the given node as root node
    for (int node = 0; node < num; node++) {

        // get the node height when act as root
        int height = getHeight(node, parentNode, isBetweenEdge, nodeHeights);

        // record the height of that node
        nodeHeights[node] = height;

        // mark the min height
        minHeight = std::min(minHeight, height);
    }

    // find the node with min height when act as root
    for (int rootNode = 0; rootNode < num; rootNode++) {

        // output the node with min height in increasing order
        if (nodeHeights[rootNode] == minHeight) {
            std::cout << rootNode << " ";
        }
    }
}

int main(void) {
    int num = 0;
    int nodeHeights[MAX] = { 0 };
    bool isBetweenEdge[MAX][MAX] = { 0 };

    // read the number of nodes in the tree
    std::cin >> num;

    // 0 <= ai, bi < n
    for (int i = 0; i < num - 1; i++) {
        int nodeA = 0, nodeB = 0;

        // read a pair of integers having edges in tree
        std::cin >> nodeA >> nodeB;

        // mark the edge between them
        isBetweenEdge[nodeA][nodeB] = 1;
        isBetweenEdge[nodeB][nodeA] = 1;
    }

    // output the root nodes result in the minimum value of height
    findMinHeightRoot(num, isBetweenEdge, nodeHeights);

    return 0;
}