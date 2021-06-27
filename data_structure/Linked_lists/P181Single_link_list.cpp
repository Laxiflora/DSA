#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
	friend class Chain;
	public:
		Node(int dat,Node* nex){
			this->next=nex;
			this->data=dat;
		}
		Node(int dat){
			this->next=0;
			this->data=dat;
		}
		Node(){
			this->next=0;
			this->data=0;
		}
	private:
		int data;
		Node* next;
};

class Chain{
	public:
		Chain();
		void Add(int);
		void Delete();
		void Output();
		
	private:
		Node* first;
		Node* current;
};

Chain::Chain(){
			this->first = new Node();
			this->current=0;
		}
		
void Chain::Output(){
	this->current=this->first->next;
	while(this->current!=0){
		cout<<current->data<<endl;
		current=current->next;
	}
}

		
void Chain::Add(int num){
	cout<<"Enter new data:\n";
	int n;
	cin>>n;
	
	int count=0;
	current =first;
	Node* to_add = new Node(n);                 
	if(!this->first->next){
		this->first->next = to_add;
	}
	else
		while(this->first->next!=0){
			if(num==count){
				Node* temp=new Node();
				temp->next=current->next;
				current->next=to_add;
				to_add->next=temp->next;
				delete temp;
				break;
			}
			else{
				if(this->current==0){
					cout<<"Error!Position excess, data has been abandoned.\n";
					delete to_add;
					break;
			}
				count++;
				current=current->next;
			}
		}
}

int main(void){
	Chain alpha;
	alpha.Add(0);
	alpha.Add(1);
	alpha.Add(2);
	alpha.Output();
	return 0;
}





