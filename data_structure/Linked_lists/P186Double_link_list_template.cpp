#include <iostream>
#include <cstdlib>
#define type string
using namespace std;
template <class T>class Chain;

template <class T>
class Node{
	friend class Chain<T>;
	private:
		T data;
		Node<T>* next;
		Node<T>* prev;
	public:
		Node(){
			next=0;
			prev=0;
		}
		Node(T dat){
			next=0;
			prev=0;
			data=dat;
		}
};

template<class T>
class Chain{
	public:
		Chain();
		void ADD();
		void Output();
		void Delete();
	private:
		Node<T>* first;
		Node<T>* current;
		Node<T>* tail;
};

template <class T>
Chain<T>::Chain(){
			this->tail=new Node<T>();
			this->first = new Node<T>();
			tail->prev=first;
			first->next=tail;
			this->current=0;
}
template <class T>
void Chain<T>::Output(){
	current = first->next;
	while(current!=tail){
		cout<<current->data<<endl;
		current=current->next;
	}
	cout<<"Undo\n";
	current=tail->prev;
	while(current!=first){
		cout<<current->data<<endl;
		current=current->prev;
	}
}

template <class T>
void Chain<T>::Delete(){
	this->current=this->first->next;
	cout<<"Delete:Enter the position(start from 0):";
	int pos,num=0;
	cin>>pos;
	while(num!=pos){
			current=current->next;
			if(this->current==tail){
				cout<<"Error! position excess.\n";
				return;
			}
			num++;
		}
	current->prev->next=current->next;
	current->next->prev=current->prev;
	delete current;
	
	
	
}

template <class T>
void Chain<T>::ADD(){
	current = first;
	cout<<"Add:Enter data,position(start from 0):";
	int pos,num=0;
	T dat;
	cin>>dat>>pos;                   //need to override operator iostream
	
	Node<T>* to_add = new Node<T>(dat);
	if(this->first->next==tail){
		first->next=to_add;
		to_add->prev=first;
		to_add->next=tail;
		tail->prev=to_add;
	}
	else{
		while(num!=pos){
			if(this->current==tail){
				cout<<"Error! position excess.\n";
				delete to_add;
				break;
			}
			current=current->next;
			num++;
		}
		if(num==pos&&this->current->next==tail){
			current->next=to_add;
			to_add->prev=current;
			to_add->next=tail;
			tail->prev=to_add;
		}
		else if(num==pos&&this->current->next!=tail){
			current->next->prev=to_add;
			to_add->next=current->next;
			current->next=to_add;
			to_add->prev=current;
		}
	}
}

int main(void){
	Chain<type> alpha;
	alpha.ADD();
	alpha.ADD();
	//alpha.ADD();
	//alpha.ADD();
	alpha.Delete();
	alpha.Output();
	
	
	
}


