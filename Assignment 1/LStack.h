//Wei Chen c3355372
//15/05/2022
//Stack using a LinkedList w/current pointer
//templated header

#ifndef AMBIVALENT_LSTACK
#define AMBIVALENT_LSTACK

#include "LinkedList.h"

template <typename T>
class LStack{

	public:
		//de/constructors
		LStack();
		~LStack();

		//mutators
		void push(const T data);

		T pop();
		//accessors
		T& peek();
		int size();
		bool isEmpty();

	private:
		//LinkedList data variable
		LinkedList<T>* list;
		//stack-specific data
		int height;
};

#include "LStack.hpp"

#endif