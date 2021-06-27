#include <iostream>
#include <cstdlib>
using namespace std;
template <class T> 
class Stack {
	public:
		Stack(int def_capacity=100){
			array = new T[def_capacity];
			capacity = def_capacity;
			top=-1; 
		}
		
		bool IsEmpty(){return top==-1;}
		
		void Excess(){
			T* temp = new T[capacity*2];
			copy(array,array+capacity,temp);
			delete[] array;
			array = temp;
		}
		
		~Stack(){delete[] array;}
		T Pop(){
			if(IsEmpty()) throw "Stack Overflow(?).";
			else{
				return array[top--];
			}
		}
		
		void Push(T alp){
			if(top-1==capacity) Excess();
			array[++top]=alp;
		}
		T Top(){
			if(IsEmpty()) throw "Stack is empty.";
			else return array[top];	
		}
		
	private:
		int top,capacity;
		T* array;
};
