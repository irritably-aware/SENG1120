/*  Wei Chen C3355372
    Assignment 3
    11/06/2022
    BTNode.hpp: implementation definition for Binary Tree Node class
*/
                        //pre: none
template <typename T>   //post: data variable not initialised, all pointers set to NULL
BTNode<T>::BTNode(){
    parent = NULL;
    left = NULL;
    right = NULL;
}
                        //pre:none
template <typename T>   //post: data variable set to data reference passed in, all pointers set NULL
BTNode<T>::BTNode(const T& newData){
    data = newData;
    parent = NULL;
    left = NULL;
    right = NULL;
}
                        //pre: none
template <typename T>   //post: data is on stack, and pointers lost won't leak
BTNode<T>::~BTNode(){

}
                        //pre: 'this' node is initialised
template <typename T>   //post: this node set its data variable as the data passed in
void BTNode<T>::setData(const T& newData){
    data = newData;
}
                        //pre: 'this' node is initialised
template <typename T>   //post: parent pointers set to the input pointer
void BTNode<T>::setParent(BTNode<T>* newP){
    parent = newP;
}
                        //pre: 'this' node is initialised
template <typename T>   //post: left pointer set to the input pointer
void BTNode<T>::setLeft(BTNode<T>* newL){
    left = newL;
}
                        //pre: 'this' node is initialised
template <typename T>   //post: right pointer set to the input pointer
void BTNode<T>::setRight(BTNode<T>* newR){
    right = newR;
}

                        //pre: 'this' node is initialised
template <typename T>   //post: reference to data is returned
T& BTNode<T>::getData(){
    return data;
}
                        //pre: 'this' node is initialised
template <typename T>   //post: parent pointer returned
BTNode<T>* BTNode<T>::getParent(){
    return parent;
}
                        //pre: 'this' node is initialised
template <typename T>   //post: left pointer returned
BTNode<T>* BTNode<T>::getLeft(){
    return left;
}
                        //pre: 'this' node is initialised
template <typename T>   //post: right pointer returned
BTNode<T>* BTNode<T>::getRight(){
    return right;
}
                        //pre: 'this' node is initialised, input ostream reference is initialised
template <typename T>   //streams data object into output
void BTNode<T>::print(std::ostream& out){
    out<<data;
}
                        //pre: 'this' node is initialised
template <typename T>   //data object in the node is streamed into ostream and returned
std::ostream& operator << (std::ostream& out, BTNode<T>* node){
    node->print(out);
    return out;
}