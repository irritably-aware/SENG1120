//Wei Chen c3355372
//15/05/2022
//Node container for data
//implementation template

template <typename T>
Node<T>::Node(){

	next = NULL;
	prev = NULL;
}

template <typename T>
Node<T>::Node(const T a){
	item = a;
	next = NULL;
	prev = NULL;
}

template <typename T>				//data is on stack, pointers will be out of bound
Node<T>::~Node(){}					//so empty destructor for Node should be fine

template <typename T>
void Node<T>::setData(const T& a){	//takes a item reference and stores it in Node
	item = a;
}

template <typename T>
void Node<T>::setNext(Node* n){
	next = n;
}

template <typename T>
void Node<T>::setPrev(Node* p){
	prev = p;
}

template <typename T>
Node<T>* Node<T>::getNext() const{
	return next;
}

template <typename T>
Node<T>* Node<T>::getPrev() const{
	return prev;
}

template <typename T>
T& Node<T>::getData(){				//returns a reference to data item
	return item;
}