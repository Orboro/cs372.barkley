#pragma once

#include "cs372Container.h"
#include "cs372List.h"

template<typename T>
class Stack : public Container {
private:
	List<T>* stackList = new List<T>();
	int stackSize = 0;
public:
	Stack();
	Stack(Stack& rhs);
	~Stack();
	bool empty() override;
	void push(T Data);
	T pop();
	void traverse(void (*doIt)(T Data));
	size_t size() override;
	size_t max_size() override;
	void swap(Container&, Container&) override;
	void clear() override;
};

template<typename T>
Stack<T>::Stack()
{}

template<typename T>
Stack<T>::Stack(Stack& rhs){
}

template<typename T>
Stack<T>::~Stack(){
	delete stackList; 
}

template<typename T>
bool Stack<T>::empty(){
	return stackList->empty(); 
}

template<typename T>
void Stack<T>::push(T data) {
	stackList->push_back(data);
	++stackSize;
}

template<typename T>
T Stack<T>::pop() {
	--stackSize;
	T back = stackList->back();
	stackList->pop_back();
	return back;
}

template<typename T>
void Stack<T>::traverse(void (*doIt)(T Data)) {
	stackList->traverse(doIt);
}

template<typename T>
size_t Stack<T>::size(){
	return stackSize;
}

template<typename T>
size_t Stack<T>::max_size() {
	return INT_MAX;
}

template<typename T>
void Stack<T>::swap(Container& a, Container& b){
	Stack tempStack;

	Stack& aStack = dynamic_cast<Stack&>(a);
	Stack& bStack = dynamic_cast<Stack&>(b);
	while (!aStack.empty()) {
		tempStack.push(aStack.pop());
	}

	int bCount = bStack.size();
	while (!bStack.empty()) {
		tempStack.push(bStack.pop());
	}

	for (int i = 0; i < bCount; ++i)
	{
		aStack.push(tempStack.pop());
	}

	while (!tempStack.empty())
	{
		bStack.push(tempStack.pop());
	}
}

template<typename T>
void Stack<T>::clear(){
	while (!empty())
	{
		pop();
	}
}
