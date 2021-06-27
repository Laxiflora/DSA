#include <iostream>
#include <cstdlib>
using namespace std;
class Node{
	friend class Chain;
	private:
		int data;
		Node* next;
		Node* prev;
	public:
		Node(){
			next=0;
			prev=0;
			data=0;
		}
		Node(int dat){
			next=0;
			prev=0;
			data=dat;
		}
};

class Chain{
	public:
		Chain();
		void ADD();
		void Output();
	private:
		Node* first;
		Node* current;
		Node* tail;
};

Chain::Chain(){
			this->tail=new Node();
			tail->prev=first;
			this->first = new Node();
			first->next=tail;
			this->current=0;
}

void Chain::Output(){
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

void Chain::ADD(){
	current = first;
	cout<<"Enter data,position:";
	int dat,pos,num=0;
	cin>>dat>>pos;
	
	Node* to_add = new Node(dat);
	if(this->first->next==tail){
		first->next=to_add;
		to_add->prev=first;
		to_add->next=tail;
		tail->prev=to_add;
	}
	else{
		while(num!=pos){
			if(!this->current){
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
	Chain alpha;
	alpha.ADD();
	alpha.ADD();
	alpha.ADD();
	alpha.Output();
	
	
	
}


