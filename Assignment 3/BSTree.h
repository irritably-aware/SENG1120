/*  Wei Chen C3355372
    Assignment 3
    11/06/2022
    BSTree.h: header definition for Binary Search Tree class
*/

#ifndef RUSHED_BSTREE
#define RUSHED_BSTREE

#include "BTNode.h" //using BTNode as underlaying data structure

//generic class
template <typename T>
class BSTree{
    public:
        //de/constructors
        BSTree();   //constructor
        ~BSTree();  //destructor

        //mutator
        void add(T newData);        //adds input data into list
        void remove(const T& data); //search for input data in the list and removes when found

        //query functions
        int  calculateTotalPop();                  //returns calculation based on data
        int  calculatePopGreaterThan(int limit);   //returns different calculation based on data
        void print(std::ostream& out);             // << overload helper

        
    private:
        BTNode<T>* root;                            //root node pointer
        size_t size;                                //tree size variable
        void insert(BTNode<T>* node, T newData);    //recursive add helper
        void eject(BTNode<T>* node, const T& data); //recursive remove helper
        BTNode<T>* findMin(BTNode<T>* node);        //recursive minimal value child node finder
        void compile(BTNode<T>* node, std::ostream& out);   //recursive print helper (inorder)
        void gather(BTNode<T>* node, int& num, int lim);    //recursive population calc helper
};

//generic overloaded << operator
template <typename T>
std::ostream& operator << (std::ostream& out, BSTree<T>& tree);

#include "BSTree.hpp"

#endif