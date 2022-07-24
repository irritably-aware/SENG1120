/*  Wei Chen C3355372
    Assignment 3
    11/06/2022
    BTNode.h: header definition for Binary Tree Node class
*/

#ifndef RUSHED_BTNODE
#define RUSHED_BTNODE

#include <cstddef> //for using NULL
#include <ostream> //for using ostream

//generic class
template <typename T>
class BTNode{
    public:
        //de/constructors
        BTNode();                   //constructor
        BTNode(const T& newData);   //constuctor given data
        ~BTNode();                  //(empty)destructor

        //mutators
        void setData(const T& newData);  //sets input data as node data
        void setParent(BTNode<T>* newP);//sets input pointer as parent pointer
        void setLeft(BTNode<T>* newL);  //sets input pointer as left pointer
        void setRight(BTNode<T>* newR); //sets input pointer as right pointer

        //query functions
        T& getData();                   //returns reference of the data
        BTNode<T>* getParent();         //returns pointer to parent
        BTNode<T>* getLeft();           //returns pointer to left child
        BTNode<T>* getRight();          //returns pointer to right child
        void print(std::ostream& out);  //helper for printing node, strictly unnecessary
    
    private:
        T data;             //the data variable, on stack
        BTNode<T>* parent;  //parent pointer
        BTNode<T>* left;    //left child pointer
        BTNode<T>* right;   //right child pointer
};

//generic overloaded << operator
template <typename T>
std::ostream& operator << (std::ostream& out, BTNode<T>* node);

#include "BTNode.hpp"

#endif