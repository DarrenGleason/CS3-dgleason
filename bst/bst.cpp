/*
    Darren Gleason
    10/27/2019
    This program reads data from a file and put the data into a binary tree. A menu then allows you to select different options from displaying the bst in a certain order to deleteing a certain node.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <iterator>

using namespace std;

//  Binary Search Tree (BST) as Abstract Data Type (ADT)
// Pointer-based implementation of BST
#define DEBUG 1 // change it to 0 if you do not want debug statement to print


// Binary Tree Node
template<class T>
struct Node {
    T data; //store data as key
    int count;
    Node<T>* lTree;
    Node<T>* rTree;
};

template <class T>
class BST {
  private:
    Node<T> *root;
    int nodeCount; // keep track of no. of nodes in BST
    
    void findTen(Node<T> *p) const {

    }

    //inorder traversal
    void inorder(Node<T> *p) const {
        if (p != nullptr) { // General case
            // 1. recursively call inorder on p's left subtree; traverse left tree
            // 2. visit node: print the data of root/current node
            // 3. recursively call inorder on p's right subtree; traverse right tree
            inorder(p->lTree);
            cout << p->data << "-" << (p->count)-1 <<" ";
            inorder(p->rTree);
            //cout << "Does this work?" << endl;
        }
        // base case, do nothing; stop
    }
    
    //preorder traversal
    void preorder(Node<T> *p) const {
        if(p != nullptr){
            // Base case: if p equals nullptr, do nothing
            // General case: otherwise do the following:
            // 1. visit node
            // 2. traverse left tree
            // 3. traverse right tree
            cout << p->data << "-" << (p->count)-1 << " ";
            preorder(p->lTree);
            preorder(p->rTree);
        }
        // LEFT as an exercise
        //cout << "FIXME: Implemented preorder method..." << endl;
    }
    
    // postorder traversal
    void postorder(Node<T> *p) const {
        // FIXME - FIXED
        if( p != nullptr){
            postorder(p->lTree);
            postorder(p->rTree);
            cout << p->data << "-" << (p->count)-1 << " ";
        }
        // LEFT as an exercise
        //cout << "FIXME: Implemented postorder method..." << endl;
    }
    
    // counts nodes in the longest path instead of edges
    // return 1 more than the actual definition of height according
    // to the opendsa infile definition of height:
    // https://opendsa-server.cs.vt.edu/ODSA/Books/CS3/html/BinaryTree.html#definitions-and-properties 
    int height(Node<T> *p) const {
        if (p == nullptr)
            return 0;
        else
            return  1 + max(height(p->lTree), height(p->rTree));
    }
    
    int max(T x, T y) const {
        return (x >= y) ? x : y;
    }
    
    int leavesCount(Node<T> *p) const {
        // FIXME - FIXED - Left as an exercise
        if(p == nullptr){
            return 0;
        }
        if(p->lTree == nullptr && p->rTree == nullptr){
            return 1;
        }
        else{
            return leavesCount(p->lTree) + leavesCount(p->rTree);
        }
        // 1. Base case: if the tree is empty, return 0
        // 2. Base case: else if the left and right subtree are empty, return 1
        // 3. Otherwise, general case: return sum of leavesCount of left subtree and leavesCount of right subtree
        return 0;
    }
    
    // find and return the node with key value K, nullptr otherwise
    Node<T>* find(Node<T> *p, const T& K) const {
        if (p == nullptr) {
            return nullptr;
        }
        if (K == p->data) {
            return p;
        }
        else if (K < p->data)
            return find(p->lTree, K);
        else 
            return find(p->rTree, K);
    }

    Node<T>* findCount(Node<T> *p, const T& K) const {
        if (p == nullptr) {
            cout << "0" << endl;
            return nullptr;
        }
        if (K == p->data) {
            cout << p->count - 1 << endl;
            return p;
        }
        else if (K < p->data)
            return findCount(p->lTree, K);
        else
            return findCount(p->rTree, K);
    }
    
    // insert a given node into the tree
    void insert(Node<T>* &p, Node<T> *newNode) {
        /*
         Given a binary search tree pointed to by p and a newNode,
         the function inserts the newNode in the correct place in the tree.
         Since the tree could be changed, it is passed by reference.
         */
        // 1. If the tree is empty, insert at that location
        // increment nodeCount
        if (p == nullptr) {
            p = newNode;
            this->nodeCount++;
            (p->count) = 1;
        }
        if (newNode->data == p->data) {
            (p->count)++;
        }
        else {
            // 2. Otherwise, recurse down the tree and insert at the correct branch
            // can handle the duplicates differently depending on the application
            if (newNode->data < p->data)
                insert(p->lTree, newNode);
            // 2.c. Otherwise, recursively insert newNode into the right subtree
            else
                insert(p->rTree, newNode);
        }
    }
    
    Node<T>* findMin(Node<T>* p) {
        if (p->lTree == nullptr) return p;
        return findMin(p->lTree);
    }
    
    // remove a node from the tree
    // key: the key value of the record
    void remove(Node<T>* &p, const T& key) {
        if (p != nullptr) // general case
        {
            if (p->data == key) {//found node
                if (p->lTree != nullptr && p->rTree != nullptr){//case 4: two children
                    if (DEBUG)
                        cout << "Debug: Deleting node with two children..." << endl;
                    // find and copy the data of the min node on its right subtree to the node you're deleting
                    Node<T>* temp = findMin(p->rTree);
                    p->data = temp->data;
                    // remove the node with the duplicate value in the right subtree
                    remove(p->rTree, temp->data);
                }
                else if (p->rTree != nullptr){//case 2: has right child
                    if (DEBUG)
                        cout << "Debug: Deleting node with right child..." << endl;
                    Node<T>* temp = p;
                    // make the right child
                    p = p->rTree;
                    delete temp;
                }
                else if (p->lTree != nullptr){//case 2: has left child
                    if (DEBUG)
                        cout << "Debug: Deleting node with left child..." << endl;
                    Node<T>* temp = p;
                    p = p->lTree;
                    delete temp;
                }
                else{//case 1: no child/leaf node
                    if (DEBUG)
                        cout << "Debug: Deleting leaf node..." << endl;
                    delete p;
                    p = nullptr;
                }
            }
            else if (p->data > key) {//search left subtree
                if(DEBUG)
                    cout << "Debug: Searching left subtree..." << endl;
                remove(p->lTree, key);
            }
            else {//search into right subtree
                if (DEBUG)
                    cout << "Debug: Searching right subtree..." << endl;
                remove(p->rTree, key);
            }
        }
    }
    
    // Reinitialize tree
    void clear(Node<T>* &p) {
        if (p != nullptr) {
            clear(p->lTree); // first clear the left subtree
            clear(p->rTree); // then clearn the right subtree
            delete p; // delete the node itself
            p = nullptr;
        }
    }
    
    
  public:
    //Default constructor
    BST() {
        this->root = nullptr;
        this->nodeCount = 0;
    }
    
    // check if the bst is empty
    bool isEmpty() const {
        return this->root == nullptr;
    }
    
    //enumerate BST using inorder traversal
    void inorder() const {
        inorder(this->root);
    }
    
    // enumerate BST using preorder traversal
    void preorder() const {
        preorder(this->root);
    }
    
    // enumerate BST using postorder traversal
    void postorder() const {
        postorder(this->root);
    }
    
    //find a node with the given key and return the node if found
    Node<T>* find(const T& key) {
        return find(this->root, key);
    }

    Node<T>* findCount(const T& key) {
        return findCount(this->root, key);
    }
    
    // find an return height of BST
    int height() const {
        return height(this->root);
    }
    
    // find and return number of leaves in BST
    int leavesCount() const {
        return leavesCount(this->root);
    }
    
    // reset tree
    void clear() {
        clear(this->root);
    }
    
    // insert given item with key into the tree
    void insert(const T& key) {
        Node<T> *node = new Node<T>;
        node->data = key;
        node->lTree = nullptr;
        node->rTree = nullptr;
        insert(this->root, node);
    }
    
    // remove the node with the given key
    void remove(const T& key) {
        remove(this->root, key);
    }
    
    // get the value of the root node
    T getRoot(){
        return this->root->data;
    }
        
    //Destructor
    ~BST() {
        clear(this->root);
    }
};

