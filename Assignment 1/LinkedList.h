//Wei Chen c3355372
//15/05/2022
//doubly LinkedList with current pointer, using Node
//templated header

#ifndef AMBIVALENT_LIST
#define AMBIVALENT_LIST

#include "Node.h"

template <typename T>
class LinkedList{

	public:
		//de/constructors
		LinkedList();
		~LinkedList();

		//mutators
		void addHead(const T data);
		void addTail(const T data);
		void addCurrent(const T data);
		T removeHead();
		T removeTail();
		T removeCurrent();
		
		//still mutators, but moves current pointer
		void start();
		void end();
		void forward();
		void back();

		//accessors
		T& getCurrent() ;
		int size();

	private:
		//linkedlist specific pointers
		Node<T>* head;
		Node<T>* tail;
		Node<T>* curr;
		//linkedlist specific data
		int length;
};

#include "LinkedList.hpp"

#endif