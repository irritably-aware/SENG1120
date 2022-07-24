//Wei Chen c3355372
//15/05/2022
//Stack using a LinkedList w/current pointer
//implementation template

template <typename T>
LStack<T>::LStack(){
	list = new LinkedList<T>();
	height = 0;
}

template <typename T>
LStack<T>::~LStack(){
	while(height!=0){
		pop();
	}
}

template <typename T>
void LStack<T>::push(const T data){
	list->addHead(data);//used to be add tail
	height++;
}

template <typename T>
T LStack<T>::pop(){
	T p = list->removeHead();
	height--;
	return p;
}

template <typename T>
T& LStack<T>::peek() {
	list->start();
	return list->getCurrent();
}

template <typename T>
int LStack<T>::size(){
	return height;
}

template <typename T>
bool LStack<T>::isEmpty(){
	if(height==0){
		return true;
	}
	return false;
}