int main(){
    BST<string> tree;
    vector<string> casper;
    ifstream infile;
    string file, text, word, found;
    int chosen, amount, number, n;

    do {
        cout << "Choose what you would like to do: " << endl;
        cout << "\t1. Input a text file (select 1)." << endl;
        cout << "\t2. Print BST inorder (select 2)." << endl;
        cout << "\t3. Print BST preorder (select 3)." << endl;
        cout << "\t4. Print BST postorder (select 4)." << endl;
        cout << "\t5. Display a word and the amount of times it has been used (select 5)." << endl;
        cout << "\t6. Delete a word from the tree (select 6)." << endl;
        cout << "\t7. Print out the top ten most used words and their frequencies (select 7)." << endl;
        cout << "\t8. Exit the program (select 8)." << endl;
        cin >> chosen;
        switch(chosen) {
            case 1:
                // reads in the file to a bst
                cout << "Input your sample text file" << endl;
                cin >> file;

                infile.open(file);

                while(infile){
                    infile >> text;
                    for (int i = 0, len = text.size(); i < len; i++)  { 
                        // check whether parsing character is punctuation or not 
                        if(ispunct(text[i])) 
                        { 
                            text.erase(i--, 1); 
                            len = text.size(); 
                        } 
                        else {
                            text[i] = tolower(text[i]);
                        }
                    } 
                    //casper.push_back(text);
                    if(tree.find(text) == nullptr) {
                        tree.insert(text);
                    }
                    else if(tree.find(text) == tree.find(text)) {
                        tree.insert(text);
                    }
                    else {
                        number++;
                    }
                    
                }
                infile.close();
                break;
            case 2:
                // prints inorder
                tree.inorder();
                cout << "\n";
                break;
            case 3:
                // prints preorder
                tree.preorder();
                cout << "\n";
                break;
            case 4:
                // prints postorder
                tree.postorder();
                cout << "\n";
                break;
            case 5:
                // finds a node given certain key
                cout << "Input the key you want to find (The word you want to find)." << endl;
                cin >> found;
                n = amount;
                if(tree.find(found) != nullptr) {
                    cout << "Your node was found:\n" << found << "\nThis key showed up this many time(s): " << endl;
                    tree.findCount(found);
                }
                else {
                    cout << "That node does not exist!" << endl;
                }
                break;
            case 6:
                cout << "Input the key you want to remove (The word you want to remove)." << endl;
                cin >> word;
                tree.remove(word);
                break;
            case 7:

                break;
            case 8:
                // Choose H to leave program
                cout << "Goodbye!" << endl;
                break;
        }
    }while(chosen != 8);
    return 0;
}