//Wei Chen c3355372
//15/05/2022
//doubly LinkedList with current pointer, using Node
//implementation template

template <typename T>
LinkedList<T>::LinkedList(){
	head=NULL;
	tail=NULL;
	curr=NULL;
	length=0;
}

template <typename T>
LinkedList<T>::~LinkedList(){
	while(length!=0){
		removeTail();
	}
}

template <typename T>
void LinkedList<T>::addHead(const T data){
	Node<T>* newn = new Node<T>(data);
	if(length==0){
		head=newn;
		tail=head;
		curr=head;
	}
	else{
		newn->setNext(head);
		head->setPrev(newn);
		head=newn;	
	}
	length++;
}

template <typename T>
void LinkedList<T>::addTail(const T data){
	Node<T>* newn = new Node<T>(data);
	if(length==0){
		tail=newn;
		head=tail;
		curr=head;
	}
	else{
		newn->setPrev(tail);
		tail->setNext(newn);
		tail=newn;
	}
	length++;
}

template <typename T>
void LinkedList<T>::addCurrent(const T data){
	Node<T>* newn = new Node<T>(data);	
	if(length==1||curr==head){
		addHead(data);
	}
	else{
		//newnode prevpointer pointing to node before current
		newn->setPrev(curr->getPrev());
		//node before current setnext newnode
		curr->getPrev()->setNext(newn);
		//newnode nextpointer pointing to current
		newn->setNext(curr);
		//current prevpointer point to newnode;
		curr->setPrev(newn);
		//switch
		curr=newn;
	}
}

template <typename T>
T LinkedList<T>::removeHead(){
	T temp = head->getData();
	if (length==1){
		delete head;
		head=NULL;
		tail=NULL;
		curr=NULL;
		length--;
	}
	else{
		Node<T>* tempptr = head;
		head->getNext()->setPrev(NULL);
		head = tempptr->getNext();
		delete tempptr;
		length--;
		tempptr=NULL;
	}
	return temp;
}

template <typename T>
T LinkedList<T>::removeTail(){
	
	T temp = tail->getData();

	if(length==1){
		delete tail;
		head=NULL;
		tail=NULL;
		curr=NULL;
		length--;
	}
	else{
		Node<T>* tempptr = tail;
		tail->getPrev()->setNext(NULL);
		tail = tempptr->getPrev();
		delete tempptr;
		length--;
		tempptr=NULL;
	}
	return temp;
}

template <typename T>
T LinkedList<T>::removeCurrent(){
	
	if(length==1){
		T temp = curr->getData();
		delete curr;
		head=NULL;
		tail=NULL;
		curr=NULL;
		length--;
		return temp;
	}
	else{
		if(curr==head){
			return removeHead();
		}
		else if(curr==tail){
			return removeTail();
		}
		else{
			Node<T>* tempptr = curr;
			T temp = curr->getData();
			curr->getPrev()->setNext(curr->getNext());
			curr->getNext()->setPrev(curr->getPrev());
			curr= tempptr->getNext();
			delete tempptr;
			length--;
			tempptr=NULL;
			return temp;
		}
	}
}

template <typename T>
void LinkedList<T>::start(){
	curr = head;
}

template <typename T>
void LinkedList<T>::end(){
	curr = tail;
}

template <typename T>
void LinkedList<T>::forward(){
	curr = curr->getNext();
}

template <typename T>
void LinkedList<T>::back(){
	curr = curr->getPrev();
}

template <typename T>
T& LinkedList<T>::getCurrent() {
	return curr->getData();
}

template <typename T>
int LinkedList<T>::size(){
	return length;
}