#ifndef HUFFNODE_H
#define HUFFNODE_H

#include <iostream>

// next line needed because NULL is part of std namespace
using namespace std;

class huffNode {
public:
    huffNode();                 // Constructor
    huffNode(string a);
    string hold;
    huffNode *left, *right;	// for doubly linked lists
};
#endif
