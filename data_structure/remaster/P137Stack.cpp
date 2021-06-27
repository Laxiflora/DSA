#include <iostream>
#include <cstdlib>
#include "P137Stack.h"
using namespace std;
	template <class T>
		Stack<T>::Stack(int stackCapacity){
			capacity = stackCapacity;
			top=0;
			itemList = new T[stackCapacity];
		}
		template <class T>
		bool Stack<T>::IsEmpty() const{
			return top==0;
		}
		template <class T>
		T Stack<T>::Top() const{
			if(top==0){ throw "Stack is Empty\n";
			} 
			else return itemList[top-1];
		}
		template <class T>
		void Stack<T>::Push(const T item) {
			if(top<capacity)itemList[top++]=item;
			else cout<<"Stack Over Flow\n";
		}
		template <class T>
		void Stack<T>::Pop(){
			top--;
		}
	//private:
	//	T* itemList;
	//	int capacity;
	//	int top;

int main(void){
	Stack<int> intStack;
	intStack.Push(32);
	cout<<intStack.Top()<<endl;
	intStack.Pop();
	cout<<intStack.IsEmpty()<<" ";//<<intStack.Top();
}
