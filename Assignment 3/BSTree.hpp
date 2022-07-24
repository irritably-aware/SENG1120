/*  Wei Chen C3355372
    Assignment 3
    11/06/2022
    BSTree.h: header implementation for Binary Search Tree class
*/

template<typename T>    //pre: none
BSTree<T>::BSTree(){    //post: root pointer set to null, size variable initialised to 0
    root = NULL;
    size = 0;
}
                        //pre: none
template<typename T>    //post: deletes root node, causing chain out-of-referencing
BSTree<T>::~BSTree(){
    delete root;
}
                        //pre: tree is initialised
template<typename T>    //post: data is placed under the tree in a BTNode
void BSTree<T>::add(T newData){
    if(size==0){        //special case for adding to empty tree
        root = new BTNode<T>(newData);
        size=1; return;
    }                   //otherwise use recursive insert function
    else{ insert(root, newData); return;}
}
                        //pre: tree is initialised, add() is called when tree not empty
template<typename T>    //post: data is inserted in BST manner
void BSTree<T>::insert(BTNode<T>* node, T newData){
    if(newData==node->getData()){       //if new data already exist in tree, replace old data
        node->setData(newData); return;
    }
    else if(newData>node->getData()){   //if new data is larger than current node data
        if(node->getRight()==NULL){     //place to insert found
            BTNode<T>* newBTN = new BTNode<T>(newData);
            newBTN->setParent(node);
            node->setRight(newBTN);     //forgetting this single line costed me 2 days in 3 versions of remove+helper re-writing...
            size++; return;             //executes the insertion and returns
        }
        else insert(node->getRight(), newData); //recurse further right
    }
    else if(newData<node->getData()){   //if new data is smaller than current node data
        if(node->getLeft()==NULL){      //much the same as above block
            BTNode<T>* newBTN = new BTNode<T>(newData);
            newBTN->setParent(node);
            node->setLeft(newBTN);
            size++; return;
        }
        else insert(node->getLeft(), newData);
    }
}
                        //pre: tree is initialised
template<typename T>    //post: input data is searched for and removed from tree if found
void BSTree<T>::remove(const T& data){
    if(size == 0) return;                    //special case: empty tree. never called :)
    if(data == root->getData() && size==1){  //special case: tree size 1. never called, may be unnecesary
        delete root; root=NULL; size=0; return;
    }
    else eject(root, data);                 //recursively find and delete found data
    
}
                        //pre: tree is initialised
template<typename T>    //post: input data is recursively searched for and removed when found
void BSTree<T>::eject(BTNode<T>* node, const T& data){
    if(node==NULL)return;   //i didn't have this line; what was i thinking?
    if(node->getData()<data){  eject(node->getRight(),data); return;}       //if current node's data is smaller than data to be removed, try right side
    else if(node->getData()>data){  eject(node->getLeft(),data); return;}   //the above comment but opposite
    if(node->getParent()==NULL) return; //won't get called i think

    else if(node->getData()==data){                                         //if we found data match
        if(node->getLeft()==NULL&&node->getRight()==NULL){                              //if node has no children
            if(node->getParent()->getLeft()!=NULL&&node->getParent()->getLeft()==node){ //if node is a left child
                node->getParent()->setLeft(NULL); delete node; node=NULL; size--;           //it's parent's un-point to it, and then delete it.
            }
            else if(node->getParent()!=NULL){node->getParent()->setRight(NULL); delete node; node=NULL; size--;}    //else node is a right child
            return;
        }
        else if(node->getLeft()==NULL||node->getRight()==NULL){                         //if node has a single child
            if(node->getParent()->getLeft()!=NULL&&node->getParent()->getLeft()==node){ //if node is a left child
                if(node->getLeft()!=NULL){                                              //if node has left child
                    node->getParent()->setLeft(node->getLeft());
                    node->getLeft()->setParent(node->getParent());
                    delete node; node=NULL;
                    size--;
                }
                else{                                                                   //else has right child
                    node->getParent()->setLeft(node->getRight()); 
                    node->getRight()->setParent(node->getParent());
                    delete node; node=NULL;
                    size--;
                }
                return;
            }
            else{                                                                       //node is a right child
                if(node->getLeft()!=NULL){                                              //much the same as above block
                    node->getParent()->setRight(node->getLeft()); 
                    node->getLeft()->setParent(node->getParent());
                    delete node; node=NULL;
                    size--;
                }
                else{
                    node->getParent()->setRight(node->getRight());
                    node->getRight()->setParent(node->getParent()); 
                    delete node; node=NULL;
                    size--;
                }
                return;
            }
            return;
        }
        else if(node->getLeft()!=NULL&&node->getRight()!=NULL){                         //node has two children
            BTNode<T>*  tempn = findMin(node->getRight());
            T* temppointer = new T(tempn->getData().get_name(), tempn->getData().get_population());
            /*T shifted = findMin(node->getRight())->getData();                           //find smallest node from node's right child as replacement
            eject(findMin(node->getRight()),findMin(node->getRight())->getData());      //remove the original node
            node->setData(shifted);*/
            eject(tempn, tempn->getData());
            node->setData(*temppointer);
            return;
        }

    }
}
                        //pre: tree is initialised
template<typename T>    //post: given a node, this function returns pointer of the smallest child relative.
BTNode<T>* BSTree<T>::findMin(BTNode<T>* node){
    if(node->getLeft()==NULL){return node;}
    return findMin(node->getLeft());
}
                        //pre: tree is initialised
template<typename T>    //post: returns total population calculation from data
int BSTree<T>::calculateTotalPop(){
    int num = 0;
    gather(root, num, 2147483647);
    return num;
}
                        //pre: tree is initialised
template<typename T>    //post: returns the population of cities w/ population surpass the input limit
int BSTree<T>::calculatePopGreaterThan(int limit){
    int num = 0;
    gather(root, num, limit);
    return num;
}
                        //pre: tree is initialised
template<typename T>    //post: recursively adds to the calculation to num
void BSTree<T>::gather(BTNode<T>* node, int& num, int lim){
    if(node!=NULL){
        gather(node->getLeft(), num, lim);
        int n = node->getData().get_population();
        if(n>lim){num=num+n;}
        gather(node->getRight(),num, lim);
    }
    return;
}
                        //pre: tree is initialised
template<typename T>    //post: place tree data in the input ostream&
void BSTree<T>::print(std::ostream& out){
    compile(root, out);
    return;
}
                        //pre: tree is initialised
template<typename T>    //post: streams data recursively and in order to the input ostream&
void BSTree<T>::compile(BTNode<T>* node, std::ostream& out){
    
    if(node!=NULL){
        compile(node->getLeft(), out);
        out<<node <<"   ";
        compile(node->getRight(),out);
    }
    return;
}
                        //pre: tree is initialised
template <typename T>   //post: tree data is returned in input ostream&
std::ostream& operator << (std::ostream& out, BSTree<T>& tree){
    tree.print(out);
    return out;
}
