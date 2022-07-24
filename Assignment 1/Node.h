//Wei Chen c3355372
//15/05/2022
//Node container for data
//templated header

#ifndef AMBIVALENT_NODE
#define AMBIVALENT_NODE

#include <iostream>

template <typename T>
class Node{

	public:
		//de/constructors
		Node();
		Node(const T a);
		~Node();

		//accessors
		void setNext(Node<T>* n);
		void setPrev(Node<T>* p);
		void setData(const T& a);
		//mutators
		Node<T>* getNext() const;
		Node<T>* getPrev() const;
		T& getData();

	private:
		//data variable/item held
		T item;
		//pointer variable
		Node<T>* next;
		Node<T>* prev;
};

#include "Node.hpp"

#endif