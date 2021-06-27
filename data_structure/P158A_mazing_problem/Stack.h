#include <iostream>
#include <cstdlib>
using namespace std;
template <class T> 
class Stack {
	public:
		Stack(int def_capacity=10){
			array = new T[def_capacity];
			capacity = def_capacity;
			top=-1; 
		}
		
		bool IsEmpty(){
			if(top==-1) return true;
			else return false;
		}
		
		void Excess(){
			T* temp = new T[capacity*2];
			copy(this->array,this->array+capacity,temp);
			delete[] array;
			this->array = temp;
			capacity*=2;
		}
		
		//~Stack(){delete[] array;}
		T Pop(){
			if(IsEmpty()) cout<<"Error from stack";
			else{
				return array[top--];
			}
		}
		
		void Push(T alp){
			if(top+2==capacity) Excess();
			array[++top]=alp;
		}
		T Top(){
			if(IsEmpty()) throw "Stack is empty.";
			else return array[top];	
		}
		
		void debug(){
			cout<<"stack="<<top+1;
		}
		
		
		
	private:
		int top,capacity;
		T* array;
};
