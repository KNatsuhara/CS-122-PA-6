#include "header.h"

/*
Function: BSTNode()
Date Created: 4/8/2020
Description: The constructor for the class BSTNode and will open a file and read each
line as a character and string and then add those componenets into a node and then add the node
into the binary search tree.
Input Parameters: void
Returns: An instanitated BSTNode object
*/
BSTNode :: BSTNode() //Constructor
{
    root = nullptr;
    nodeCounter = 0;
    char c;
    string str;

    fstream dataFile; //opens txt file

    dataFile.open("MorseChart.txt", ios::in);

    if (!dataFile.is_open()) //Checks if file opened
    {
        cout << "Morse file did not open!\n";
    }

    while (dataFile >> str >> c)
    {
        insertNode(c, str);
    }

    dataFile.close(); //Closes file 
}

/*
Function: insert()
Date Created: 4/8/2020
Description: Will take the root node and the newNode being introduced to the tree
and then insert the node based on the value of the character and then add it in the
correct order in the tree.
Input Parameters: void
Returns: void
*/
void BSTNode::insert(Node*&nodePtr, Node*&newNode)
{
    if (nodePtr == nullptr)
        nodePtr = newNode;                  // Insert the node.
    else if (newNode->letter < nodePtr->letter)
        insert(nodePtr->left, newNode);     // Search the left branch
    else
        insert(nodePtr->right, newNode);    // Search the right branch
}

/*
Function: insertNode(char c, string str)
Date Created: 4/8/2020
Description: Will add a char c and str c to create a node and then
use the insert function to insert the node into the tree.
Input Parameters: void
Returns: void
*/
void BSTNode::insertNode(char c, string str)
{
    Node* newNode = nullptr;	// Pointer to a new node.

   // Create a new node and store num in it.
    newNode = new Node;
    newNode->letter = c;
    newNode->morse = str;
    newNode->left = newNode->right = nullptr;

    // Insert the node.
    insert(root, newNode);
    nodeCounter++; //add 1 to node counter in tree
}

/*
Function: destroySubTree(Node* nodePtr)
Date Created: 4/8/2020
Description:Will go through the subtree to the last child node and then delete the nodePtr
untl all the nodePtr all destroyed
Input Parameters: void
Returns: void
*/
void BSTNode::destroySubTree(Node* nodePtr)
{
    if (nodePtr)
    {
        if (nodePtr->left)
            destroySubTree(nodePtr->left);
        if (nodePtr->right)
            destroySubTree(nodePtr->right);
        delete nodePtr;
    }
}

/*
Function: searchNode(char c)
Date Created: 4/8/2020
Description: Will search through the BST and search
for all a specific character and return true if found or else false
Input Parameters: void
Returns: boolean
*/
bool BSTNode::searchNode(char c)
{
    Node* nodePtr = root;

    while (nodePtr)
    {
        if (nodePtr->letter == c)
            return true;
        else if (c < nodePtr->letter)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return false;
}

/*
Function: remove(char c)
Date Created: 4/8/2020
Description: Will node with char c and then delete Node from tree
Input Parameters: void
Returns: void
*/
void BSTNode::remove(char c)
{
    deleteNode(c, root);
}

/*
Function: deleteNode(char c, Node*&nodePtr)
Date Created: 4/8/2020
Description: Will search through the tree until the designated character
is found and then run the deleteNode function using recursion until using the
makeDeleteion function to delete the node from the BST.
Input Parameters: void
Returns: void
*/
void BSTNode::deleteNode(char c, Node*&nodePtr)
{
    if (c < nodePtr->letter)
        deleteNode(c, nodePtr->left);
    else if (c > nodePtr->letter)
        deleteNode(c, nodePtr->right);
    else
        makeDeletion(nodePtr);
}

/*
Function: makeDeletetion(Node*&nodePtr)
Date Created: 4/8/2020
Description: Will find a node to delete and based on the location of the node in the BST
will reattach the child node ptrs to reconnect the BST.
Input Parameters: void
Returns: void
*/
void BSTNode::makeDeletion(Node*&nodePtr)
{
    // Define a temporary pointer to use in reattaching
   // the left subtree.
    Node* tempNodePtr = nullptr;

    if (nodePtr == nullptr)
        cout << "Cannot delete empty node.\n";
    else if (nodePtr->right == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;   // Reattach the left child
        delete tempNodePtr;
    }
    else if (nodePtr->left == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;  // Reattach the right child
        delete tempNodePtr;
    }
    // If the node has two children.
    else
    {
        // Move one node to the right.
        tempNodePtr = nodePtr->right;
        // Go to the end left node.
        while (tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;
        // Reattach the left subtree.
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        // Reattach the right subtree.
        nodePtr = nodePtr->right;
        delete tempNodePtr;
        nodeCounter--; //subtract 1 from node counter in tree
    }
}

/*
Function: displayInOrder(Node* nodePtr)
Date Created: 4/8/2020
Description: Uses recursion to travere to the most left child and then work its way
to the the right-most child node in order and print the contents of the node to the console.
Input Parameters: void
Returns: void
*/
void BSTNode::displayInOrder(Node* nodePtr) const
{
    if (nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout << nodePtr->letter << " " << nodePtr->morse << endl;
        displayInOrder(nodePtr->right);
    }
}

/*
Function: findNode(cahr c)
Date Created: 4/8/2020
Description: Will traverse through the tree until finding the Node with the shared
character and then print the morse translation of that character to the console.
Input Parameters: void
Returns: void
*/
void BSTNode::findNode(char c)
{
    Node* nodePtr = root;

    while (nodePtr)
    {
        if (nodePtr->letter == c)
        {
            cout << nodePtr->morse << " ";
            return;
        }
        else if (c < nodePtr->letter)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
}

/*
Function: convertString()
Date Created: 4/8/2020
Description: This function will read the convert.txt file and then convert the strings in
the file into a translated morse code sentence.
Input Parameters: void
Returns: void
*/
void BSTNode ::convertString()
{
    char test[300];
    int i = 0, total = 0;

    fstream dataFile;

    dataFile.open("Convert.txt", ios::in); //opens convert.txt

    if (!dataFile.is_open()) //Checks if file opened
    {
        cout << "Morse file did not open!\n";
    }

    while (!dataFile.eof()) //reads until all of the text file has been read
    {
        dataFile.get(test[i]); //gets each character in the text file and adds them to a characeter array
        i++; //increases count
        total++; //increases total character count in array
    }

    for (int r = 0; r < total-1; r++)
    {
        cout << test[r]; //prints out the entire character array
    }
    cout << endl;

    for (int j = 0; j < total; j++)
    {
        if (test[j] == ' ') //if a space is in the array print a space
        {
            cout << "   "; //Three spaces
        }
        else if(test[j] == '\n') //if a newline is in the array, print a new line
        {
            cout << endl;
        }
        else
        {
            findNode(toupper(test[j])); //converts the character to uppercase and finds node in BST and prints out morse code
        }
    }
    
}
